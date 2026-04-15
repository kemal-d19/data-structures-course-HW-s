#include "BinaryTree.h"
#include "BinaryTreeNode.h"
#include <iostream>
#include <vector>
#include <algorithm> // You can use sort, max, min

using namespace std;

void printVector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}


bool is_com_full(int num){
    bool is_con = true;
    int two_power = 2;
    while (is_con){
        if (num == two_power - 1){return true;}
        if (num < two_power) {is_con = false;}
        two_power = 2 * two_power;
    }
    return false;
}



int main()
{
    cout << is_com_full(15) << endl;

    cout << "kemo" << endl;
    return 0;
}
