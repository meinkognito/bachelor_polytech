#include <iostream>
#include "QueueArray.hpp"
#include "BinarySearchTree.hpp"

int main()
{
  std::cout << "Тест 1. Очередь" << std::endl;
  QueueArray<int> queue(5);

  for (int i = 0; i < 5; ++i)
  {
    queue.enQueue(i);
  }

  queue.deQueue();
  queue.enQueue(21);

  for (int i = 0; i < 5; ++i)
  {
    std::cout << queue.deQueue() << " ";
  }

  std::cout << std::endl;

  std::cout << "Тест 2. Итеративный метод обхода дерева по уровням" << std::endl;
  BinarySearchTree<int> test_tree_1;

  for (int i = 0; i < 50; ++i)
  {
    int a = std::rand() % 25;
    test_tree_1.insert(a);
  }
  test_tree_1.print(std::cout);
  test_tree_1.iterativeInorderWalk([](int x) {
    std::cout << x << " ";
  });

  std::cout << std::endl;

  std::cout << "Тест 3. Итеративный метод обхода дерева слева направо (инфиксный)" << std::endl;
  BinarySearchTree<int> test_tree_2;

  for (int i = 0; i < 50; ++i)
  {
    int a = std::rand() % 25;
    test_tree_2.insert(a);
  }
  test_tree_2.print(std::cout);
  test_tree_2.inorderStackWalk([](int x) {
    std::cout << x << " ";
  });

  std::cout << std::endl;

  std::cout << "Тест 4. Метод обхода в ширину" << std::endl;
  BinarySearchTree<int> test_tree_;

  for (int i = 0; i < 25; ++i)
  {
    int a = std::rand() % 25;
    test_tree_2.insert(a);
  }
  test_tree_2.print(std::cout);
  test_tree_2.bfs([](int x) {
    std::cout << x << " ";
  });

  std::cout << std::endl;

  std::cout << "Тест 5. Сравнение деревьев" << std::endl;

  test_tree_1.inorderStackWalk([](int x) {
    std::cout << x << " ";
  });
  std::cout << std::endl;

  test_tree_2.inorderStackWalk([](int x) {
    std::cout << x << " ";
  });
  std::cout << std::endl;

  if (test_tree_1 == test_tree_2)
  {
    std::cout << "trees are equal" << std::endl;
  }
  else
  {
    std::cout << "trees are not equal" << std::endl;
  }

  BinarySearchTree<int> test_tree_3;
  for (int i = 0; i < 10; ++i)
  {
    test_tree_3.insert(i);
  }

  BinarySearchTree<int> test_tree_4;
  for (int i = 0; i < 10; ++i)
  {
    test_tree_4.insert(i);
  }

  test_tree_3.inorderStackWalk([](int x) {
    std::cout << x << " ";
  });
  std::cout << std::endl;

  test_tree_4.inorderStackWalk([](int x) {
    std::cout << x << " ";
  });
  std::cout << std::endl;

  if (test_tree_3 == test_tree_4)
  {
    std::cout << "trees are equal" << std::endl;
  }
  else
  {
    std::cout << "trees are not equal" << std::endl;
  }

  return 0;
}
