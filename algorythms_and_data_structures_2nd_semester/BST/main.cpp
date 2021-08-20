#include <iostream>
#include "BinarySearchTree.hpp"

int main()
{
  std::cout << "Тест 1. Проверка работы базовых методов дерева" << std::endl;
  BinarySearchTree<int> test_tree_1;

  test_tree_1.insert(21);
  test_tree_1.insert(53);
  test_tree_1.insert(9);

  std::cout << test_tree_1.getCount() << std::endl;
  test_tree_1.print(std::cout);
  std::cout << std::endl;

  test_tree_1.deleteKey(53);
  std::cout << test_tree_1.getCount() << std::endl;
  test_tree_1.print(std::cout);
  std::cout << std::endl;

  std::cout << test_tree_1.getHeight() << std::endl;

  std::cout << "Тест 2. Итеративный метод обхода дерева по уровням" << std::endl;
  BinarySearchTree<int> test_tree_2;

  for (int i = 0; i < 50; ++i)
  {
    int a = std::rand() % 25;
    test_tree_2.insert(a);
  }
  test_tree_2.print(std::cout);
  test_tree_2.iterativeInorderWalk([](int x) {
    std::cout << x << " ";
  });

  return 0;
}
