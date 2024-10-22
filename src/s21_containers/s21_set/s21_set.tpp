#ifndef S21_CONTAINERS_S21_SET_S21_SET_TPP_
#define S21_CONTAINERS_S21_SET_S21_SET_TPP_

#include "../s21_vector/s21_vector.h"  // for BONUS PART

namespace s21 {

/*==============================================
=             Set Member functions             =
==============================================*/
template <typename Key>
set<Key>::set() : RBTree<Key, Key>() {}

template <typename Key>
set<Key>::set(std::initializer_list<value_type> const& items) : set() {
  auto it = items.begin();
  for (size_t i = 0; i < items.size(); ++i, ++it) {
    if (!this->contains(*it)) {
      Node* new_node = new Node{*it, true};
      RBTree<Key, Key>::TreeInsert(new_node);
    }
  }
}

template <typename Key>
set<Key>::set(const set& m) : RBTree<Key, Key>(m) {}

template <typename Key>
set<Key>::set(set&& m) : RBTree<Key, Key>(std::move(m)) {}

template <typename Key>
set<Key>& set<Key>::operator=(set&& m) {
  if (this->end() != m.end()) {
    RBTree<Key, Key>::operator=(std::move(m));
  }

  return *this;
}

/*==============================================
=                 Set Modifiers                =
==============================================*/
template <typename Key>
std::pair<typename set<Key>::iterator, bool> set<Key>::insert(
    const value_type& value) {
  Node* new_node = new Node{value, true};
  std::pair<typename set<Key>::iterator, bool> result =
      this->TreeInsert(new_node);

  if (!result.second) {
    delete new_node;
  }

  return result;
}

/*==============================================
=                  Set Lookup                  =
==============================================*/
template <typename Key>
typename set<Key>::iterator set<Key>::find(const Key& key) {
  BaseNode* result = nullptr;

  if (!this->empty() && this->contains(key)) {
    result = this->GetExistNode(this->root_.left, key);
  } else {
    result = this->end().get_node_ptr();
  }

  return {result};
}

/*==============================================
=                  BONUS PART                  =
==============================================*/
template <typename Key>
template <class... Args>
s21::vector<std::pair<typename set<Key>::iterator, bool>> set<Key>::insert_many(
    Args&&... args) {
  s21::vector<std::pair<typename set<Key>::iterator, bool>> result;

  set<Key> tmp{args...};

  for (auto elem_iter = tmp.begin(); elem_iter != tmp.end(); ++elem_iter) {
    Node* other_node = static_cast<Node*>(elem_iter.get_node_ptr());
    auto result_elem = insert(other_node->key);
    result.push_back(result_elem);
  }

  result.shrink_to_fit();

  return result;
}

}  // namespace s21

#endif  // S21_CONTAINERS_S21_SET_S21_SET_TPP_