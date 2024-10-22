#ifndef S21_CONTAINERS_S21_MULTISET_S21_MULTISET_H_
#define S21_CONTAINERS_S21_MULTISET_S21_MULTISET_H_

#include "../common/rb_tree.h"
#include "../s21_list/list.h"
#include "../s21_vector/s21_vector.h"

namespace s21 {

template <typename Key>
class multiset : public RBTree<Key, s21::list<Key>> {
  using Node = typename RBTree<Key, s21::list<Key>>::Node;
  using BaseNode = typename RBTree<Key, s21::list<Key>>::BaseNode;

  template <bool is_const>
  class BaseMultisetIterator;

 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = BaseMultisetIterator<false>;
  using const_iterator = BaseMultisetIterator<true>;
  using size_type = size_t;

  // Multiset Member functions
  multiset();
  multiset(std::initializer_list<value_type> const& items);
  multiset(const multiset& ms);
  multiset(multiset&& ms);
  ~multiset();
  multiset& operator=(multiset&& ms);

  // Multiset Iterators
  iterator begin();

  // Multiset Modifiers
  void clear();
  iterator insert(const value_type& value);
  void erase(iterator pos);
  void merge(multiset& other);

  // Multiset Lookup
  size_type count(const Key& key);
  iterator find(const Key& key);
  std::pair<iterator,iterator> equal_range(const Key& key);
  iterator lower_bound(const Key& key);
  iterator upper_bound(const Key& key);

  // BOMUS PART
  template <typename... Args>
  s21::vector<std::pair<iterator, bool>> insert_many(Args&&... args);

  void TestInsert(const key_type&) = delete;
  void PrintTree() = delete;

 private:
  /*
  * @param plus_size Флаг, указывающий, нужно ли увеличивать размер контейнера.
  * (В родительском методе TreeInsert() автоматом увеличивается size_)
  */
  iterator AddValueToNode(const value_type& item, bool plus_size = true);

  /*
  * @brief Рекурсивное освобождение памяти
  *
  * Тк внутри этого контейнера используется другой контейнер, то дефолтный
  * деструктор и метод RecDelTree() не подходят.
  * Необходимо очистить внутренний контейнер вручную,
  * а затем удалять ноду
  */
  void FreeMemory(BaseNode*& baby_node);
};

}  // namespace s21

#include "./s21_multiset.tpp"
#include "./s21_multiset_iterator.h"

#endif  // S21_CONTAINERS_S21_MULTISET_S21_MULTISET_H_