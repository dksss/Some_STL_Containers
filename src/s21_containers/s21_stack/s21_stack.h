#ifndef S21_CONTAINERS_S21_STACK_S21_STACK_H_
#define S21_CONTAINERS_S21_STACK_S21_STACK_H_

#include "../s21_vector/s21_vector.h"

namespace s21 {

template <class T, class Container = s21::vector<T>>
class stack {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

  // Stack Member functions
  stack();
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &s);
  stack(stack &&s);
  ~stack() = default;
  stack &operator=(stack &&s);

  // Stack Element access
  const_reference top();

  // Stack Capacity
  bool empty();
  size_type size();

  // Stack Modifiers
  void push(const_reference value);
  void pop();
  void swap(stack &other);

  template <class... Args>
  void insert_many_front(Args&&... args);

 private:
  Container some_container_;
};

} //  namespace s21

#include "./s21_stack.tpp"

#endif // S21_CONTAINERS_S21_STACK_S21_STACK_H_