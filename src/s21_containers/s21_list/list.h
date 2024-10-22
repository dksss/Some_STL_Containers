#ifndef S21_CONTAINERS_S21_LIST_S21_LIST_H_
#define S21_CONTAINERS_S21_LIST_S21_LIST_H_

#include <cstddef>           // for size_t
#include <initializer_list>  // for ctor with initializer_list
#include <iostream>          // for  cout, for testing
#include <limits>            // for max_size
#include <stdexcept>         // for throwing exceptions

namespace s21 {

template <class T>
class list {
 public:
  class ListConstIterator;
  class ListIterator;
  using reference = T &;
  using value_type = T;
  using size_type = size_t;
  using const_iterator = ListConstIterator;
  using iterator = ListIterator;
  using const_reference = const T &;

  iterator begin();
  iterator end();

  // ctors
  list();
  list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &l);
  list(list &&l);
  ~list();

  // overload
  list &operator=(list &&l);

  // List Element access
  const_reference front();
  const_reference back();

  // List Capacity
  bool empty();
  size_type size();
  size_type max_size();

  // List Modifiers
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other);
  void merge(list &other);
  void splice(const_iterator pos, list &other);
  void reverse();
  void unique();
  void sort();

  template <class... Args>
  iterator insert_many(const_iterator pos, Args &&...args);

  template <class... Args>
  void insert_many_back(Args &&...args);

  template <class... Args>
  void insert_many_front(Args &&...args);

 private:
  struct node {
    value_type element;
    struct node *next;
    struct node *previous;
  };

  struct node *end_node = new struct node;
  struct node *head_node = end_node;
  struct node *tail_node = end_node;
};

};  // namespace s21

#include "list.tpp"

#endif // S21_CONTAINERS_S21_LIST_S21_LIST_H_