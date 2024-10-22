#ifndef S21_CONTAINERS_S21_STACK_S21_STACK_TPP_
#define S21_CONTAINERS_S21_STACK_S21_STACK_TPP_

#include "../s21_vector/s21_vector.h"

namespace s21 {

/*==============================================
=            Stack Member functions            =
==============================================*/
template <typename T, class Container>
stack<T, Container>::stack() : some_container_() {}

template <typename T, class Container>
stack<T, Container>::stack(std::initializer_list<value_type> const& items)
    : some_container_(items) {}

template <typename T, class Container>
stack<T, Container>::stack(const stack& s)
    : some_container_(s.some_container_) {}

template <typename T, class Container>
stack<T, Container>::stack(stack&& s)
    : some_container_(std::move(s.some_container_)) {}

template <typename T, class Container>
stack<T, Container>& stack<T, Container>::operator=(stack&& s) {
  if (this != &s) {
    some_container_ = std::move(s.some_container_);
  }
  return *this;
}

/*==============================================
=             Stack Element Access             =
// ==============================================*/
template <typename T, class Container>
const T& stack<T, Container>::top() {
  return some_container_.back();
}

/*==============================================
=                Stack Capacity                =
==============================================*/
template <typename T, class Container>
bool stack<T, Container>::empty() {
  return some_container_.empty();
}

template <typename T, class Container>
size_t stack<T, Container>::size() {
  return some_container_.size();
}

/*==============================================
=                Stack Modifiers               =
==============================================*/
template <typename T, class Container>
void stack<T, Container>::push(const_reference value) {
  some_container_.push_back(value);
}

template <typename T, class Container>
void stack<T, Container>::pop() {
  some_container_.pop_back();
}

template <typename T, class Container>
void stack<T, Container>::swap(stack& other) {
  some_container_.swap(other.some_container_);
}

/*==============================================
=                     BONUS                    =
==============================================*/
template <typename T, class Container>
template <class... Args>
void stack<T, Container>::insert_many_front(Args&&... args) {
  for (auto& arg : {args...}) {
    push(arg);
  }
}

}  // namespace s21

#endif  // S21_CONTAINERS_S21_STACK_S21_STACK_TPP_