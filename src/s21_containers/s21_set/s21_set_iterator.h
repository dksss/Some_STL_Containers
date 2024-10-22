#ifndef S21_CONTAINERS_S21_SET_S21_SET_ITERATOR_H_
#define S21_CONTAINERS_S21_SET_S21_SET_ITERATOR_H_

#include "../common/base_tree_iterator.h"

namespace s21 {

template <typename Key>
template <bool is_const>
class set<Key>::BaseSetIterator
    : public RBTree<Key, Key>::BaseTreeIterator<is_const> {
  using BaseTreeIterator =
      typename RBTree<Key, Key>::BaseTreeIterator<is_const>;

 public:
  using reference_type = std::conditional_t<is_const, const Key&, Key&>;

  BaseSetIterator() { this->node_ptr_ = nullptr; }
  BaseSetIterator(const BaseSetIterator&) = default;
  BaseSetIterator& operator=(const BaseSetIterator&) = default;
  BaseSetIterator(const BaseTreeIterator& other) {
    this->node_ptr_ = other.get_node_ptr();
  }
  BaseSetIterator& operator=(const BaseTreeIterator& other) {
    this->node_ptr_ = other.get_node_ptr();
    return *this;
  }

  const reference_type operator*() const {
    Node* value_node = static_cast<Node*>(this->node_ptr_);
    return value_node->key;
  }

  friend class set<Key>;

 protected:
  using BaseTreeIterator::get_node_ptr;

 private:
  BaseSetIterator(BaseNode* ptr) { this->node_ptr_ = ptr; }
};

}  // namespace s21

#endif  // S21_CONTAINERS_S21_SET_S21_SET_ITERATOR_H_