#ifndef S21_CONTAINERS_S21_MULTISET_S21_MULTISET_TPP_
#define S21_CONTAINERS_S21_MULTISET_S21_MULTISET_TPP_

#include "../s21_list/list.h"
#include "../s21_vector/s21_vector.h"

namespace s21 {

/*==============================================
=               Helpful methods                =
==============================================*/
template <typename Key>
typename multiset<Key>::iterator multiset<Key>::AddValueToNode(
    const value_type& item, bool plus_size) {
  Node* exist_node_list =
      static_cast<Node*>(this->GetExistNode(this->root_.left, item));
  exist_node_list->value.push_back(item);

  if (plus_size) ++this->size_;

  iterator result{exist_node_list};
  // изменияем поле итератора листа на последний вставленный элемент
  result.value_iter_ = --(exist_node_list->value.end());

  return result;
}

template <typename Key>
void multiset<Key>::FreeMemory(BaseNode*& baby_node) {
  if (baby_node) {
    if (baby_node->left) FreeMemory(baby_node->left);

    if (baby_node->right) FreeMemory(baby_node->right);

    Node* current_node = static_cast<Node*>(baby_node);
    current_node->value.~list<Key>();
    delete baby_node;
    baby_node = nullptr;
  }
}

/*==============================================
=            Multiset constructors             =
==============================================*/
template <typename Key>
multiset<Key>::multiset() : RBTree<Key, s21::list<Key>>() {}

template <typename Key>
multiset<Key>::multiset(std::initializer_list<value_type> const& items)
    : multiset() {
  auto it = items.begin();
  for (size_t i = 0; i < items.size(); ++i, ++it) {
    if (!(this->empty()) && this->contains(*it)) {
      AddValueToNode(*it);
    } else {
      Node* new_node = new Node{*it, s21::list<Key>(), true};
      this->TreeInsert(new_node);
      AddValueToNode(*it, false);
    }
  }
}

template <typename Key>
multiset<Key>::multiset(const multiset& ms) : RBTree<Key, s21::list<Key>>(ms) {}

template <typename Key>
multiset<Key>::multiset(multiset&& ms)
    : RBTree<Key, s21::list<Key>>(std::move(ms)) {}

template <typename Key>
multiset<Key>::~multiset() {
  FreeMemory(this->root_.left);
}

template <typename Key>
multiset<Key>& multiset<Key>::operator=(multiset&& ms) {
  if (this != &ms) {
    RBTree<Key, s21::list<Key>>::operator=(std::move(ms));
  }
  return *this;
}

/*==============================================
=              Multiset Iterators              =
==============================================*/
template <typename Key>
typename multiset<Key>::iterator multiset<Key>::begin() {
  return {RBTree<Key, s21::list<Key>>::begin()};
}

/*==============================================
=               Multiset Modifiers             =
==============================================*/
template <typename Key>
void multiset<Key>::clear() {
  FreeMemory(this->root_.left);
  this->size_ = 0;
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::insert(
    const value_type& value) {
  iterator result;

  if (this->empty() || !(this->contains(value))) {
    Node* new_node = new Node{value, s21::list<Key>(), true};
    this->TreeInsert(new_node);
    result = AddValueToNode(value, false);
  } else {
    result = AddValueToNode(value);
  }

  return result;
}

template <typename Key>
void multiset<Key>::erase(iterator pos) {
  // проверяем fake_root
  if (pos.get_node_ptr() != (this->end()).get_node_ptr()) {
    Node* eraseable_node = static_cast<Node*>(pos.get_node_ptr());
    eraseable_node->value.erase(pos.value_iter_);

    if (eraseable_node->value.size() == 0) {
      eraseable_node->value.~list<Key>();  // жОские костыли
      RBTree<Key, s21::list<Key>>::erase(pos);
    } else {
      --this->size_;
    }
  }
}

template <typename Key>
void multiset<Key>::merge(multiset& other) {
  if (other.empty()) return;

  if (this->empty()) {
    this->swap(other);
  } else {
    for (auto iter = other.begin(); iter != other.end(); ++iter) {
      this->insert(*iter);
    }
    other.clear();
  }
}

/*==============================================
=                Multiset Lookup               =
==============================================*/
template <typename Key>
size_t multiset<Key>::count(const Key& key) {
  Node* exist_node_list =
      static_cast<Node*>(this->GetExistNode(this->root_.left, key));
  return exist_node_list->value.size();
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::find(const Key& key) {
  BaseNode* result = nullptr;

  if (!this->empty() && this->contains(key)) {
    result = this->GetExistNode(this->root_.left, key);
  } else {
    result = this->end().get_node_ptr();
  }

  return {result};
}

template <typename Key>
std::pair<typename multiset<Key>::iterator, typename multiset<Key>::iterator>
multiset<Key>::equal_range(const Key& key) {
  return {lower_bound(key), upper_bound(key)};
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::lower_bound(const Key& key) {
  iterator result = this->end();

  for (auto iter = begin(); iter != this->end(); ++iter) {
    if (*iter >= key) {
      result = iter;
      break;
    }
  }
  return result;
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::upper_bound(const Key& key) {
  iterator result = this->end();

  for (auto iter = begin(); iter != this->end(); ++iter) {
    if (*iter > key) {
      result = iter;
      break;
    }
  }
  return result;
}

/*==============================================
=                  BONUS PART                  =
==============================================*/
template <typename Key>
template <typename... Args>
s21::vector<std::pair<typename multiset<Key>::iterator, bool>>
multiset<Key>::insert_many(Args&&... args) {
  s21::vector<std::pair<typename multiset<Key>::iterator, bool>> result;

  multiset<Key> tmp{args...};

  for (auto iter = tmp.begin(); iter != tmp.end(); ++iter) {
    auto result_elem = insert(*iter);
    result.push_back({result_elem, true});
  }

  result.shrink_to_fit();

  return result;
}

}  // namespace s21

#endif  // S21_CONTAINERS_S21_MULTISET_S21_MULTISET_TPP_