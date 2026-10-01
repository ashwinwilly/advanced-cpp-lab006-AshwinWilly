#pragma once

#include <cstddef>
#include <stdexcept>
#include <utility>
#include <vector>

template <typename T>
struct SNode {
    T value;
    SNode* next;

    explicit SNode(const T& v, SNode* n = nullptr) : value(v), next(n) {}
};

template <typename T>
class SLinkedList {
public:
    SLinkedList();
    ~SLinkedList();
    SLinkedList(const SLinkedList& other);
    SLinkedList& operator=(const SLinkedList& other);

    void push_front(const T& value);
    void push_back(const T& value);
    bool pop_front();
    bool pop_back();

    T& front();
    const T& front() const;
    std::size_t size() const noexcept;
    bool empty() const noexcept;
    bool contains(const T& value) const;
    std::vector<T> to_vector() const;
    void clear();

private:
    SNode<T>* head_;
    std::size_t size_;
};

template <typename T>
SLinkedList<T>::SLinkedList() : head_(nullptr), size_(0) {}

template <typename T>
SLinkedList<T>::~SLinkedList() {
//TODO: Implement the destructor for the SLinkedList class
    SNode<T>* curr=head_;
    while(curr!=nullptr){
        SNode<T>* next=curr->next;//save temp next
        delete curr;
        curr=next;
    }
    head_=nullptr;
}

template <typename T>
SLinkedList<T>::SLinkedList(const SLinkedList& other)
    : head_(nullptr), size_(0) {

    SNode<T>* curr = other.head_;
    SNode<T>* tail = nullptr;

    while (curr != nullptr) {
        SNode<T>* newNode = new SNode<T>(curr->value);

        if (head_ == nullptr) {
            head_ = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        size_++;
        curr = curr->next;
    }
}

template <typename T>
SLinkedList<T>& SLinkedList<T>::operator=(const SLinkedList& other) {
//TODO: Implement the assignment operator for the SLinkedList class
    if(&other==this){
        return *this;
    }
    clear();
    SNode<T>* curr = other.head_;
    SNode<T>* tail = nullptr;

    while (curr != nullptr) {
        SNode<T>* newNode = new SNode<T>(curr->value);

        if (head_ == nullptr) {
            head_ = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        size_++;
        curr = curr->next;
    }
    return *this;

}

template <typename T>
void SLinkedList<T>::push_front(const T& value) {
// TODO: Implement the push_front function for the SLinkedList class
    SNode<T>* insert=new SNode<T>(value);
    insert->next=head_;
    head_=insert;
    size_++;
}

template <typename T>
void SLinkedList<T>::push_back(const T& value) {
// TODO: Implement the push_back function for the SLinkedList class
    SNode<T>* insert=new SNode<T>(value);
    if(empty()){
        head_=insert;
        size_++;
        return;
    }
    SNode<T>* curr=head_;
    while(curr->next!=nullptr){
        curr=curr->next;
    }
    curr->next=insert;
    size_++;
    
}

template <typename T>
bool SLinkedList<T>::pop_front() {
// TODO: Implement the pop_front function for the SLinkedList class
    if(empty()){
        return false;
    }
    SNode<T>* old=head_;
    head_=head_->next;
    delete old;
    size_--;
    return true;

}

template <typename T>
bool SLinkedList<T>::pop_back() {
// TODO: Implement the pop_back function for the SLinkedList class
    if(empty()){
        return false;
    }
    if(size_==1){
        delete head_;
        head_=nullptr;
        size_--;
        return true;
    }
    SNode<T>* curr=head_;
    while(curr->next->next!=nullptr){
        curr=curr->next;
    }
    SNode<T>* temp=curr->next;
    curr->next=nullptr;
    delete temp;
    size_--;
    return true;


}

template <typename T>
T& SLinkedList<T>::front() {
// TODO: Implement the front function for the SLinkedList class
    if (empty()) {
        throw std::out_of_range("SLinkedList is empty");
    }
    return head_->value;
}

template <typename T>
const T& SLinkedList<T>::front() const {
    if (empty()) {
        throw std::out_of_range("SLinkedList is empty");
    }
    return head_->value;
}

template <typename T>
std::size_t SLinkedList<T>::size() const noexcept {
// TODO: Implement the size function for the SLinkedList class
    return size_;
}

template <typename T>
bool SLinkedList<T>::empty() const noexcept {
// TODO: Implement the empty function for the SLinkedList class
    return head_==nullptr;
}

template <typename T>
bool SLinkedList<T>::contains(const T& value) const {
// TODO: Implement the contains function for the SLinkedList class
    SNode<T>* curr=head_;
    while(curr!=nullptr){
        if(curr->value==value){
            return true;
        }
        curr=curr->next;
    }
    return false;
}

template <typename T>
std::vector<T> SLinkedList<T>::to_vector() const {
    std::vector<T> values;
    values.reserve(size_);
    for (SNode<T>* current = head_; current != nullptr; current = current->next) {
        values.push_back(current->value);
    }
    return values;
}

template <typename T>
void SLinkedList<T>::clear() {
//TODO: Implement the clear function for the SLinkedList class
    while(pop_front()){}

}
