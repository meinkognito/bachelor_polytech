#include "Dictionary.hpp"

Dictionary::Dictionary():
  root_(nullptr)
{}

Dictionary::Dictionary(Dictionary &&scr) noexcept
{
  swap(*this, scr);
  scr.root_ = nullptr;
}

Dictionary::~Dictionary()
{
  deleteSubtree(this->root_);
}

void Dictionary::find(const std::wstring &key, std::wostream &out) const
{
  Node *translation = iterativeSearchNode(key);

  printNode(translation, out);
}

bool Dictionary::insert(const std::wstring &key, const std::wstring &translation)
{
  Node *current = root_;
  Node *parent = nullptr;

  while (current != nullptr)
  {
    if (current->word_ == key)
    {
      (*current->translation_).insert(translation);
      break;
    }
    parent = current;
    if (current->word_ < key)
    {
      current = current->right_;
      if (current == nullptr)
      {
        current = new Node(key, translation);
        (*current->translation_).insert(translation);
        current->p_ = parent;
        parent->right_ = current;
        break;
      }
    }
    else if (current->word_ > key)
    {
      current = current->left_;
      if (current == nullptr)
      {
        current = new Node(key, translation);
        (*current->translation_).insert(translation);
        current->p_ = parent;
        parent->left_ = current;
        break;
      }
    }
  }
  if (root_ == nullptr)
  {
    root_ = new Node(key, translation);
    (*root_->translation_).insert(translation);
  }

  return true;
}

bool Dictionary::remove(const std::wstring &key)
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
      temp->word_ = current->word_;
      temp->translation_ = current->translation_;
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
      temp->word_ = current->word_;
      temp->translation_ = current->translation_;
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

void Dictionary::print(std::wostream &out) const
{
  printNode(root_, std::wcout);
  out.clear();
}

void Dictionary::swap(Dictionary &left, Dictionary &right)
{
  std::swap(left.root_, right.root_);
}

void Dictionary::deleteSubtree(Dictionary::Node *node)
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

typename Dictionary::Node *Dictionary::iterativeSearchNode(const std::wstring &key) const
{
  Node *current = root_;
  while (current != nullptr)
  {
    if (current->word_ < key)
    {
      current = current->right_;
    }
    else if (current->word_ > key)
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

void Dictionary::printNode(Dictionary::Node *node, std::wostream &out) const
{
  if (node != nullptr)
  {
    std::wcout << L"Слово " << std::quoted(node->word_) << L" переводится как: ";
    node->translation_->print(std::wcout);
    printNode(node->left_, std::wcout);
    printNode(node->right_, std::wcout);
  }
}
