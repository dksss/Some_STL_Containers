#ifndef S21_CONTAINERS_S21_VECTOR_S21_VECTOR_H_
#define S21_CONTAINERS_S21_VECTOR_S21_VECTOR_H_

#include <algorithm>         // std::copy()
#include <initializer_list>  // for constructor
#include <limits>            // std::numeric_limits
#include <stdexcept>         // std::out_of_range
#include <utility>           // std::swap(), std::move()

namespace s21 {

template <typename T>
class vector {
  template <bool IsConst>
  class BaseVectorIterator;

 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = vector<T>::BaseVectorIterator<false>;
  using const_iterator = vector<T>::BaseVectorIterator<true>;
  using size_type = size_t;

  // Vector Member functions
  vector();
  explicit vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  vector(vector &&v);
  ~vector();
  vector<T> &operator=(vector &&v);

  // Vector Element access
  reference at(size_type pos);
  const_reference at(size_type pos) const;
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;
  const_reference front();
  const_reference back();
  T *data();

  // Vector Iterators
  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;

  // Vector Capacity
  bool empty() const;
  size_type size() const;
  size_type max_size() const;
  void reserve(size_type size);
  size_type capacity() const;
  void shrink_to_fit();

  // Vector Modifiers
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector &other);

  // BONUS PART
  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <typename... Args>
  void insert_many_back(Args &&...args);

 private:
  size_type size_;
  size_type capacity_;
  T *data_;

  T *GetRawMemory(size_t);
  void DelRawMemory();
  void CapacityHandling();
};

}  // namespace s21

#include "./s21_vector.tpp"
#include "./s21_vector_iterator.h"

#endif  // S21_CONTAINERS_S21_VECTOR_S21_VECTOR_H_