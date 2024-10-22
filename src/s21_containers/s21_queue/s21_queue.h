#ifndef S21_CONTAINERS_S21_QUEUE_S21_QUEUE_H_
#define S21_CONTAINERS_S21_QUEUE_S21_QUEUE_H_

#include "../s21_list/list.h"

namespace s21 {

// дефолтное значение внутреннего класса в адаптере =list
// так же может быть любой контейнер с методами push(), pop(), top() 
template <typename T, class Container = s21::list<T>>
class queue {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

  // Queue Member functions
  queue();
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &q);
  queue(queue &&q);
  ~queue() = default;
  queue& operator=(queue &&q);

  // Queue Element access
  const_reference front();
  const_reference back();

  // Queue Capacity
  bool empty();
  size_type size();

  // Queue Modifiers
  void push(const_reference value);
  void pop();
  void swap(queue& other);

  // BONUS
  template <class... Args>
  void insert_many_back(Args&&... args);

 private:
  Container some_container_;
};

} // namespace s21

#include "./s21_queue.tpp"

#endif // S21_CONTAINERS_S21_QUEUE_S21_QUEUE_H_