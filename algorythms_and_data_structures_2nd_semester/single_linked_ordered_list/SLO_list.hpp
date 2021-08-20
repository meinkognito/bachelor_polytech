#ifndef SLOL_BELOSHITSKIY_DR_SLO_LIST_HPP
#define SLOL_BELOSHITSKIY_DR_SLO_LIST_HPP

#include <ostream>

class SLO_list {
public:
    SLO_list();

    ~SLO_list();

    [[maybe_unused]] [[nodiscard]] int getSize() const;

    SLO_list(const SLO_list &other);

    SLO_list(SLO_list &&other) noexcept;

    bool insert(int item);

    bool searchItem(int item);

    bool deleteItem(int item);

    void mergeLists(SLO_list &other);

    bool deleteSimilarItems(const SLO_list &other);

    void listsIntersection(SLO_list const &other);

    void print() const;

private:
    struct Node {
        int data_;
        Node *next_;

        explicit Node(int data, Node *next = nullptr):
                data_(data),
                next_(next)
        {}
    };

    Node *head_;

    int size_;

    Node *searchNode(int item);

    void clear();

};

#endif //SLOL_BELOSHITSKIY_DR_SLO_LIST_HPP
