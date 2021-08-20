#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include <iostream>
#include <vector>

template<class T>
class BinarySearchTree
{
public:
  BinarySearchTree();

  BinarySearchTree(const BinarySearchTree<T> &scr) = delete;

  BinarySearchTree(BinarySearchTree<T> &&scr) noexcept;

  ~BinarySearchTree();

  bool iterativeSearch(const T &key) const;

  bool insert(const T &key);

  bool deleteKey(const T &key);

  void print(std::ostream &out) const;

  int getCount() const;

  int getHeight() const;

  void iterativeInorderWalk(void (*visit)(T)) const; // итеративный обход

  void inorderWalk(void (*visit)(T)) const; // рекурсивный обход

  bool operator==(const BinarySearchTree<T> &src);

private:
  struct Node
  {
    T key_;
    Node *left_;
    Node *right_;
    Node *p_;

    explicit Node(T key, Node *left = nullptr, Node *right = nullptr, Node *p = nullptr):
      key_(key),
      left_(left),
      right_(right),
      p_(p)
    {}
  };

  Node *root_;

  void swap(BinarySearchTree<T> &left, BinarySearchTree<T> &right);

  void deleteSubtree(Node *node);

  Node *iterativeSearchNode(const T &key) const;

  void printNode(std::ostream &out, Node *root) const;

  int getCountSubTree(const Node *node) const;

  int getHeightSubTree(Node *node) const;
};

template<class T>
BinarySearchTree<T>::BinarySearchTree():
  root_(nullptr)
{}

template<class T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T> &&scr) noexcept
{
  swap(*this, scr);
  scr.root_ = nullptr;
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
  deleteSubtree(this->root_);
}

template<class T>
bool BinarySearchTree<T>::iterativeSearch(const T &key) const
{
  return (iterativeSearchNode(key) != nullptr);
}

template<class T>
bool BinarySearchTree<T>::insert(const T &key)
{
  Node *current = root_;
  Node *parent = nullptr;
  while (current != nullptr)
  {
    parent = current;
    if (key > current->key_)
    {
      current = current->right_;
      if (current == nullptr)
      {
        current = new Node(key);
        current->p_ = parent;
        parent->right_ = current;
        break;
      }
    }
    else if (current->key_ > key)
    {
      current = current->left_;
      if (current == nullptr)
      {
        current = new Node(key);
        current->p_ = parent;
        parent->left_ = current;
        break;
      }
    }
    else
    {
      return false;
    }
  }

  if (root_ == nullptr)
  {
    current = new Node(key);
    root_ = current;
  }

  return true;
}

template<class T>
bool BinarySearchTree<T>::deleteKey(const T &key)
{
  Node *current = iterativeSearchNode(key);
  if (current == nullptr)
  {
    return false;
  }
  else if ((current == root_) && (current->left_ == nullptr) && (current->right_ == nullptr))
  {
    delete root_;
    root_ = nullptr;
    return true;
  }

  if (current->right_ && current->left_)
  {
    Node *temp = current;
    current = current->right_;

    if (current->left_)
    {
      while (current->left_)
      {
        current = current->left_;
      }

      temp->key_ = current->key_;
      if (current->right_ != nullptr)
      {
        Node *to_delete = current;
        current = current->p_;
        current->left_ = to_delete->right_;
        to_delete->right_->p_ = current;
        delete to_delete;
        return true;
      }

      current = current->p_;
      delete current->left_;
      current->left_ = nullptr;
      return true;
    }
    else
    {
      temp->key_ = current->key_;
      Node *to_delete = temp->right_;
      if (temp->right_)
      {
        temp->right_ = temp->right_->right_;
        if (temp->right_)
        {
          temp->right_->p_ = temp;
        }
      }
      delete to_delete;
      return true;
    }
  }
  else if (current->right_)
  {
    Node *parent_ptr = current->p_;
    if (current != root_)
    {
      if (parent_ptr->right_ == current)
      {
        parent_ptr->right_ = current->right_;
        current->right_->p_ = parent_ptr;
      }
      else if (parent_ptr->left_ == current)
      {
        parent_ptr->left_ = current->right_;
        current->right_->p_ = parent_ptr;
      }
    }
    else
    {
      root_ = current->right_;
      root_->p_ = parent_ptr;
    }
    delete current;
    return true;
  }
  else if (current->left_)
  {
    Node *parent_ptr = current->p_;
    if (current != root_)
    {
      if (parent_ptr->right_ == current)
      {
        parent_ptr->right_ = current->left_;
        current->left_->p_ = parent_ptr;
      }
      else if (parent_ptr->left_ == current)
      {
        parent_ptr->left_ = current->left_;
        current->left_->p_ = parent_ptr;
      }
    }
    else
    {
      root_ = current->left_;
      root_->p_ = parent_ptr;
    }
    delete current;
    return true;
  }
  else
  {
    Node *parent_ptr = current->p_;
    if (current != root_)
    {
      if (parent_ptr->right_ == current)
      {
        parent_ptr->right_ = current->left_;
      }
      else if (parent_ptr->left_ == current)
      {
        parent_ptr->left_ = current->left_;
      }
    }
    delete current;
    current = nullptr;
    return true;
  }
}

