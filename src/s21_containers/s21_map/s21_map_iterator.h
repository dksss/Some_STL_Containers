#ifndef S21_CONTAINERS_S21_MAP_S21_MAP_ITERATOR_H_
#define S21_CONTAINERS_S21_MAP_S21_MAP_ITERATOR_H_

#include "../common/base_tree_iterator.h"

namespace s21 {

template <typename Key, typename T>
template <bool is_const>
class map<Key, T>::BaseMapIterator
    : public RBTree<Key, T>::BaseTreeIterator<is_const> {
  using BaseTreeIterator = typename RBTree<Key, T>::BaseTreeIterator<is_const>;

 public:
  using pointer_type = std::conditional_t<is_const, const Node*, Node*>;
  using reference_type = std::conditional_t<is_const, const T&, T&>;

  BaseMapIterator() { this->node_ptr_ = nullptr; }
  BaseMapIterator(const BaseMapIterator&) = default;
  BaseMapIterator& operator=(const BaseMapIterator&) = default;
  BaseMapIterator(const BaseTreeIterator& other) {
    this->node_ptr_ = other.get_node_ptr();
  }
  BaseMapIterator& operator=(const BaseTreeIterator& other) {
    this->node_ptr_ = other.get_node_ptr();
    return *this;
  }

  reference_type operator*() const {
    Node* value_node = static_cast<Node*>(this->node_ptr_);
    return value_node->value;
  }
  pointer_type operator->() const {
    Node* value_node = static_cast<Node*>(this->node_ptr_);
    return value_node;
  }

  operator BaseMapIterator<true>() const { return {this->node_ptr_}; }

  friend class map<Key, T>;

 protected:
  using BaseTreeIterator::get_node_ptr;

 private:
  BaseMapIterator(BaseNode* ptr) { this->node_ptr_ = ptr; }
};

}  // namespace s21

#endif  // S21_CONTAINERS_S21_MAP_S21_MAP_ITERATOR_H_