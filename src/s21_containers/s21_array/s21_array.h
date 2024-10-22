#ifndef S21_CONTAINERS_S21_ARRAY_S21_ARRAY_H_
#define S21_CONTAINERS_S21_ARRAY_S21_ARRAY_H_

#include <initializer_list>  // for constructor
#include <stdexcept>         // std::out_of_range
#include <utility>           // std::swap()

namespace s21 {

template <typename T, std::size_t N>
class array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  // Array Member functions
  array();
  array(std::initializer_list<value_type> const &items);
  array(const array<T, N> &a);
  array(array<T, N> &&a);
  ~array();
  array<T, N> &operator=(array<T, N> &&a);

  // Array Element Access
  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front() const;
  const_reference back() const;
  iterator data();

  // Array Iterators
  iterator begin();
  iterator end();

  // Array Capacity
  bool empty();
  size_type size();
  size_type max_size();

  // Array Modifiers
  void swap(array<T, N> &other);
  void fill(const_reference value);

 private:
  size_type size_ = N;
  value_type data_[N];
};

}  // namespace s21

#include "./s21_array.tpp"

#endif  // S21_CONTAINERS_S21_ARRAY_S21_ARRAY_H_