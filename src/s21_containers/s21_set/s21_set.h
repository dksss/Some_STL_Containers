#ifndef S21_CONTAINERS_S21_SET_S21_SET_H_
#define S21_CONTAINERS_S21_SET_S21_SET_H_

#include "../common/rb_tree.h"         // for inheritance
#include "../s21_vector/s21_vector.h"  // for BONUS PART

namespace s21 {

template <typename Key>
class set : public RBTree<Key, Key> {
  using Node = typename RBTree<Key, Key>::Node;
  using BaseNode = typename RBTree<Key, Key>::BaseNode;

  template <bool is_const>
  class BaseSetIterator;

 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = set<Key>::BaseSetIterator<false>;
  using const_iterator = set<Key>::BaseSetIterator<true>;
  using size_type = size_t;

  // Set Member funcs
  set();
  set(std::initializer_list<value_type> const& items);
  set(const set& m);
  set(set&& m);
  ~set() = default;
  set& operator=(set&& m);

  // Set Modifiers
  std::pair<iterator, bool> insert(const value_type& value);

  // Set Lookup
  iterator find(const Key& key);

  // BONUS PART
  template <class... Args>
  s21::vector<std::pair<iterator, bool>> insert_many(Args&&... args);

  std::pair<iterator, bool> TestInsert() = delete;
  void PrintTree() = delete;
};

}  // namespace s21

#include "./s21_set.tpp"
#include "./s21_set_iterator.h"

#endif  // S21_CONTAINERS_S21_SET_S21_SET_H_