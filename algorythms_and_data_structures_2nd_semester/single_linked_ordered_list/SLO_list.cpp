#include <iostream>
#include "SLO_list.hpp"

SLO_list::SLO_list()
{
    head_ = nullptr;
    size_ = 0;
}

SLO_list::~SLO_list()
{
    Node *current = head_;
    Node *temp;
    while (current != nullptr) {
        temp = current->next_;
        delete current;
        current = temp;
    }
}

[[maybe_unused]] int SLO_list::getSize() const
{
    return size_;
}

SLO_list::SLO_list(const SLO_list &other)
{
    Node *current = other.head_;
    Node *temp;
    size_ = 0;
    if (current != nullptr) {
        Node *thisItem = new Node(current->data_);
        head_ = thisItem;
        current = current->next_;
        while (current) {
            temp = new Node(current->data_);
            thisItem->next_ = temp;
            current = current->next_;
            thisItem = thisItem->next_;
            size_++;
        }
    }
}

SLO_list::SLO_list(SLO_list &&other) noexcept
{
    std::swap(head_, other.head_);
    std::swap(size_, other.size_);
    other.head_ = nullptr;
    other.size_ = 0;
}

bool SLO_list::insert(int item)
{
    Node *current = head_;
    Node *previous = head_;

    if (current == nullptr) {
        head_ = new Node(item);
        size_++;
        return true;
    } else {
        if (current->data_ > item) {
            Node *temp = new Node(item);
            temp->next_ = head_;
            head_ = temp;
            size_++;
            return true;
        }

        current = current->next_;

        while (current != nullptr) {
            if (current->data_ > item && previous->data_ < item) {
                Node *temp = new Node(item, current);
                previous->next_ = temp;
                size_++;
                return true;
            } else {
                previous = previous->next_;
                current = current->next_;
            }
        }

        if (previous->data_ < item) {
            Node *temp = new Node(item, current);
            previous->next_ = temp;
            size_++;
            return true;
        } else {
            return false;
        }
    }
}

bool SLO_list::searchItem(int item)
{
    return searchNode(item);
}

bool SLO_list::deleteItem(int item)
{
    Node *current = head_;
    Node *previous = head_;

    if (!searchItem(item)) {
        return false;
    } else if (item == current->data_) {
        head_ = current->next_;
        delete current;
        size_--;
        return true;
    } else {
        current = current->next_;
        while (current != nullptr) {
            if (current->data_ == item) {
                previous->next_ = current->next_;
                delete current;
                size_--;
                return true;
            } else {
                current = current->next_;
                previous = previous->next_;
            }
        }
    }
    return false;
}

void SLO_list::mergeLists(SLO_list &other)
{
    Node *current = head_;
    Node *previous = nullptr;
    Node *other_current = other.head_;

    if (other_current != nullptr) {
        if (other_current->data_ < current->data_) {
            head_ = other.head_;
            other_current = other_current->next_;
            Node *temp_head = head_;
            while (other_current->data_ < current->data_) {
                temp_head->next_ = other_current;
                temp_head = temp_head->next_;
                other_current = other_current->next_;
                if (other_current == nullptr) {
                    break;
                }
            }
            temp_head->next_ = current;
        }

        if (current->next_ != nullptr) {
            previous = current;
            current = current->next_;
        }

        while (other_current != nullptr && current->next_ != nullptr) {
            if ((current->data_ > other_current->data_) && (other_current->data_ > previous->data_)) {
                previous->next_ = other_current;
                other_current = other_current->next_;
                previous->next_->next_ = current;
                previous = previous->next_;
            } else if (current->data_ < other_current->data_) {
                previous = current;
                current = current->next_;
            } else if (current->data_ == other_current->data_) {
                Node *temp = other_current->next_;
                delete other_current;
                other_current = temp;
            } else {
                other_current = other_current->next_;
            }
        }

        while (other_current != nullptr) {
            current->next_ = other_current;
            current = current->next_;
            other_current = other_current->next_;
        }
        other.head_ = nullptr;
    }
}

bool SLO_list::deleteSimilarItems(const SLO_list &other)
{
    Node *current = head_;
    Node *other_current = other.head_;
    Node *previous;

    if (current != nullptr) {
        while (current->data_ > other_current->data_) {
            other_current = other_current->next_;
            if (other_current == nullptr) {
                break;
            }
        }
        if (other_current != nullptr) {
            while (current->data_ == other_current->data_) {
                Node *temp = current;
                current = current->next_;
                other_current = other_current->next_;
                if ((other_current == nullptr) || (current == nullptr)) {
                    break;
                }
                size_--;
                delete temp;
            }
        }

        previous = current;
        head_ = current;

        if (other_current != nullptr && current != nullptr) {
            current = current->next_;
            while (current != nullptr && other_current != nullptr) {
                if (other_current->data_ < current->data_) {
                    other_current = other_current->next_;
                } else if (other_current->data_ > current->data_) {
                    previous = current;
                    current = current->next_;
                } else {
                    Node *temp = current;
                    previous->next_ = current->next_;
                    previous = previous;
                    current = current->next_;
                    other_current = other_current->next_;
                    size_--;
                    delete temp;
                }
            }
        }
    }
    return true;
}

void SLO_list::print() const
{
    Node *temp = head_;
    while (temp != nullptr) {
        std::cout << temp->data_ << " ";
        temp = temp->next_;
    }
    std::cout << std::endl;
}

SLO_list::Node *SLO_list::searchNode(int item)
{
    Node *current = head_;
    while (current != nullptr) {
        if (current->data_ == item) {
            return current;
        } else {
            if (current->data_ > item) {
                return nullptr;
            }
            current = current->next_;
        }
    }
    return nullptr;
}

void SLO_list::clear()
{
    Node *current = head_;
    Node *temp = nullptr;
    while (current) {
        temp = current->next_;
        delete current;
        current = temp;
    }
}

void SLO_list::listsIntersection(const SLO_list &other)
{
    Node *current = head_;
    Node *currentSecond = other.head_;

    if (currentSecond == nullptr) {
        clear();
        this->head_ = nullptr;
    } else if (current != nullptr) {
        while (current->data_ != currentSecond->data_) {
            if (currentSecond->data_ < current->data_) {
                currentSecond = currentSecond->next_;
            } else if (currentSecond->data_ > current->data_) {
                Node *temp = current;
                current = current->next_;
                delete temp;
            }
            if (current == nullptr or currentSecond == nullptr) {
                current = nullptr;
                break;
            }
        }
        if (currentSecond == nullptr) {
            clear();
            current = nullptr;
        }
        head_ = current;
        if (current != nullptr) {
            while (current->next_ != nullptr and currentSecond->next_ != nullptr) {
                if (current->next_->data_ > currentSecond->next_->data_) {
                    currentSecond = currentSecond->next_;
                } else if (current->next_->data_ < currentSecond->next_->data_) {
                    Node *temp = current->next_;
                    current->next_ = current->next_->next_;
                    delete temp;
                } else {
                    current = current->next_;
                }
            }
            if (currentSecond->next_ == nullptr) {
                while (current->next_ != nullptr) {
                    Node *temp = current->next_;
                    if (current->next_->next_ != nullptr) {
                        current->next_ = current->next_->next_;
                    } else {
                        delete current->next_;
                        current->next_ = nullptr;
                    }
                }
            }
        }
    }
}
