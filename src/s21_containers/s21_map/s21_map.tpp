#ifndef S21_CONTAINERS_S21_MAP_S21_MAP_TPP_
#define S21_CONTAINERS_S21_MAP_S21_MAP_TPP_

#include "../s21_vector/s21_vector.h"  // for BONUS PART

namespace s21 {

/*==============================================
=               Helpful methods                =
==============================================*/
template <typename Key, typename T>
void map<Key, T>::ChangeValue(BaseNode* some_node, const T& obj) {
  Node* exist_node = static_cast<Node*>(some_node);
  exist_node->value = obj;
}

/*==============================================
=             Map Member functions             =
==============================================*/
template <typename Key, typename T>
map<Key, T>::map() : RBTree<Key, T>() {}

template <typename Key, typename T>
map<Key, T>::map(std::initializer_list<value_type> const& items) : map() {
  auto it = items.begin();
  for (size_t i = 0; i < items.size(); ++i, ++it) {
    if (!this->contains((*it).first)) {
      Node* new_node = new Node{it->first, it->second, true};
      RBTree<Key, T>::TreeInsert(new_node);
    }
  }
}

template <typename Key, typename T>
map<Key, T>::map(const map& m) : RBTree<Key, T>(m) {}

template <typename Key, typename T>
map<Key, T>::map(map&& m) : RBTree<Key, T>(std::move(m)) {}

template <typename Key, typename T>
map<Key, T>& map<Key, T>::operator=(map&& m) {
  if (this->end() != m.end()) {
    RBTree<Key, T>::operator=(std::move(m));
  }

  return *this;
}

/*==============================================
=              Map Element Access              =
==============================================*/
template <typename Key, typename T>
T& map<Key, T>::at(const Key& key) {
  if (this->empty() || !this->contains(key)) {
    throw std::out_of_range("Error: std::out of range\n");
  }

  Node* exist_node =
      static_cast<Node*>(this->GetExistNode(this->root_.left, key));
  return exist_node->value;
}

template <typename Key, typename T>
T& map<Key, T>::operator[](const Key& key) {
  if (this->empty() || !this->contains(key)) {
    T some_value;  // ???
    Node* new_node = new Node{key, some_value, true};
    this->TreeInsert(new_node);
  }

  Node* result_node =
      static_cast<Node*>(this->GetExistNode(this->root_.left, key));
  return result_node->value;
}

/*==============================================
=                 Map Modifiers                =
==============================================*/
template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const value_type& value) {
  Node* new_node = new Node{value.first, value.second, true};
  std::pair<iterator, bool> result = this->TreeInsert(new_node);

  if (!result.second) {
    delete new_node;
  }
  return result;
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const Key& key, const T& obj) {
  Node* new_node = new Node{key, obj, true};
  std::pair<iterator, bool> result = this->TreeInsert(new_node);

  if (!result.second) {
    delete new_node;
  }
  return result;
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert_or_assign(
    const Key& key, const T& obj) {
  std::pair<iterator, bool> result{nullptr, false};

  if (!this->empty() && this->contains(key)) {
    BaseNode* tmp = this->GetExistNode(this->root_.left, key);
    ChangeValue(tmp, obj);
    result = {{tmp}, false};
  } else {
    result = insert(key, obj);
  }

  return result;
}

/*==============================================
=                  BONUS PART                  =
==============================================*/
template <typename Key, typename T>
template <typename... Args>
s21::vector<std::pair<typename map<Key, T>::iterator, bool>>
map<Key, T>::insert_many(Args&&... args) {
  s21::vector<std::pair<typename map<Key, T>::iterator, bool>> result;

  map<Key, T> tmp{args...};

  for (auto elem_iter = tmp.begin(); elem_iter != tmp.end(); ++elem_iter) {
    Node* other_node = static_cast<Node*>(elem_iter.get_node_ptr());
    auto result_elem = insert(other_node->key, other_node->value);
    result.push_back(result_elem);
  }

  result.shrink_to_fit();

  return result;
}

}  // namespace s21

#endif  // S21_CONTAINERS_S21_MAP_S21_MAP_TPP_