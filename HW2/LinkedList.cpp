#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

LinkedList::~LinkedList() {
    Node* current = head;
    Node* next = nullptr;
    while(current != nullptr){
        next = current->next;
        delete current;
        current = next;
    }
}

LinkedList::LinkedList(const LinkedList& other) {
    head = nullptr;
    tail = nullptr;
    size = 0;
    Node* p = other.head;
    while (p != nullptr){
        insert_to_end(p->data);
        p = p->next;
    }
        

}

void LinkedList::insert_to_beginning(int value) {
    if (head == nullptr){
        Node* newNode = new Node(value);
        head = tail = newNode;
        size += 1; 
    }
    else {
        Node* newNode = new Node(value, head);
        head = newNode;
        size += 1 ;
    }
}

void LinkedList::insert_to_end(int value) {
    if (head == nullptr){
        Node* newNode = new Node(value);
        head = tail = newNode;
        size += 1;
    }
    else {
        Node* p = head;
        while(p->next != nullptr){
            p = p->next;
        }
        Node* newNode = new Node(value);
        p->next = tail = newNode;
        size += 1;
    }
}

void LinkedList::insert_to_position(int value, int k) {
    if (k == 0){
        insert_to_beginning(value);
        size += 1;
    }
     
    else if (k < size){
        Node* p = head;
        int count = 0;
        while(p != nullptr){
            if (count == k - 1){
                Node* newNode = new Node(value, p->next);
                p->next = newNode;
                size +=1;
                break;
            }
            else{
                p = p->next;
                count += 1;
            }
        } 
    }
}
    


bool LinkedList::remove_from_beginning() {
    if (size > 0){
        Node* p = head;
        head = head->next;
        delete p;
        size -= 1;
        return true;
    }
    else{ return false; } 
}

bool LinkedList::remove_from_end() {
    if (size > 0){ 
        Node* p = head;
        while(p->next != nullptr && p->next->next != nullptr){
            p = p->next;
        }
        tail = p;
        delete p->next;
        p->next = nullptr;
        size -=1;
        return true;
    }
    else { return false; }
}

bool LinkedList::remove_value(int value) {
    if (head->data == value){
        remove_from_beginning();
        return true;
    }
    else {
        Node* p = head;
        while(p->next->next != nullptr ){
            if (p->next->data == value){
                Node* prev = p->next->next;
                delete p->next;
                p->next = prev;
                size -=1;
                return true;
            }
            else{
                p = p->next;
            }
        }
        if (p->next->next == nullptr && p->next->data == value){
            delete p->next;
            p->next = nullptr;
            tail = p;
            size -= 1;
            return true;
        } 
        return false;
    }
}

int LinkedList::getSize() const {
    return size; 
}

int LinkedList::get_position(int k) const {
    int count = 0;
    Node* p = head;
    while(p != nullptr){
        if (count == k){
            return p->data;
        }
        p = p->next;
        count += 1;
    }
    return -1;
}

//////////////

// void LinkedList::Print(){

//     const Node* p = head;
//     while(p) {
//         cout << p->data ;
//         cout << " ";
//         p = p->next;
//     }
//     cout << endl;

// }
