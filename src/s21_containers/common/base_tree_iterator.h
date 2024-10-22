#ifndef S21_CONTAINERS_COMMON_BASE_TREE_ITERATOR_H_
#define S21_CONTAINERS_COMMON_BASE_TREE_ITERATOR_H_

#include <type_traits>  // std::conditional

namespace s21 {

template <typename Key, typename T>
template <bool is_const>
class RBTree<Key, T>::BaseTreeIterator {
 public:
  BaseTreeIterator() : node_ptr_(nullptr) {}
  BaseTreeIterator(const BaseTreeIterator&) = default;
  BaseTreeIterator& operator=(const BaseTreeIterator&) = default;

  /*
   * Отсутствуют методы: operator*() и operator->(),
   * тк они будут реализовываться в наследниках
   */
  BaseTreeIterator& operator++() {
    if (node_ptr_->right) {
      node_ptr_ = GetRightLeftNode();
    } else if (node_ptr_ == (node_ptr_->parent)->right) {
      while (node_ptr_ == (node_ptr_->parent)->right) {
        node_ptr_ = node_ptr_->parent;
      }
      // * по аналогии с operator--() (см. ниже)
      node_ptr_ = node_ptr_->parent;
    } else {
      node_ptr_ = node_ptr_->parent;
    }
    return *this;
  }
  BaseTreeIterator operator++(int) {
    BaseTreeIterator copy = *this;
    ++(*this);
    return copy;
  }
  BaseTreeIterator& operator--() {
    if (node_ptr_->left) {
      node_ptr_ = GetLeftRightNode();
    } else if (node_ptr_ == (node_ptr_->parent)->left) {
      while (node_ptr_ == (node_ptr_->parent)->left) {
        node_ptr_ = node_ptr_->parent;
      }
      // * После выхода из цикла, мы останавливаемся на пройденной ноде.
      // * Поэтому смещаемся вверх на одну
      node_ptr_ = node_ptr_->parent;
    } else {
      node_ptr_ = node_ptr_->parent;
    }

    return *this;
  }
  BaseTreeIterator operator--(int) {
    BaseTreeIterator copy = *this;
    --(*this);
    return copy;
  }
  bool operator==(const BaseTreeIterator& x) const {
    return (node_ptr_ == x.node_ptr_);
  }
  bool operator!=(const BaseTreeIterator& x) const { return !(*this == x); }
  operator BaseTreeIterator<true>() const { return {node_ptr_}; }
  BaseNode* get_node_ptr() const { return node_ptr_; }

 protected:  // для наследования в итераторы конкретных наследников
  BaseNode* node_ptr_;

  BaseTreeIterator(BaseNode* ptr) : node_ptr_(ptr) {}

  friend class RBTree<Key, T>;

 private:
  BaseNode* GetLeftRightNode() {
    BaseNode* left_right_node = node_ptr_->left;
    while (left_right_node->right) {
      left_right_node = left_right_node->right;
    }
    return left_right_node;
  }
  BaseNode* GetRightLeftNode() {
    BaseNode* right_left_node = node_ptr_->right;
    while (right_left_node->left) {
      right_left_node = right_left_node->left;
    }
    return right_left_node;
  }
};

}  // namespace s21

#endif  // S21_CONTAINERS_COMMON_BASE_TREE_ITERATOR_H_