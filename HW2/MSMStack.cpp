#include "MSMStack.h"
#include <iostream>
#include <climits>

MSMStack::MSMStack(bool increasing) {
    isIncreasing = increasing;
}

MSMStack::~MSMStack() {

}

MSMStack::MSMStack(const MSMStack& other) {
    isIncreasing = other.isIncreasing;
    for (int i = 0; i < other.data.getSize(); i++){
        data.insert_to_end(other.data.get_position(i));
    }
}

int MSMStack::push(int x) {
    int count = 0;
    if(isIncreasing){
        while(data.get_position(0) >= x){
            data.remove_from_beginning();
            count += 1;
        }
        data.insert_to_beginning(x);
    }
    else {
        while(data.get_position(0) <= x && data.get_position(0) != -1){
            data.remove_from_beginning();
            count += 1;
        }
        data.insert_to_beginning(x);
    }
    return count;
}

int MSMStack::pop() {

    int x = data.get_position(0);
    return data.remove_from_beginning() ? x : -1;
}

int MSMStack::get_top() const {
    return data.get_position(0);
}

int MSMStack::get_size() const {
    return data.getSize();
}

MSMStack* MSMStack::split(int k) {
    MSMStack* splitted = new MSMStack[k];

    for(int i = 0; i < k; i++){
        splitted[i].isIncreasing = !isIncreasing;
        
    }

    int index = 0;
    int value = pop();
    while(value != -1){
        if (index % k == 0){ index = 0;}

        // std::cout << "index:" << index  << " value:" << value <<  std::endl;
        // std::cout << splitted[index].isIncreasing << std::endl;

        splitted[index].push(value);
        value = pop();
        index += 1;
    } 
    return splitted;
}

MSMStack* MSMStack::merge(MSMStack* parts, int numParts) {
    
    MSMStack* result = new MSMStack(!parts[0].isIncreasing);
    int count = 0; 
    while(count < numParts){
        count = 0;
        for (int i = 0; i < numParts; i++){
            if (parts[i].get_top() != -1){
                result->push(parts[i].pop());
            }
            else { count++; }
        }
    }
    return result;

}
