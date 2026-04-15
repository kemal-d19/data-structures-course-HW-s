#include "LinkedList.h"
#include "MSMStack.h"
#include <iostream>

using namespace std;

int main(){
    MSMStack stack(true);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    //cout << stack.get_top() << endl;
    MSMStack* a =  stack.split(2);
    //cout << a[0].get_top() << endl;
    MSMStack* merged = stack.merge(a, 2);
    for(int i = 0; i < merged->get_size(); i++){
        cout << merged->pop() << endl;
    }


    delete[] a;
    
    return 0; 
}
