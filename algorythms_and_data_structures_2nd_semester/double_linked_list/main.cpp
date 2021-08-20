//
// Тестовая функция: проверка методов работы со списком
//
#include "DoubleLinkedList.h"
#include <iostream>

int main()
{
    DoubleLinkedList list1;
    list1.insertTail(1);
    list1.insertTail(2);
    list1.insertTail(3);

    DoubleLinkedList list2(list1);
    std::cout << "Проверка работы конструктора копирования на примере list1 и list2" << std::endl;
    list1.outAll();
    list2.outAll();

    DoubleLinkedList list3;
    std::cout << "Проверка работы оператора копирующего присваивания на примере list1 2 и list3" << std::endl;
    list2.outAll();
    list3 = list2;
    list3.outAll();

    DoubleLinkedList list4;
    std::cout << "Проверка работы конструктора перемещения на примере list2 и list4" << std::endl;
    list4.swap(list2);
    list2.outAll(); // list1 2 пуст, т.к. все данные переместились в list4
    list4.outAll();

    DoubleLinkedList list5;
    list5.insertTail(24);
    std::cout << "Проверка работы оператора перемещающего присваивания на примере list2 и list5" << std::endl;
    list5.outAll();
    list2 = std::move(list5); // list1 5 пуст, т.к. все данные переместились в list2

    DoubleLinkedList list6;
    std::cout << "Проверка работы метода insertTail на примере list6" << std::endl;
    list6.outAll();
    list6.insertTail(21);
    list6.insertTail(19);
    list6.insertTail(76);
    list6.outAll();

    std::cout << "Проверка работы метода deleteTail на примере list6" << std::endl;
    list6.outAll();
    list6.deleteTail();
    list6.outAll();

    std::cout << "Проверка работы метода deleteItem на примере list6" << std::endl;
    list6.outAll();
    list6.deleteItem(21);
    list6.outAll();

    std::cout << "Проверка работы метода replaceItem на примере list6" << std::endl;
    list6.outAll();
    list6.replaceItem(19, 45);
    list6.outAll();

    std::cout << "Проверка работы перегруженного оператора вывода на примере list1" << std::endl;
    std::cout << list1;

    std::cout << "Проверка работы перегруженного оператора сравнения на примере list1, list 2 и list4" << std::endl;
    std::cout << (list1 == list2) << std::endl;
    std::cout << (list1 == list4) << std::endl;

    std::cout << "Проверка работы метода для добавления в конец исходного списка элементов"
                 " списка на примере list2 и list6" << std::endl;
    list2.outAll();
    list2.list_push_back(list6);
    list2.outAll();

    return 0;
}