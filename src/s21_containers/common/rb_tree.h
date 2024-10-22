#ifndef S21_CONTAINERS_COMMON_RB_TREE_H_
#define S21_CONTAINERS_COMMON_RB_TREE_H_

#include <initializer_list>  // for constructor
#include <limits>            // std::numeric_limits
#include <type_traits>       // std::conditional
#include <utility>           // std::pair std::swap

namespace s21 {

template <typename Key, typename T>
class RBTree {
 protected:
  struct BaseNode;
  struct Node;

  template <bool is_const>
  class BaseTreeIterator;

 public:
  using key_type = Key;
  using value_type = T;
  using iterator = RBTree<Key, T>::BaseTreeIterator<false>;
  using const_iterator = RBTree<Key, T>::BaseTreeIterator<true>;
  using size_type = size_t;

  // Member Functions
  RBTree();
  RBTree(std::initializer_list<Key> const& items);
  RBTree(const RBTree& other);
  RBTree(RBTree&& other);
  ~RBTree();
  RBTree& operator=(RBTree&& other);

  // Iterators
  iterator begin();
  iterator end();

  // Capacity
  bool empty();
  size_t size() const;
  size_t max_size() const;  // ! mb fix

  // Modifiers
  void clear();
  void erase(iterator pos);
  void TestInsert(const key_type& item);
  void swap(RBTree& other);
  void merge(RBTree<Key, T>& other);

  // Lookup
  void PrintTree();
  bool contains(const Key& key) const;

 protected:  // чтоб можно было юзать на наследниках
  struct BaseNode {
    BaseNode* left;
    BaseNode* right;
    BaseNode* parent;
  };
  struct Node : public BaseNode {
    key_type key;
    value_type value;
    bool red;
    bool true_value =
        false;  // * костыль для универсального наследования дерева

    // для set
    Node(key_type key_item, bool is_red);
    // для map
    Node(const key_type& key_item, const value_type& value_item, bool is_red);
  };
  BaseNode root_;  // fake root
  size_t size_;

  void InitNode(Node* orphan, BaseNode* father);
  std::pair<iterator, bool> TreeInsert(
      Node* new_node);  // нужна обертка в контейнерах
  BaseNode* GetExistNode(BaseNode* some_node, const Key& some_key);

 private:
  void RecDelTree(BaseNode*& baby_node);
  void RecursiveInsert(BaseNode* father, Node* new_node, bool finded_leaf,
                       std::pair<RBTree<Key, T>::iterator, bool>& result);
  BaseNode* FindMin(BaseNode* root) const;
  Node* GetTreeCopy(Node* other, BaseNode* parent_node);
  bool RecFind(const Key& key, const BaseNode* some_node) const;
  BaseNode* ReflashNodes(Node* other_node, BaseNode* root,
                         RBTree<Key, T>& other_tree);
  BaseNode* Reflash(Node* other_node, BaseNode* right_branch,
                    RBTree<Key, T>& other_tree);
  Node* RecursiveSearchNearestNode(BaseNode* root, const key_type& item,
                                   bool* left);
  // void LeftRotate();
  // void RightRotate();
  // void FixBalance(Node* current_node);
};

}  // namespace s21

#include "./base_tree_iterator.h"
#include "./rb_tree.tpp"

#endif  // S21_CONTAINERS_COMMON_RB_TREE_H_