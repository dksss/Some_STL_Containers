#ifndef S21_CONTAINERS_S21_MULTISET_S21_MULTISET_ITERATOR_H_
#define S21_CONTAINERS_S21_MULTISET_S21_MULTISET_ITERATOR_H_

#include "../common/base_tree_iterator.h"

namespace s21 {

template <typename Key>
template <bool is_const>
class multiset<Key>::BaseMultisetIterator: public RBTree<Key, s21::list<Key>>::BaseTreeIterator<is_const> {
 public:
  using BaseTreeIterator = typename RBTree<Key, s21::list<Key>>::BaseTreeIterator<is_const>;
  using pointer_type = std::conditional_t<is_const, const Key*, Key*>;
  using reference_type = std::conditional_t<is_const, const Key, const Key>;

  BaseMultisetIterator() {
    this->node_ptr_ = nullptr;
  }
  BaseMultisetIterator(const BaseMultisetIterator&) = default;
  BaseMultisetIterator(const BaseTreeIterator& other) {
    this->node_ptr_ = other.get_node_ptr();

    if (this->node_ptr_ != this->node_ptr_->parent)
      value_iter_ = GetListIterator(true);
  }
  BaseMultisetIterator& operator=(const BaseMultisetIterator&) = default;
  BaseMultisetIterator& operator=(const BaseTreeIterator& other) {
    this->node_ptr_ = other.get_node_ptr();

    if (this->node_ptr_ != this->node_ptr_->parent)
      value_iter_ = GetListIterator(true);

    return *this;
  }

  reference_type operator*() {
    return *value_iter_;
  }
  pointer_type operator->() const {
    return value_iter_;
  }

  /*
  * Тк каждая нода в мултисете является листом с ключами, 
  * то для итераций по мультиесету проверяем
  * прошли ли мы каждую реальную ноду листа в ноде мультисета
  * 
  * В результате мы либо итерируемся по нодам листа, либо по нодам мультисета
  */
  BaseMultisetIterator& operator++() {
    if (this->node_ptr_ != this->node_ptr_->parent) {
      auto list_end_iter = GetListIterator(false);
      if (value_iter_ == list_end_iter) {
        MoveToNextNodeAndResetIter();
      } else {
        ++value_iter_;
        if (value_iter_ == list_end_iter) {
          MoveToNextNodeAndResetIter();
        }
      }
    } else {
      this->node_ptr_ = BaseTreeIterator::operator++().get_node_ptr();
    }

    return *this;
  }
  BaseMultisetIterator operator++(int) {
    BaseMultisetIterator copy = *this;
    ++(*this);
    return copy;
  }
  BaseMultisetIterator& operator--() {
    if (this->node_ptr_ != this->node_ptr_->parent) {
      auto list_begin_iter = GetListIterator(true);
      if (value_iter_ != list_begin_iter) {
        --value_iter_;
      } else {
        this->node_ptr_ = BaseTreeIterator::operator--().get_node_ptr();
        value_iter_ = --(GetListIterator(false)); // приравниваем к последней реальной ноде листа
      }
    } else {
      this->node_ptr_ = BaseTreeIterator::operator--().get_node_ptr();
      value_iter_ = --(GetListIterator(false));
    }

    return *this;
  }
  BaseMultisetIterator operator--(int) {
    BaseMultisetIterator copy = *this;
    --(*this);
    return copy;
  }
  bool operator==(const BaseMultisetIterator& other) { // need tests
    bool result = false;

    if (this->node_ptr_ == other.node_ptr_) {
      if (this->node_ptr_ == this->node_ptr_->parent) {
        result = true;
      } else if (value_iter_ == other.value_iter_) {
        result = true;
      }
    }

    return result;
  }
  bool operator!=(const BaseMultisetIterator& other) { // need tests
    return !(*this == other);
  }
  operator BaseMultisetIterator<true>() const { return {this->node_ptr_}; }

  friend class multiset<Key>;

 protected:
  using BaseTreeIterator::get_node_ptr;

 private:
  typename s21::list<Key>::iterator value_iter_;

  BaseMultisetIterator(BaseNode* ptr) { // ! check
    this->node_ptr_ = ptr;

    if (this->node_ptr_ != this->node_ptr_->parent)
      value_iter_ = GetListIterator(true);
  }

  typename s21::list<Key>::iterator GetListIterator(bool is_begin) {
    Node* cur_node = static_cast<Node*>(this->node_ptr_);
    typename s21::list<Key>::iterator list_iter;
      
    if (is_begin) {
      list_iter = cur_node->value.begin();
    } else {
      list_iter = cur_node->value.end();
    }

    return list_iter;
  }
  void MoveToNextNodeAndResetIter() {
    this->node_ptr_ = BaseTreeIterator::operator++().get_node_ptr();
    if (this->node_ptr_ != this->node_ptr_->parent)
      value_iter_ = GetListIterator(true);
  }
};

} // namespace s21

#endif // S21_CONTAINERS_S21_MULTISET_S21_MULTISET_ITERATOR_H_