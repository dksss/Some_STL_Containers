#ifndef S21_CONTAINERS_S21_LIST_S21_LIST_TPP_
#define S21_CONTAINERS_S21_LIST_S21_LIST_TPP_

namespace s21 {

template <class T>
class list<T>::ListIterator {
 public:
  struct node *some_node;
  bool equivalent;
  ListIterator(){};
  ListIterator(struct node *some_ptr) : some_node(some_ptr){};

  T operator*() { return some_node->element; }

  ListIterator &operator--() {
    some_node = some_node->previous;
    return *this;
  };
  ListIterator operator--(int) {
    ListIterator tmp = *this;
    some_node = some_node->previous;
    return tmp;
  };
  ListIterator &operator++() {
    some_node = some_node->next;
    return *this;
  };
  ListIterator operator++(int) {
    ListIterator tmp = *this;
    some_node = some_node->next;
    return tmp;
  };

  bool operator==(ListIterator someObject) {
    if (some_node == someObject.some_node)
      equivalent = 1;
    else
      equivalent = 0;
    return equivalent;
  };
  bool operator!=(ListIterator someObject) {
    return (*this == someObject) ? 0 : 1;
  }
  void operator=(const_iterator someObject) {
    some_node = someObject.some_node;
  }
};

template <class T>
class list<T>::ListConstIterator {
 public:
  struct node *some_node;
  bool equivalent;
  ListConstIterator(){};
  ListConstIterator(struct node *some_ptr) : some_node(some_ptr){};
  ListConstIterator(iterator iter) : some_node(iter.some_node){};
  T operator*() { return some_node->element; }
  bool operator==(ListConstIterator someObject) {
    if (some_node == someObject.some_node)
      equivalent = 1;
    else
      equivalent = 0;
    return equivalent;
  };
  bool operator==(iterator someObject) {
    if (some_node == someObject.some_node)
      equivalent = 1;
    else
      equivalent = 0;
    return equivalent;
  };
  bool operator!=(ListConstIterator someObject) {
    return (*this == someObject) ? 0 : 1;
  }
  bool operator!=(iterator someObject) { return (*this == someObject) ? 0 : 1; }
};

template <class T>
typename list<T>::iterator list<T>::begin() {
  iterator someObject(head_node);
  return someObject;
};

template <class T>
typename list<T>::iterator list<T>::end() {
  iterator someObject(end_node);
  return someObject;
};

template <class T>
list<T>::list() {
  end_node->previous = nullptr;
  end_node->next = nullptr;
};

template <class T>
list<T>::list(size_type n) {
  iterator iter = begin();
  for (size_type i = 0; i < n; i++) insert(iter, 0);
};

template <class T>
list<T>::list(std::initializer_list<value_type> const &items) {
  for (value_type i : items) push_back(i);
};

template <class T>
list<T>::list(const list &l) {  // copy ctor
  iterator iter_of_argument_start(l.head_node);
  iterator iter_of_argument_end(l.end_node);
  iterator iter_of_this = begin();
  while (iter_of_argument_start != iter_of_argument_end) {
    insert(iter_of_this, iter_of_argument_start.some_node->element);
    ++iter_of_argument_start;
  }
};

template <class T>
list<T>::list(list &&l) {  // move ctor
  head_node = l.head_node;
  tail_node = l.tail_node;
  delete end_node;
  end_node = l.end_node;
  l.head_node = nullptr;
  l.tail_node = nullptr;
  l.end_node = nullptr;
};

template <class T>
list<T>::~list() {
  iterator iter = begin();
  if (iter.some_node != nullptr) {
    while (iter != end()) {
      if (iter.some_node->previous != nullptr) delete iter.some_node->previous;
      ++iter;
    }
    --iter;
    delete iter.some_node;
  }
  delete end_node;
};

template <class T>
list<T> &list<T>::operator=(list &&l) {
  clear();
  head_node = l.head_node;
  tail_node = l.tail_node;
  delete end_node;
  end_node = l.end_node;
  l.head_node = nullptr;
  l.tail_node = nullptr;
  l.end_node = nullptr;
  return *this;
};

template <class T>
typename list<T>::const_reference list<T>::front() {
  return head_node->element;
};
template <class T>
typename list<T>::const_reference list<T>::back() {
  return tail_node->element;
};

template <class T>
bool list<T>::empty() {
  return (head_node == end_node) ? 1 : 0;
};

template <class T>
typename list<T>::size_type list<T>::size() {
  size_type counter = 0;
  iterator iter = begin();
  while (iter != end()) {
    counter++;
    iter++;
  }
  return counter;
};

template <class T>
typename list<T>::size_type list<T>::max_size() {
  return (std::numeric_limits<size_type>::max() / sizeof(struct node));
};

template <class T>
void list<T>::clear() {
  iterator iter = begin();
  while (iter != end()) {
    if (iter.some_node->previous != nullptr) delete iter.some_node->previous;
    ++iter;
  }
  --iter;
  delete iter.some_node;
  end_node->previous = nullptr;
  head_node = end_node;
  tail_node = end_node;
};

template <class T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference value) {
  struct node *tmp_struct = new struct node;
  tmp_struct->element = value;
  if (pos == begin()) {
    tmp_struct->previous = nullptr;
    tmp_struct->next = head_node;

    if (head_node != end_node) {
      head_node->previous = tmp_struct;
      head_node = tmp_struct;
    } else {
      head_node = tmp_struct;
      tail_node = tmp_struct;
      head_node->next = end_node;
      end_node->previous = tail_node;
    }

  } else if (pos == end()) {
    tmp_struct->previous = tail_node;
    tmp_struct->next = end_node;
    end_node->previous = tmp_struct;

    if (tail_node != end_node)
      tail_node->next = tmp_struct;
    else
      head_node = tmp_struct;
    tail_node = tmp_struct;

  } else {
    tmp_struct->next = pos.some_node;
    tmp_struct->previous = pos.some_node->previous;
    pos.some_node->previous->next = tmp_struct;
    pos.some_node->previous = tmp_struct;
  }

  return tmp_struct;
};

