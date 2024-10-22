#ifndef S21_CONTAINERS_S21_VECTOR_S21_VECTOR_ITERATOR_H_
#define S21_CONTAINERS_S21_VECTOR_S21_VECTOR_ITERATOR_H_

#include <type_traits>  // std::conditional_t

namespace s21 {

template <typename T>
template <bool IsConst>
class vector<T>::BaseVectorIterator {
 public:
  using pointer_type = std::conditional_t<IsConst, const T *, T *>;
  using reference_type = std::conditional_t<IsConst, const T &, T &>;
  using value_type = T;

  BaseVectorIterator(const BaseVectorIterator &) = default;
  BaseVectorIterator &operator=(const BaseVectorIterator &) = default;

  reference_type operator*() const { return *ptr_; }
  pointer_type operator->() const { return ptr_; }

  BaseVectorIterator &operator++() {
    ++ptr_;
    return *this;
  }

  BaseVectorIterator operator++(int) {
    BaseVectorIterator copy = *this;
    ++ptr_;
    return copy;
  }

  BaseVectorIterator &operator--() {
    --ptr_;
    return *this;
  }

  BaseVectorIterator operator--(int) {
    BaseVectorIterator copy = *this;
    --ptr_;
    return copy;
  }

  bool operator==(const BaseVectorIterator &other) const {
    return ptr_ == other.ptr_;
  }

  bool operator!=(const BaseVectorIterator &other) const {
    return !(*this == other);
  }

  BaseVectorIterator &operator-(int n) {
    ptr_ -= n;
    return *this;
  }

  BaseVectorIterator &operator+(int n) {
    ptr_ += n;
    return *this;
  }

  size_t operator-(const BaseVectorIterator &other) const {
    return ptr_ - other.ptr_;
  }

  operator BaseVectorIterator<true>() const { return {ptr_}; }

 private:
  pointer_type ptr_;

  BaseVectorIterator(T *ptr) : ptr_(ptr) {}

  friend class vector<T>;
};

}  // namespace s21

#endif  // S21_CONTAINERS_S21_VECTOR_S21_VECTOR_ITERATOR_H_