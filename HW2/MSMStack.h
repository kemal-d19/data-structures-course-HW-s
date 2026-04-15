// DO NOT MODIFY THIS FILE
 #ifndef MSMSTACK_H
 #define MSMSTACK_H

 #include "LinkedList.h"

 class MSMStack {
 private:
    LinkedList data;
    bool isIncreasing; // true for increasing, false for decreasing

 public:
    MSMStack(bool increasing=true);
    ~MSMStack();
    MSMStack(const MSMStack& other); // Copy constructor

    int push(int x);// Push a value and pop elements to maintain monotonicity.

    int pop();// Pop and return the top element.

    int get_top() const; // Retrieve the top element without removing it.
    
    int get_size() const; // return number of elements in MSMStack
    
    MSMStack* split(int k); // Split the stack into k monotonic stacks.
    
    static MSMStack* merge(MSMStack* parts, int numParts); /* Merge an array of
    MSMStacks. */
 };
 #endif