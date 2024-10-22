#ifndef S21_CONTAINERS_S21_VECTOR_S21VECTOR_TPP_
#define S21_CONTAINERS_S21_VECTOR_S21VECTOR_TPP_

namespace s21 {

/*==============================================
=               Helpful methods                =
==============================================*/

template <typename T>
T *vector<T>::GetRawMemory(size_t n) {
  T *data = reinterpret_cast<T *>(new char[n * sizeof(T)]());
  return data;
}

template <typename T>
void vector<T>::DelRawMemory() {
  delete[] reinterpret_cast<char *>(data_);
}

template <typename T>
void vector<T>::CapacityHandling() {
  if (size_ == capacity_) {
    reserve(capacity_ > 0 ? capacity_ * 2 : 1);
  }
}

/*==============================================
=            Vector Member functions           =
==============================================*/

template <typename T>
vector<T>::vector() : size_(0), capacity_(0), data_(nullptr) {}

template <typename T>
vector<T>::vector(size_type n)
    : size_(n), capacity_(n), data_(GetRawMemory(n)) {}

template <typename T>
vector<T>::vector(std::initializer_list<value_type> const &items)
    : size_(items.size()),
      capacity_(items.size()),
      data_(GetRawMemory(items.size())) {
  auto it = items.begin();
  for (size_t i = 0; i < items.size(); ++i, ++it) {
    new (data_ + i) T(*it);
  }
}

template <typename T>
vector<T>::vector(const vector &v)
    : size_(v.size_), capacity_(v.capacity_), data_(GetRawMemory(v.capacity_)) {
  for (size_t i = 0; i < size_; ++i) {
    new (data_ + i) T(v.data_[i]);
  }
}

template <typename T>
vector<T>::vector(vector &&v) : vector() {
  swap(v);
}

template <typename T>
vector<T>::~vector() {
  if (data_ != nullptr) {
    for (size_t i = 0; i < size_; ++i) {
      (data_ + i)->~T();
    }

    DelRawMemory();
    data_ = nullptr;
  }
}

template <typename T>
vector<T> &vector<T>::operator=(vector &&v) {
  vector<T> tmp;
  tmp.swap(v);
  swap(tmp);
  return *this;
}

/*==============================================
=             Vector Element access            =
==============================================*/

template <typename T>
T &vector<T>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Error: Out of range\n");
  }
  return data_[pos];
}

template <typename T>
const T &vector<T>::at(size_type pos) const {
  if (pos >= size_) throw std::out_of_range("Error: Out of range\n");
  return data_[pos];
}

template <typename T>
T &vector<T>::operator[](size_type pos) {
  return data_[pos];
}

template <typename T>
const T &vector<T>::operator[](size_type pos) const {
  return data_[pos];
}

template <typename T>
const T &vector<T>::front() {
  return *begin();
}

template <typename T>
const T &vector<T>::back() {
  return *(end() - 1);
}

template <typename T>
T *vector<T>::data() {
  return data_;
}

/*==============================================
=               Vector Iterators               =
==============================================*/

template <typename T>
typename vector<T>::iterator vector<T>::begin() {
  return iterator{data_};
}

template <typename T>
typename vector<T>::const_iterator vector<T>::begin() const {
  return const_iterator{data_};
}

template <typename T>
typename vector<T>::iterator vector<T>::end() {
  return iterator{data_ + size_};
}

template <typename T>
typename vector<T>::const_iterator vector<T>::end() const {
  return const_iterator{data_ + size_};
}

/*==============================================
=               Vector Capacity                =
==============================================*/

template <typename T>
bool vector<T>::empty() const {
  return (begin() == end());
}

template <typename T>
size_t vector<T>::size() const {
  return size_;
}

template <typename T>
size_t vector<T>::max_size() const {
  // при написании заметил, что std::vector возвращает значение /2
  return (std::numeric_limits<size_t>::max() / sizeof(T)) / 2;
}

template <typename T>
void vector<T>::reserve(size_t size) {
  if (size <= capacity_) return;

  if (size > max_size()) throw std::out_of_range("> max_capacity\n");

  T *new_data = GetRawMemory(size);
  for (size_t i = 0; i < size_; ++i) {
    new (new_data + i) T(data_[i]);
  }

  for (size_t i = 0; i < size_; ++i) {
    (data_ + i)->~T();
  }

  DelRawMemory();

  data_ = new_data;
  capacity_ = size;
}

template <typename T>
size_t vector<T>::capacity() const {
  return capacity_;
}

template <typename T>
void vector<T>::shrink_to_fit() {
  if (capacity_ > size_) {
    vector<T> tmp(size_);
    for (size_t i = 0; i < size_; ++i) {
      new (tmp.data_ + i) T(data_[i]);
    }
    swap(tmp);
  }
}

/*==============================================
=                Vector Modifiers              =
==============================================*/

template <typename T>
void vector<T>::clear() {
  for (size_t i = 0; i < size_; ++i) {
    (data_ + i)->~T();
  }
  size_ = 0;
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(iterator pos,
                                               const_reference value) {
  size_t i = pos - begin();

  CapacityHandling();

  for (size_t j = size_; j != i; --j) {
    new (data_ + j) T(data_[j - 1]);
    (data_ + j - 1)->~T();
  }

  new (data_ + i) T(value);
  ++size_;
  return iterator{data_ + i};
}

template <typename T>
void vector<T>::erase(iterator pos) {
  if (pos == end()) {
    throw std::out_of_range("Invalid iterator\n");
  }

  size_t i = pos - begin();
  (data_ + i)->~T();

  for (size_t j = i; j < size_ - 1; ++j) {
    data_[j] = std::move(data_[j + 1]);
  }
  --size_;
}

template <typename T>
void vector<T>::push_back(const_reference value) {
  CapacityHandling();
  new (data_ + size_) T(value);
  ++size_;
}

template <typename T>
void vector<T>::pop_back() {
  (data_ + size_ - 1)->~T();
  --size_;
}

template <typename T>
void vector<T>::swap(vector &other) {
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
  std::swap(data_, other.data_);
}

/*==============================================
=                     BONUS                    =
==============================================*/

template <typename T>
template <typename... Args>
typename vector<T>::iterator vector<T>::insert_many(const_iterator pos,
                                                    Args &&...args) {
  vector<T> tmp{args...};

  size_t iter_pos = pos - begin();
  iterator it = begin() + iter_pos;
  for (size_t i = 0; i < tmp.size(); ++i) {
    it = insert(it, tmp[i]);
    ++it;
  }
  return it;
}

template <typename T>
template <typename... Args>
void vector<T>::insert_many_back(Args &&...args) {
  vector<T> tmp{args...};
  for (size_t i = 0; i < tmp.size(); ++i) {
    insert(end(), tmp[i]);
  }
}

}  // namespace s21

#endif  // S21_CONTAINERS_S21_VECTOR_S21VECTOR_TPP_