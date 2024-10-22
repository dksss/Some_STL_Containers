#ifndef S21_CONTAINERS_S21_ARRAY_S21_ARRAY_TPP_
#define S21_CONTAINERS_S21_ARRAY_S21_ARRAY_TPP_

namespace s21 {

/*==============================================
=            Vector Member functions           =
==============================================*/

/*
 * не используем списковую инициализацию, тк размер и массив задаются
 * по умолчанию от параметров T и N
 */
template <typename T, std::size_t N>
array<T, N>::array() {}

template <typename T, std::size_t N>
array<T, N>::array(std::initializer_list<value_type> const& items) {
  auto tmp = items.begin();
  for (size_t i = 0; i < items.size(); ++i, ++tmp) {
    new (data_ + i) T(*tmp);
  }
}

template <typename T, std::size_t N>
array<T, N>::array(const array<T, N>& a) {
  for (size_t i = 0; i < size_; ++i) {
    new (data_ + i) T(a.data_[i]);
  }
}

template <typename T, std::size_t N>
array<T, N>::array(array<T, N>&& a) : array() {
  swap(a);
}

template <typename T, std::size_t N>
array<T, N>::~array() {
  for (size_t i = 0; i < size_; ++i) {
    data_[i].~T();
  }
}

template <typename T, std::size_t N>
array<T, N>& array<T, N>::operator=(array<T, N>&& a) {
  swap(a);
  return *this;
}

/*==============================================
=              Array Element access            =
==============================================*/

template <typename T, std::size_t N>
T& array<T, N>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Error: Out of range\n");
  }
  return data_[pos];
}

template <typename T, std::size_t N>
T& array<T, N>::operator[](size_type pos) {
  return data_[pos];
}

template <typename T, std::size_t N>
const T& array<T, N>::front() const {
  return data_[0];
}

template <typename T, std::size_t N>
const T& array<T, N>::back() const {
  return data_[size_ - 1];
}

template <typename T, std::size_t N>
T* array<T, N>::data() {
  return &data_[0];
}

/*==============================================
=                Array Iterators               =
==============================================*/

template <typename T, std::size_t N>
T* array<T, N>::begin() {
  return data_;
}

template <typename T, std::size_t N>
T* array<T, N>::end() {
  return data_ + size_;
}

/*==============================================
=                Array Capacity                =
==============================================*/

template <typename T, std::size_t N>
bool array<T, N>::empty() {
  return begin() == end();
}

template <typename T, std::size_t N>
size_t array<T, N>::size() {
  return size_;
}

template <typename T, std::size_t N>
size_t array<T, N>::max_size() {
  return size();
}

/*==============================================
=                 Array Modifiers              =
==============================================*/

template <typename T, std::size_t N>
void array<T, N>::swap(array<T, N>& other) {
  for (size_t i = 0; i < size_; ++i) {
    std::swap(data_[i], other.data_[i]);
  }
}

template <typename T, std::size_t N>
void array<T, N>::fill(const_reference value) {
  for (size_t i = 0; i < size_; ++i) {
    new (&data_[i]) T(value);
  }
}

}  // namespace s21

#endif  // S21_CONTAINERS_S21_ARRAY_S21_ARRAY_TPP_