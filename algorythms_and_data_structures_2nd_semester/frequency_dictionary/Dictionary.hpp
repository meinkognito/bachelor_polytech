#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <memory>

#include "SLO_list.hpp"

class Dictionary
{
public:
  Dictionary();

  Dictionary(const Dictionary &scr) = delete;

  Dictionary(Dictionary &&scr) noexcept;

  ~Dictionary();

  void find(const std::wstring &key, std::wostream &out = std::wcout) const;

  bool insert(const std::wstring &key, const std::wstring &translation);

  bool remove(const std::wstring &key);

  void print(std::wostream &out) const;

private:
  struct Node
  {
    std::wstring word_;
    std::shared_ptr<SLO_list> translation_;
    Node *left_;
    Node *right_;
    Node *p_;

    explicit Node(std::wstring word, const std::wstring &translation, Node *left = nullptr,
                  Node *right = nullptr, Node *p = nullptr):
      word_(std::move(word)),
      translation_(std::make_shared<SLO_list>()),
      left_(left),
      right_(right),
      p_(p)
    {
      (*translation_).insert(translation);
    }
  };

  Node *root_;

  void swap(Dictionary &left, Dictionary &right);

  void deleteSubtree(Node *node);

  Node *iterativeSearchNode(const std::wstring &key) const;

  void printNode(Node *node, std::wostream &out) const;

};

#endif //DICTIONARY_HPP
