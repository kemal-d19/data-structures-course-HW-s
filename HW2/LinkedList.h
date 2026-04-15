// DO NOT MODIFY THIS FILE
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value, Node* nextNode = nullptr)
            : data(value), next(nextNode) {}
    };
    Node* head;
    Node* tail;
    int size;
public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList& other); // Copy constructor

    void insert_to_beginning(int value);

    void insert_to_end(int value);

    void insert_to_position(int value, int k); /* do nothing if position k does not
    exist */
    bool remove_from_beginning(); /* do nothing and return false if the linked list is
    empty */
    bool remove_from_end(); /* do nothing and return false if the linked list is empty
    */
    bool remove_value(int value); /* do nothing and return false if the value is not
    in linked list */
    int getSize() const;
    int get_position(int k) const; // returns value of kth element
    void Print();
};
#endif