template <class T>
void list<T>::erase(iterator pos) {
  struct node *temp_previous = pos.some_node->previous;
  struct node *temp_next = pos.some_node->next;
  struct node *temp = pos.some_node;
  if (temp_previous != nullptr) {
    --pos;
    pos.some_node->next = temp_next;
  } else
    head_node = temp_next;
  if (temp_next != nullptr) {
    ++pos;
    pos.some_node->previous = temp_previous;
  } else
    throw std::invalid_argument("can't delete end node");
  delete temp;
};

template <class T>
void list<T>::push_back(const_reference value) {
  insert(end(), value);
};

template <class T>
void list<T>::pop_back() {
  iterator temp_iter = end();
  erase(--temp_iter);
};

template <class T>
void list<T>::push_front(const_reference value) {
  insert(begin(), value);
};

template <class T>
void list<T>::pop_front() {
  iterator temp_iter = begin();
  erase(temp_iter);
};

template <class T>
void list<T>::swap(list &other) {
  list<T> temp_obj(std::move(*this));

  head_node = other.head_node;
  tail_node = other.tail_node;
  end_node = other.end_node;

  other.head_node = temp_obj.head_node;
  other.tail_node = temp_obj.tail_node;
  other.end_node = temp_obj.end_node;

  temp_obj.head_node = nullptr;
  temp_obj.tail_node = nullptr;
  temp_obj.end_node = nullptr;
};

template <class T>
void list<T>::merge(list &other) {
  iterator iter_of_this = begin();
  iterator iter_of_other = other.begin();
  while (iter_of_other != other.end() && iter_of_this != end()) {
    if (iter_of_other.some_node->element <= iter_of_this.some_node->element) {
      insert(iter_of_this, iter_of_other.some_node->element);
      iter_of_other++;
    } else
      iter_of_this++;
  }
  while (iter_of_other != other.end()) {
    push_back(iter_of_other.some_node->element);
    iter_of_other++;
  }
};

template <class T>
void list<T>::splice(const_iterator pos, list &other) {
  iterator iter_of_other = other.begin();
  iterator non_const_pos;
  non_const_pos = pos;
  while (iter_of_other != other.end()) {
    insert(non_const_pos, iter_of_other.some_node->element);
    iter_of_other++;
  }
};

template <class T>
void list<T>::reverse() {
  iterator iter = begin();
  struct node *temp = 0;
  tail_node = iter.some_node;
  while (iter != end()) {
    temp = iter.some_node->previous;
    iter.some_node->previous = iter.some_node->next;
    iter.some_node->next = temp;
    --iter;
  }
  --iter;
  iter.some_node->previous = nullptr;
  head_node = iter.some_node;
  tail_node->next = end_node;
  end_node->previous = tail_node;
};

template <class T>
void list<T>::unique() {
  iterator iter = begin();
  iterator temp_iter;
  if (iter != end()) iter++;
  while (iter != end()) {
    if (iter.some_node->previous->element == iter.some_node->element) {
      temp_iter = iter;
      --temp_iter;
      erase(iter);
      iter = temp_iter;
    }
    iter++;
  }
};

template <class T>
void list<T>::sort() {
  iterator iter;
  bool swapped;
  for (long unsigned int i = 0; i < size() - 1; i++) {
    iter = begin();
    swapped = 0;
    for (long unsigned int j = 0; j < size() - i - 1; j++) {
      if (iter.some_node->element > iter.some_node->next->element) {
        if (iter.some_node->previous != nullptr)
          iter.some_node->previous->next = iter.some_node->next;
        else
          head_node = iter.some_node->next;
        iter.some_node->next->next->previous = iter.some_node;
        iter.some_node->next->previous = iter.some_node->previous;
        iter.some_node->previous = iter.some_node->next;
        iter.some_node->next = iter.some_node->next->next;
        iter.some_node->previous->next = iter.some_node;
        swapped = 1;
      } else
        iter++;
    }
    if (swapped == 0) break;
  }
};

template <class T>
template <class... Args>
typename list<T>::iterator list<T>::insert_many(const_iterator pos,
                                                Args &&...args) {
  iterator non_const_pos;
  non_const_pos = pos;
  for (const T &some_value : {args...}) insert(non_const_pos, some_value);
  return non_const_pos;
};

template <class T>
template <class... Args>
void list<T>::insert_many_back(Args &&...args) {
  for (const T &some_value : {args...}) push_back(some_value);
};

template <class T>
template <class... Args>
void list<T>::insert_many_front(Args &&...args) {
  iterator iter = begin();
  for (const T &some_value : {args...}) insert(iter, some_value);
};

}  // namespace s21

#endif  // S21_CONTAINERS_S21_LIST_S21_LIST_TPP_