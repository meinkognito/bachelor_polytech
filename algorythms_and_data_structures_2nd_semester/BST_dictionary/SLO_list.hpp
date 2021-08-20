#ifndef SLO_LIST_HPP
#define SLO_LIST_HPP

#include <iosfwd>
#include <string>
#include <utility>

class SLO_list
{
public:
  SLO_list();

  ~SLO_list();

  [[nodiscard]] size_t getSize() const;

  bool insert(const std::wstring &item);

  void print(std::wostream &out) const;

private:
  struct Node
  {
    std::wstring data_;
    Node *next_;

    explicit Node(std::wstring data, Node *next = nullptr):
      data_(std::move(data)),
      next_(next)
    {}
  };

  Node *head_;

  size_t size_;
};

#endif //SLO_LIST_HPP
