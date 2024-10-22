#ifndef S21_CONTAINERS_COMMON_RBTREE_TPP_
#define S21_CONTAINERS_COMMON_RBTREE_TPP_

namespace s21 {

/*==============================================
=               Helpful methods                =
==============================================*/
template <typename Key, typename T>
void RBTree<Key, T>::InitNode(Node* orphan, BaseNode* father) {
  orphan->left = nullptr;
  orphan->right = nullptr;
  orphan->parent = father;
}

template <typename Key, typename T>
std::pair<typename RBTree<Key, T>::iterator, bool> RBTree<Key, T>::TreeInsert(
    Node* new_node) {
  std::pair<iterator, bool> result{nullptr, false};

  if (empty()) {
    InitNode(new_node, &root_);
    root_.left = new_node;
    result = {iterator{new_node}, true};
  } else {
    bool finded_leaf = false;
    RecursiveInsert(root_.left, new_node, finded_leaf, result);
  }

  if (result.second == true) {
    ++size_;
    // FixBalance();
  }

  return result;
}

template <typename Key, typename T>
typename RBTree<Key, T>::BaseNode* RBTree<Key, T>::GetExistNode(
    BaseNode* some_node, const Key& some_key) {
  BaseNode* result = nullptr;

  Node* exist_node = static_cast<Node*>(some_node);
  if (some_key < exist_node->key) {
    result = GetExistNode(some_node->left, some_key);
  } else if (some_key > exist_node->key) {
    result = GetExistNode(some_node->right, some_key);
  } else {
    result = some_node;
  }

  return result;
}

/*
 * Когда мы передаем параметр в функцию по указателю (BaseNode* baby_node),
 * мы передаем адрес объекта, на который указывает указатель.
 * Это позволяет изменять данные объекта, на который указывает указатель,
 * но сама переменная-указатель (то есть адрес, который она содержит)
 * остается неизменной относительно области видимости,
 * из которой была сделана передача.
 * Другими словами, мы можем изменить состояние объекта,
 * но не саму переменную-указатель.
 *
 * Когда же мы передаем параметр в функцию
 * по ссылке на указатель (BaseNode*& baby_node),
 * мы фактически передаем ссылку на саму переменную-указатель.
 * Это означает, что функция может изменять как данные объекта,
 * на который указывает указатель, так и саму переменную-указатель.
 * То есть, функция может изменить адрес,
 * который содержит переменная-указатель
 */
template <typename Key, typename T>
void RBTree<Key, T>::RecDelTree(BaseNode*& baby_node) {
  if (baby_node != nullptr) {
    if (baby_node->left) RecDelTree(baby_node->left);

    if (baby_node->right) RecDelTree(baby_node->right);

    delete baby_node;
    baby_node = nullptr;
  } else
    return;
}

template <typename Key, typename T>
void RBTree<Key, T>::RecursiveInsert(
    BaseNode* father, Node* new_node, bool finded_leaf,
    std::pair<RBTree<Key, T>::iterator, bool>& result) {
  if (!finded_leaf) {
    // * Гарантируется, что parent -- нода, а не фейк
    Node* true_node = static_cast<Node*>(father);

    if (new_node->key < true_node->key) {
      if (true_node->left) {
        RecursiveInsert(true_node->left, new_node, finded_leaf, result);
      } else {
        finded_leaf = true;
        InitNode(new_node, true_node);
        true_node->left = new_node;
        result = {iterator{new_node}, true};
      }
    } else if (new_node->key > true_node->key) {
      if (true_node->right) {
        RecursiveInsert(true_node->right, new_node, finded_leaf, result);
      } else {
        finded_leaf = true;
        InitNode(new_node, true_node);
        true_node->right = new_node;
        result = {iterator{new_node}, true};
      }
    } else {  // ! для мультисета надо реворкнуть
      finded_leaf = true;
      result = {iterator{true_node}, false};
    }
  }
}

template <typename Key, typename T>
typename RBTree<Key, T>::BaseNode* RBTree<Key, T>::FindMin(
    BaseNode* root) const {
  return (root->left != nullptr ? FindMin(root->left) : root);
}

template <typename Key, typename T>
typename RBTree<Key, T>::Node* RBTree<Key, T>::GetTreeCopy(
    Node* other, BaseNode* parent_node) {
  if (!other) return nullptr;

  Node* branch = nullptr;
  if (other->true_value) {
    branch = new Node{other->key, other->value, other->red};
  } else {
    branch = new Node{other->key, other->red};
  }

  branch->parent = parent_node;
  branch->left = GetTreeCopy(static_cast<Node*>(other->left), branch);
  branch->right = GetTreeCopy(static_cast<Node*>(other->right), branch);

  return branch;
}

template <typename Key, typename T>
bool RBTree<Key, T>::RecFind(const Key& key, const BaseNode* some_node) const {
  bool result = false;
  const Node* value_node = static_cast<const Node*>(some_node);

  if (key == value_node->key) {
    result = true;
  } else if (key < value_node->key && value_node->left) {
    result = RecFind(key, value_node->left);
  } else if (key > value_node->key && value_node->right) {
    result = RecFind(key, value_node->right);
  }

  return result;
}

template <typename Key, typename T>
typename RBTree<Key, T>::BaseNode* RBTree<Key, T>::ReflashNodes(
    Node* other_node, BaseNode* root, RBTree<Key, T>& other_tree) {
  BaseNode* result = nullptr;

  // обработка правой ветви
  BaseNode* right_branch = (other_node->right ? other_node->right : nullptr);
  if (right_branch) {
    Node* right_min_node = static_cast<Node*>(FindMin(right_branch));
    // можно, тк дочерние ноды привязаны к родительской (но это не транзитивно)
    result = ReflashNodes(right_min_node, other_node, other_tree);
    other_node->right = result;
  }

  // Обработка листа
  if (other_node == root->left || other_node == root->right) {
    result = Reflash(other_node, result, other_tree);
  } else {
    Node* father = static_cast<Node*>(other_node->parent);
    father->left = Reflash(other_node, result, other_tree);
    result = ReflashNodes(father, root, other_tree);
  }
  return result;
}

template <typename Key, typename T>
typename RBTree<Key, T>::BaseNode* RBTree<Key, T>::Reflash(
    Node* other_node, BaseNode* right_branch, RBTree<Key, T>& other_tree) {
  BaseNode* result = other_node;  // ! check slicing

  if (!contains(other_node->key)) {
    // Обработка другого дерева
    --other_tree.size_;

    // Обработка текущего дерева
    bool left;  // left - 1, right - 0
    Node* finded_node =
        RecursiveSearchNearestNode(root_.left, other_node->key, &left);

    if (left) {
      finded_node->left = other_node;
    } else {
      finded_node->right = other_node;
    }

    other_node->parent = finded_node;
    ++size_;

    result = right_branch;
  }
  return result;
}

// * только для уникальных ключей
template <typename Key, typename T>
typename RBTree<Key, T>::Node* RBTree<Key, T>::RecursiveSearchNearestNode(
    BaseNode* root, const key_type& item, bool* left) {
  Node* result;  // ? mb rework (memory)
  Node* true_root = static_cast<Node*>(root);

  if (item < true_root->key) {
    if (root->left) {
      result = RecursiveSearchNearestNode(root->left, item, left);
    } else {
      *left = true;
      result = true_root;  // дублирование оправдано всратой логикой работы
    }
  } else {
    if (root->right) {
      result = RecursiveSearchNearestNode(root->right, item, left);
    } else {
      *left = false;
      result = true_root;
    }
  }

  return result;
}

/*==============================================
=              Tree constructors               =
==============================================*/
template <typename Key, typename T>
RBTree<Key, T>::RBTree() : root_{nullptr, nullptr, &root_}, size_(0) {}

template <typename Key, typename T>
RBTree<Key, T>::RBTree(std::initializer_list<Key> const& items) : RBTree() {
  auto it = items.begin();
  for (size_t i = 0; i < items.size(); ++i, ++it) {
    if (!contains(*it)) {
      Node* new_node = new Node{*it, true};
      TreeInsert(new_node);
    }
  }
}

template <typename Key, typename T>
RBTree<Key, T>::RBTree(const RBTree& other) : size_(other.size_) {
  Node* other_true_root = static_cast<Node*>(other.root_.left);
  root_.left = GetTreeCopy(other_true_root, &root_);
  root_.right = nullptr;
  root_.parent = &root_;
}

template <typename Key, typename T>
RBTree<Key, T>::RBTree(RBTree&& other) : RBTree() {
  swap(other);
}

template <typename Key, typename T>
RBTree<Key, T>::~RBTree() {
  RecDelTree(root_.left);
}

template <typename Key, typename T>
RBTree<Key, T>& RBTree<Key, T>::operator=(RBTree&& other) {
  if (this != &other) {
    RBTree tmp;
    tmp.swap(other);
    swap(tmp);
  }
  return *this;
}

/*==============================================
=              Node constructors               =
==============================================*/
template <typename Key, typename T>
RBTree<Key, T>::Node::Node(key_type key_item, bool is_red)
    : key(key_item), red(is_red) {}  // для set

template <typename Key, typename T>
RBTree<Key, T>::Node::Node(const key_type& key_item,
                           const value_type& value_item, bool is_red)
    : key(key_item),
      value(value_item),
      red(is_red),
      true_value(true) {}  // для map

/*==============================================
=                Tree Iterators                =
==============================================*/
template <typename Key, typename T>
typename RBTree<Key, T>::iterator RBTree<Key, T>::begin() {
  return iterator{FindMin(&root_)};
}

template <typename Key, typename T>
typename RBTree<Key, T>::iterator RBTree<Key, T>::end() {
  return iterator{&root_};
}

/*==============================================
=                Tree Capacity                 =
==============================================*/
template <typename Key, typename T>
bool RBTree<Key, T>::empty() {
  return (begin() == end());
}

template <typename Key, typename T>
size_t RBTree<Key, T>::size() const {
  return size_;
}

template <typename Key, typename T>
size_t RBTree<Key, T>::max_size() const {
  return std::numeric_limits<size_t>::max() / sizeof(RBTree<Key, T>);
}

/*==============================================
=                 Tree Modifiers               =
==============================================*/
template <typename Key, typename T>
void RBTree<Key, T>::clear() {
  RecDelTree(root_.left);
  size_ = 0;
}

template <typename Key, typename T>
void RBTree<Key, T>::erase(iterator pos) {
  if (pos != end()) {
    BaseNode* dead_node = pos.node_ptr_;

    BaseNode* father = dead_node->parent;
    bool right_or_left_child = false;  // 0 -- right, 1 - left
    if (dead_node == father->left) right_or_left_child = true;

    // Если нода - лист
    if (!dead_node->left && !dead_node->right) {
      if (right_or_left_child)
        father->left = nullptr;
      else
        father->right = nullptr;

    } else {  // Если нода - ветвь
      BaseNode* left_orphan = pos.node_ptr_->left;
      BaseNode* right_orphan = pos.node_ptr_->right;

      if (right_orphan) {  // по дефолту, правый сирота -- наследник убитого
                           // отца в иерархии дерева
        if (right_or_left_child)
          father->left = right_orphan;  //
        else
          father->right = right_orphan;

        // самая маленькая нода правой сироты априори больше левого сироты
        BaseNode* min_right_orphan_node = FindMin(right_orphan);
        min_right_orphan_node->left = left_orphan;

      } else {  // если правой ветви нет
        if (right_or_left_child)
          father->left = left_orphan;
        else
          father->right = left_orphan;
      }
    }

    delete dead_node;
    --size_;

    // балансировка, если хватит времени (мб реворкнуть)
    // while (!CheckBalance()) { FixBalance(); }
  }
}

template <typename Key, typename T>
void RBTree<Key, T>::TestInsert(const key_type& item) {
  Node* new_node = new Node{item, true};
  std::pair<typename RBTree<Key, T>::iterator, bool> result =
      TreeInsert(new_node);

  if (!result.second) {
    delete new_node;
  }
}

template <typename Key, typename T>
void RBTree<Key, T>::swap(RBTree& other) {
  std::swap(size_, other.size_);
  std::swap(root_.left, other.root_.left);
}

template <typename Key, typename T>
void RBTree<Key, T>::merge(RBTree<Key, T>& other) {
  if (other.empty()) {
    return;
  }

  if (empty()) {
    swap(other);
  } else {
    Node* other_min_node = static_cast<Node*>(other.begin().node_ptr_);
    other.root_.left = ReflashNodes(other_min_node, &other.root_, other);
  }
}

/*==============================================
=                     Lookup                   =
==============================================*/
template <typename Key, typename T>
void RBTree<Key, T>::PrintTree() {
  std::cout << "\t\t\tfake_node\n"
            << "\t\t\t|\n";

  if (!empty()) {
    Node* true_node = static_cast<Node*>(root_.left);

    // 1ый уровень
    Node* left_node = static_cast<Node*>(true_node->left);
    Node* right_node = static_cast<Node*>(true_node->right);
    bool right_node_exist = (right_node ? true : false);

    // 2ой уровень
    Node* left_left_node = static_cast<Node*>(left_node->left);
    Node* left_right_node = static_cast<Node*>(left_node->right);
    Node* right_left_node = nullptr;
    Node* right_right_node = nullptr;
    if (right_node_exist) {
      right_left_node = static_cast<Node*>(right_node->left);  // sega
      right_right_node = static_cast<Node*>(right_node->right);
    }

    std::cout << "\t\t\t" << true_node->key << " " << true_node->red << "\n";
    std::cout << "\t\t/\t\t\\\n";

    if (true_node->left != nullptr) {
      std::cout << "\t\t" << left_node->key << " " << left_node->red << "\t\t";
    } else {
      std::cout << "\t\tnill\t\t";
    }

    if (true_node->right != nullptr) {
      std::cout << "  " << right_node->key << " " << right_node->red << "\n";
    } else {
      std::cout << "nill\t\t";
    }

    std::cout << "\t/\t\\"
              << "\t\t/\t\\\n";

    if (left_left_node != nullptr) {
      std::cout << "\t" << left_left_node->key << " " << left_left_node->red;
    } else {
      std::cout << "\tnill";
    }
    if (left_right_node != nullptr) {
      std::cout << "\t" << left_right_node->key << " " << left_right_node->red
                << "\t\t";
    } else {
      std::cout << "\tnill\t\t";
    }

    if (right_node_exist) {
      if (right_left_node != nullptr) {
        std::cout << right_left_node->key << " " << right_left_node->red
                  << "\t";
      } else {
        std::cout << "nill\t";
      }
      if (right_right_node != nullptr) {
        std::cout << right_right_node->key << " " << right_right_node->red;
      } else {
        std::cout << "nill";
      }
    }

  } else {
    std::cout << "\t\t\tnill\n";
  }
}

template <typename Key, typename T>
bool RBTree<Key, T>::contains(const Key& key) const {
  bool result = false;
  if (root_.left) {
    result = RecFind(key, root_.left);
  }

  return result;
}

}  // namespace s21

#endif  // S21_CONTAINERS_COMMON_RBTREE_TPP_