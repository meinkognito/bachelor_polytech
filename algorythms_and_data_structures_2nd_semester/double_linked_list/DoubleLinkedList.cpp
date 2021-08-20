#include "DoubleLinkedList.h"
//  DoubleLinkedList.cpp - Дважды связный список целых чисел - реализация методов класса
//
#include <iostream>

// Конструктор "по умолчанию" - создание пустого списка - см. Описание класса
// DoubleLinkedList::DoubleLinkedList(): count_(0), head_(nullptr), tail_(nullptr) {  }

// Конструктор "копирования" – создание копии имеющегося списка
// DoubleLinkedList::DoubleLinkedList (const DoubleLinkedList::DoubleLinkedList & src) {}

// Вставить сформированный узел в хвост списка
void DoubleLinkedList::insertTail(Node *x)
{
    x->prev_ = tail_;

    if (head_ != nullptr) {
        tail_->next_ = x;
    } else {
        head_ = x;
    }

    tail_ = x;

    count_++;
}

// Вставить сформированный узел в начало списка
void DoubleLinkedList::insertHead(Node *x)
{   // x->prev_ == nullptr,  x->next_ == nullptr
    x->next_ = head_;
    if (head_ != nullptr) {
        // список был НЕ пуст – новый элемент будет и первым, и последним
        head_->prev_ = x;
    } else {
        // список был пуст – новый элемент будет и первым, и последним
        tail_ = x;
    }
    head_ = x;
    count_++;  // число элементов списка увеличилось
}

// Удаление заданного узла
void DoubleLinkedList::deleteNode(Node *x)
{
    if (x == nullptr) {
        throw ("DoubleLinkedList::deleteNode  - неверно задан адрес удаляемого узла");
    }
    if (x->prev_ != nullptr) {
        // удаляется НЕ голова списка
        (x->prev_)->next_ = x->next_;
    } else {
        // удаляется голова списка,  второй элемент становится первым
        head_ = x->next_;
    }
    if (x->next_ != nullptr) {
        // удаляется НЕ хвост
        (x->next_)->prev_ = x->prev_;
    } else {
        // удаляется хвост
        tail_ = x->prev_;
    }
    delete x;      //
    count_--;     // число элементов списка уменьшилось
}

// Поиск узла (адрес) с заданным значением
DoubleLinkedList::Node *DoubleLinkedList::searchNode(int item)
{
    Node *x = head_;
    while (x != nullptr && x->item_ != item) {
        x = x->next_;
    }
    return x;
}

// Замена информации узла на новое
DoubleLinkedList::Node *DoubleLinkedList::replaceNode(DoubleLinkedList::Node *x, int item)
{
    x->item_ = item;
    return x;
}

// количество элементов списка
//  int DoubleLinkedList::сount()const{ return count_; }

// Доступ к информации головного узла списка
int DoubleLinkedList::headItem() const
{
    if (head_ != nullptr) {
        return head_->item_;
    }
    throw ("headItem - список пуст!");
}

int &DoubleLinkedList::headItem()
{
    if (head_ != nullptr) {
        return head_->item_;
    }
    throw ("headItem - список пуст!");
}

// Доступ к информации хвостового узла списка
int DoubleLinkedList::tailItem() const
{
    if (tail_ != nullptr) {
        return tail_->item_;
    }
    throw ("tailItem - список пуст!");
}

int &DoubleLinkedList::tailItem()
{
    if (tail_ != nullptr) {
        return tail_->item_;
    }
    throw ("tailItem - список пуст!");
}

// Вставить элемент в голову списка
void DoubleLinkedList::insertHead(int item)
{   // создаем новый элемент списка и добавляем в голову
    insertHead(new Node(item));
}

// Вставить элемент в хвост списка
void DoubleLinkedList::insertTail(int item)
{   // создаем новый элемент списка и добавляем в хвост
    insertTail(new Node(item));
}

// Удалить элемент с головы списка
bool DoubleLinkedList::deleteHead()
{
    if (head_ == nullptr) {
        return 0;  // список пуст, удалений нет
    }
    deleteNode(head_);
    return 1;      // список был НЕ пуст, удаление головы
}

// Удалить элемент из хвоста списка
bool DoubleLinkedList::deleteTail()
{
    if (tail_ == nullptr) {
        return false;
    }

    deleteNode(tail_);

    return true;
}

