#include "SLO_list.hpp"
#include <ostream>

SLO_list::SLO_list()
{
  head_ = nullptr;
  size_ = 0;
}

SLO_list::~SLO_list()
{
  Node *current = head_;
  Node *temp;
  while (current != nullptr)
  {
    temp = current->next_;
    delete current;
    current = temp;
  }
}

size_t SLO_list::getSize() const
{
  return size_;
}

bool SLO_list::insert(const std::wstring &item)
{
  Node *current = head_;
  Node *previous = head_;

  if (current == nullptr)
  {
    head_ = new Node(item);
    size_++;
    return true;
  }
  else
  {
    if (current->data_ > item)
    {
      Node *temp = new Node(item);
      temp->next_ = head_;
      head_ = temp;
      size_++;
      return true;
    }

    current = current->next_;

    while (current != nullptr)
    {
      if (current->data_ > item && previous->data_ < item)
      {
        Node *temp = new Node(item, current);
        previous->next_ = temp;
        size_++;
        return true;
      }
      else
      {
        previous = previous->next_;
        current = current->next_;
      }
    }

    if (previous->data_ < item)
    {
      Node *temp = new Node(item, current);
      previous->next_ = temp;
      size_++;
      return true;
    }
    else
    {
      return false;
    }
  }
}

void SLO_list::print(std::wostream &out) const
{
  Node *temp = head_;
  int counter = 0;
  while (temp != nullptr)
  {
    out << temp->data_;
    temp = temp->next_;
    if (this->getSize() != 1 && counter != getSize() - 1)
    {
      out << ", ";
      counter++;
    }
    else
    {
      out << " ";
    }
  }
  out << '\n';
}
