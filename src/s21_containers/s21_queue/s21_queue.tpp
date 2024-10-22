#ifndef S21_CONTAINERS_S21_QUEUE_S21_QUEUE_TPP_
#define S21_CONTAINERS_S21_QUEUE_S21_QUEUE_TPP_

#include "../s21_list/list.h"

namespace s21 {

/*==============================================
=            Queue Member functions            =
==============================================*/
template <typename T, class Container>
queue<T, Container>::queue() : some_container_() {}

template <typename T, class Container>
queue<T, Container>::queue(std::initializer_list<value_type> const& items)
    : some_container_(items) {}

template <typename T, class Container>
queue<T, Container>::queue(const queue& q)
    : some_container_(q.some_container_) {}

template <typename T, class Container>
queue<T, Container>::queue(queue&& q)
    : some_container_(std::move(q.some_container_)) {}

template <typename T, class Container>
queue<T, Container>& queue<T, Container>::operator=(queue&& q) {
  if (this != &q) {
    some_container_ = std::move(q.some_container_);
  }
  return *this;
}

/*==============================================
=             Queue Element Access             =
==============================================*/
template <typename T, class Container>
const T& queue<T, Container>::front() {
  return some_container_.front();
}

template <typename T, class Container>
const T& queue<T, Container>::back() {
  return some_container_.back();
}

/*==============================================
=                Queue Capacity                =
==============================================*/
template <typename T, class Container>
bool queue<T, Container>::empty() {
  return some_container_.empty();
}

template <typename T, class Container>
size_t queue<T, Container>::size() {
  return some_container_.size();
}

/*==============================================
=                Queue Modifiers               =
==============================================*/
template <typename T, class Container>
void queue<T, Container>::push(const_reference value) {
  some_container_.push_back(value);
}

template <typename T, class Container>
void queue<T, Container>::pop() {
  some_container_.pop_front();
}

template <typename T, class Container>
void queue<T, Container>::swap(queue& other) {
  some_container_.swap(other.some_container_);
}

/*==============================================
=                     BONUS                    =
==============================================*/
template <typename T, class Container>
template <class... Args>
void queue<T, Container>::insert_many_back(Args&&... args) {
  for (auto& arg : {args...}) {
    some_container_.push_back(arg);
  }
}

}  // namespace s21

#endif  // S21_CONTAINERS_S21_QUEUE_S21_QUEUE_TPP_