// Удаление узла с заданным значением
bool DoubleLinkedList::deleteItem(const int item, bool all)
{
    Node *node = searchNode(item);

    if (node != nullptr) {
        if (node->next_ != nullptr) {
            node = node->next_;
            deleteNode(node->prev_);
        } else {
            deleteNode(node);
        }
    } else {
        return false;
    }

    while (node != nullptr && all) {
        if (node->item_ == item) {
            if (node->next_ != nullptr) {
                node = node->next_;
                deleteNode(node->prev_);
            } else {
                deleteNode(node);
            }
        } else {
            node = node->next_;
        }
    }
    return true;
}

// Поиск записи с заданным значением
bool DoubleLinkedList::searchItem(int item)
{   // возвращаем TRUE, если узел найден
    return (searchNode(item) != nullptr);
}

// Замена информации узла на новое
bool DoubleLinkedList::replaceItem(int old_item, int new_item, bool all)
{
    Node *node = searchNode(old_item);

    if (node != nullptr) {
        replaceNode(node, new_item);
        node = node->next_;
    } else {
        return false;
    }

    while (node != nullptr && all) {
        if (node->item_ == old_item) {
            replaceNode(node, new_item);
        }
        node = node->next_;

    }
    return true;
}

// Вывод элементов списка в текстовом виде в стандартный выходной поток
void DoubleLinkedList::outAll()
{
    Node *current = head_;       // Указатель на элемент
    while (current != nullptr) {
        std::cout << current->item_ << " ";
        current = current->next_;  // Переход к следующему элементу
    }
    std::cout << std::endl;
}

// Деструктор списка
DoubleLinkedList::~DoubleLinkedList()
{
    Node *current = nullptr;   // указатель на элемент, подлежащий удалению
    Node *next = head_;        // указатель на следующий элемент
    while (next != nullptr) {  // пока есть еще элементы в списке
        current = next;
        next = next->next_;    // переход к следующему элементу
        delete current;        // освобождение памяти
    }
}

// Конструктор копирования списка
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList &src)
{
    Node *temp = src.head_;

    this->head_ = nullptr;
    this->tail_ = nullptr;
    this->count_ = 0;

    while (temp != nullptr) {
        insertTail(temp->item_);
        temp = temp->next_;
    }
}

// Оператор копирующего присваивания
void DoubleLinkedList::swap(DoubleLinkedList &other)
{
    Node *temp_head = other.head_;
    Node *temp_tail = other.tail_;
    int temp_count = other.count_;

    other.head_ = this->head_;
    other.tail_ = this->tail_;
    other.count_ = this->count_;

    this->head_ = temp_head;
    this->tail_ = temp_tail;
    this->count_ = temp_count;
}

DoubleLinkedList::DoubleLinkedList(DoubleLinkedList &&other) noexcept
{
    tail_ = other.tail_;
    head_ = other.head_;
    count_ = other.count_;

    other.tail_ = nullptr;
    other.head_ = nullptr;
    other.count_ = 0;
}

DoubleLinkedList &DoubleLinkedList::operator=(const DoubleLinkedList &other)
{
    if (&other == this) {
        return *this;
    }
    DoubleLinkedList temp = other;
    this->swap(temp);
    return *this;
}

DoubleLinkedList &DoubleLinkedList::operator=(DoubleLinkedList &&other) noexcept
{
    if (&other == this) {
        return *this;
    }

    Node *current = nullptr;
    Node *next = head_;

    while (next != nullptr) {
        current = next;
        next = next->next_;
        delete current;
    }

    tail_ = other.tail_;
    head_ = other.head_;
    count_ = other.count_;

    other.tail_ = nullptr;
    other.head_ = nullptr;
    other.count_ = 0;

    return *this;
}

std::ostream &operator<<(std::ostream &os, const DoubleLinkedList &list)
{
    DoubleLinkedList::Node *node = list.head_;

    while (node != nullptr) {
        os << node->item_ << " ";
        node = node->next_;
    }
    os << std::endl;

    return os;
}

bool DoubleLinkedList::operator==(const DoubleLinkedList &other) const
{
    if (count_ == other.count_) {
        Node *first_list = this->head_;
        Node *second_list = other.head_;

        while (first_list != nullptr) {
            if (first_list->item_ != second_list->item_) {
                return false;
            }

            first_list = first_list->next_;
            second_list = second_list->next_;
        }
        return true;
    } else {
        return false;
    }
}

void DoubleLinkedList::list_push_back(DoubleLinkedList &other)
{
    this->tail_->next_ = other.head_;
    other.head_->prev_ = this->tail_;
    this->tail_ = other.tail_;
    this->count_ += other.count_;

    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.count_ = 0;
}


