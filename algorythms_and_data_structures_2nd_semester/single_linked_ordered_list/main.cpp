#include <iostream>
#include "SLO_list.hpp"

int main()
{
    SLO_list x;
    x.insert(7);
    x.insert(5);
    x.insert(2);
    x.print();
    x.deleteItem(7);
    x.print();
    x.searchItem(4) ? std::cout << "was founded" << std::endl : std::cout << "was not founded" << std::endl;

    SLO_list y;
    y.insert(10);
    y.insert(1);
    y.insert(7);
    x.mergeLists(y);
    x.print();

    SLO_list z;
    z.insert(5);
    z.insert(3);
    z.insert(48);
    x.deleteSimilarItems(z);
    x.print();

    y.insert(48);
    y.insert(3);
    z.listsIntersection(y);
    z.print();

    return 0;
}