template<class T>
void BinarySearchTree<T>::print(std::ostream &out) const
{
  printNode(out, root_);
  out << std::endl;
}

template<class T>
int BinarySearchTree<T>::getCount() const
{
  return getCountSubTree(this->root_);
}

template<class T>
int BinarySearchTree<T>::getHeight() const
{
  return getHeightSubTree(this->root_);
}

template<class T>
bool BinarySearchTree<T>::operator==(const BinarySearchTree<T> &src)
{
  std::vector<T> v;
  inorderWalk(&std::vector<T>::push_back, v);
  for (size_t i = 0; i < v.size(); ++i)
  {
    if (!src.iterativeSearch(v[i]))
    {
      return false;
    }
  }
  return true;
}

template<class T>
void BinarySearchTree<T>::swap(BinarySearchTree<T> &left, BinarySearchTree<T> &right)
{
  std::swap(left.root_, right.root_);
}

template<class T>
void BinarySearchTree<T>::deleteSubtree(BinarySearchTree::Node *node)
{
  if (node != nullptr)
  {
    if (node->right_ != nullptr)
    {
      deleteSubtree(node->right_);
    }
    if (node->left_ != nullptr)
    {
      deleteSubtree(node->left_);
    }
    delete node;
  }
}

template<class T>
typename BinarySearchTree<T>::Node *BinarySearchTree<T>::iterativeSearchNode(const T &key) const
{
  Node *current = root_;
  while (current != nullptr)
  {
    if (current->key_ < key)
    {
      current = current->right_;
    }
    else if (current->key_ > key)
    {
      current = current->left_;
    }
    else
    {
      return current;
    }
  }
  return current;
}

template<class T>
void BinarySearchTree<T>::printNode(std::ostream &out, BinarySearchTree::Node *root) const
{
  out << '(';
  if (root != nullptr)
  {
    out << root->key_;
    printNode(out, root->left_);
    printNode(out, root->right_);
  }
  out << ')';
}

template<class T>
int BinarySearchTree<T>::getCountSubTree(const BinarySearchTree::Node *node) const
{
  if (node == nullptr)
  {
    return 0;
  }
  return (1 + getCountSubTree(node->left_) + getCountSubTree(node->right_));
}

template<class T>
int BinarySearchTree<T>::getHeightSubTree(BinarySearchTree::Node *node) const
{
  int temp, temp_right;
  if (node->left_ != nullptr)
  {
    temp = 1 + getHeightSubTree(node->left_);
  }
  else
  {
    temp = 1;
  }
  if (node->right_ != nullptr)
  {
    temp_right = 1 + getHeightSubTree(node->right_);
  }
  else
  {
    temp_right = 1;
  }
  return std::max(temp, temp_right);
}

template<class T>
void BinarySearchTree<T>::iterativeInorderWalk(void (*visit)(T)) const
{
  T previous;
  Node *max = root_;
  Node *min = root_;
  while (max->right_ != nullptr)
  {
    max = max->right_;
  }
  while (min->left_ != nullptr)
  {
    min = min->left_;
  }
  previous = min->key_;
  Node *current = min;
  visit(previous);
  while (previous != max->key_)
  {
    while ((current->left_ != nullptr) && (current->left_->key_ > previous))
    {
      current = current->left_;
    }
    if ((current->left_ != nullptr) && (current->left_->key_ < previous) && (previous != current->key_))
    {
      if (current->left_->key_ < previous && previous != current->key_)
      {
        if (previous != current->key_)
        {
          visit(current->key_);
          previous = current->key_;
        }
      }
    }
    else
    {
      if (current->right_ != nullptr)
      {
        if (previous != current->key_)
        {
          visit(current->key_);
          previous = current->key_;
        }
        current = current->right_;
      }
      else
      {
        if (previous != current->key_)
        {
          visit(current->key_);
          previous = current->key_;
        }
        while (current->key_ <= previous && previous != max->key_)
        {
          current = current->p_;
        }
      }
    }
  }
}

template<class T>
void BinarySearchTree<T>::inorderWalk(void (*visit)(T)) const
{
  return inorderWalkNode(this->root_, visit);
}

#endif //BINARYSEARCHTREE_HPP
