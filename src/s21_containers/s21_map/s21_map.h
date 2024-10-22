#ifndef S21_CONTAINERS_S21_MAP_S21_MAP_H_
#define S21_CONTAINERS_S21_MAP_S21_MAP_H_

#include <utility>  // std::pair

#include "../common/rb_tree.h"         // for inheritence
#include "../s21_vector/s21_vector.h"  // for BONUS PART

namespace s21 {

template <typename Key, typename T>
class map : public RBTree<Key, T> {
  using Node = typename RBTree<Key, T>::Node;
  using BaseNode = typename RBTree<Key, T>::BaseNode;

  template <bool is_const>
  class BaseMapIterator;

 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = map<Key, T>::BaseMapIterator<false>;
  using const_iterator = map<Key, T>::BaseMapIterator<true>;
  using size_type = size_t;

  // Map Member functions
  map();
  map(std::initializer_list<value_type> const& items);
  map(const map& m);
  map(map&& m);
  ~map() = default;
  map& operator=(map&& m);

  // Map Element Access
  T& at(const Key& key);
  T& operator[](const Key& key);

  // Map Modifiers
  std::pair<iterator, bool> insert(const value_type& value);
  std::pair<iterator, bool> insert(const Key& key, const T& obj);
  std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);

  // BONUS PART
  template <typename... Args>
  s21::vector<std::pair<iterator, bool>> insert_many(Args&&... args);

  void PrintTree() = delete;
  void TestInsert(const key_type&) = delete;

 private:
  void ChangeValue(BaseNode* some_node, const T& obj);
};

}  // namespace s21

#include "./s21_map.tpp"
#include "./s21_map_iterator.h"

#endif  // S21_CONTAINERS_S21_MAP_S21_MAP_H_