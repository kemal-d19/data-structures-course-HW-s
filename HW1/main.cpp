#include "matrix.h"
#include <iostream>

using namespace std;

int main(){
    Matrix A(2,3);
    A.set(0,0,1);
    A.set(0,1,2);
    A.set(0,2,3);
    A.set(1,0,4);
    A.set(1,1,5);
    A.set(1,2,6);
    A.print();
    Matrix B(3,2);
    B.set(0,0,7);
    B.set(0,1,8);
    B.set(1,0,9);
    B.set(1,1,10);
    B.set(2,0,11);
    B.set(2,1,12);
    
    Matrix tr = A.transpose();

    tr.print();
    
    return 0; 
}

