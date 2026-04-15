#include "BinaryTree.h"
#include "BinaryTreeNode.h"

BinaryTree::BinaryTree(BinaryTreeNode *root_node) {
    root = root_node;
}

BinaryTree::~BinaryTree() {
    removeAll(root);
}

BinaryTreeNode* BinaryTree::get_root() {
    return root;
}

bool BinaryTree::isBST() {
    return is_BST(root, -2147483647, 2147483647);
}

bool BinaryTree::isFull() {
    return is_Full(root);
}

bool BinaryTree::isBalanced() {
    return is_Balanced(root);
}

bool BinaryTree::isChain() {
    if (root == nullptr) return true;
    if (root->get_left() != nullptr && root->get_right() != nullptr){
        return false;
    }
    BinaryTreeNode* p = root;
    if (root->get_left() == nullptr){
        while(p != nullptr){
            if(p->get_left() != nullptr) return false;
            p = p->get_right();
        }
        return true;
    }
    if (root->get_right() == nullptr){
        while(p != nullptr){
            if (p->get_right() != nullptr) return false;
            p = p->get_left();
        }
        return true;
    }
}

bool BinaryTree::contains(int number) {
    return is_contains(root, number);
}

int BinaryTree::findSmallestMissingPositive() {
    vector<int>* p_array = new vector<int>;
    inorder(root, p_array);
    int smallest;
    if (p_array->operator[](0) > 1) smallest = 1;
    else {
        int count = 0;
        for(int i = 0; i < p_array->size() - 1; i++){
            if (p_array->operator[](i+1) != 1 + p_array->operator[](i)){
                smallest = p_array->operator[](i) + 1;
                break;
            }
            smallest = p_array->operator[](i+1) + 1;
        }
    }
    delete p_array;
    return smallest;
}

int BinaryTree::countOddNumbers() {
    vector<int>* k_array = new vector<int>;
    inorder(root, k_array);
    int odd_count = 0;
    for (int i = 0; i < k_array->size(); i++){
        if (k_array->operator[](i) % 2 == 1){
            odd_count += 1;
        }
    }
    return odd_count;
}

BinaryTree* BinaryTree::convertToCompleteBST() {
    vector<int>* k_array = new vector<int>;
    inorder(root, k_array);

    sort(k_array->begin(), k_array->end());

    BinaryTreeNode* new_root = build_BST(k_array, 0, k_array->size() - 1);
    BinaryTree* newTree = new BinaryTree(new_root);
    delete k_array;
    return newTree;
}

bool BinaryTree::isComplete() {
    if (root == nullptr) return true;
    queue<BinaryTreeNode*> q;
    q.push(root);
    bool isNull = false;

    while(!q.empty()){
        BinaryTreeNode* current =  q.front();
        q.pop();

        if (current->get_left() != nullptr){
            if (isNull) return false;
            q.push(current->get_left());
        }
        else {
            isNull = true;
        }
        if (current->get_right() != nullptr){
            if (isNull) return false;
            q.push(current->get_right());
        }
        else {
            isNull = true;
        }
    }
    return true;
}

int BinaryTree::isHeap() {
    if (!isComplete()) return 0;
    if (is_maxHeap(root)) return 1;
    if (is_minHeap(root)) return 2;
    else return 0;
}

// IMPLEMENT THE HELPER FUNCTIONS YOU DEFINED IN BinaryTree.h HERE, IF NEEDED

BinaryTreeNode* BinaryTree::build_BST(vector<int>* array, int start, int end){
    if (end - start < 0) {return nullptr;}
    if (end == start){
        BinaryTreeNode* newNode = new BinaryTreeNode(array->begin()[start] , nullptr, nullptr);
        return newNode;
    }
    int mid = 0;
    if ((end - start) % 2 == 0) {mid = (end- start)/2 ;}
    else {mid = ((end - start) / 2) + 1;}
    mid = start + mid;
    bool con = true;
    while (con){
        if (is_com_full(mid - start)){
            con = false;
        }
        else if (is_com_full(end - mid)){ 
            con = false;
        }
        else { mid += 1;}
    }
    BinaryTreeNode* newNode = new BinaryTreeNode(array->begin()[mid], nullptr, nullptr);
    newNode->set_left(build_BST(array, start, mid - 1));
    newNode->set_right(build_BST(array, mid + 1, end));
    return newNode;
}

bool BinaryTree::is_com_full(int num){
    bool is_con = true;
    int two_power = 2;
    while (is_con){
        if (num == two_power - 1){return true;}
        if (num < two_power) {is_con = false;}
        two_power = 2 * two_power;
    }
    return false;
}


void BinaryTree::inorder(BinaryTreeNode* p, vector<int>* array){
    if (p != nullptr){
        inorder(p->get_left(), array);
        array->push_back(p->get_data());
        inorder(p->get_right(), array);
    }
}

bool BinaryTree::is_contains(BinaryTreeNode* p, int value){
    if(p == nullptr) return false;
    if (p->get_data() == value) return true;
    if (p->get_left() == nullptr && p->get_right() == nullptr) return false;
    if (p->get_left() == nullptr){
        return is_contains(p->get_right(), value);
    }
    if (p->get_right() == nullptr){
        return is_contains(p->get_left(), value);
    }
    return is_contains(p->get_left(), value) || is_contains(p->get_right(), value);

}


bool BinaryTree::is_Balanced(BinaryTreeNode* p){
    if (p == nullptr) return true;
    if (abs(height(p->get_left()) - height(p->get_right())) > 1){
        return false;
    }
    return is_Balanced(p->get_left()) && is_Balanced(p->get_right());
}


int BinaryTree::height(BinaryTreeNode* p){
    if (p == nullptr) return 0;
    return max(height(p->get_left()), height(p->get_right())) + 1;
}



bool BinaryTree::is_maxHeap(BinaryTreeNode* p){
    if (p->get_left() == nullptr && p->get_right() == nullptr) return true;
    if (p->get_left() == nullptr){
        if (p->get_right()->get_data() <= p->get_data()){
            return is_maxHeap(p->get_right());
        }
        else return false;
    }

    if (p->get_right() == nullptr){
        if (p->get_left()->get_data() <= p->get_data()){
            return is_maxHeap(p->get_left());
        }
        else return false;
    }

    if (p->get_left()->get_data() <= p->get_data() &&
     p->get_right()->get_data() <= p->get_data()){
        return is_maxHeap(p->get_left()) && is_maxHeap(p->get_right());
    }
    else return false;

}

bool BinaryTree::is_minHeap(BinaryTreeNode* p){
    if (p->get_left() == nullptr && p->get_right() == nullptr) return true;
    if (p->get_left() == nullptr){
        if (p->get_right()->get_data() >= p->get_data()){
            return is_minHeap(p->get_right());
        }
        else return false;
    }

    if (p->get_right() == nullptr){
        if (p->get_left()->get_data() >= p->get_data()){
            return is_minHeap(p->get_left());
        }
        else return false;
    }

    if (p->get_left()->get_data() >= p->get_data() &&
     p->get_right()->get_data() >= p->get_data()){
        return is_minHeap(p->get_left()) && is_minHeap(p->get_right());
    }
    else return false;

}

bool BinaryTree::is_BST(BinaryTreeNode* p, int min_val, int max_val){
    if (p == nullptr) return true;
    
    if (p->get_data() < min_val || p->get_data() > max_val) {
        return false;
    }

    return is_BST(p->get_left(), min_val, p->get_data()) &&  
           is_BST(p->get_right(), p->get_data(), max_val); 
}


bool BinaryTree::is_Full(BinaryTreeNode* p){
    if (p == nullptr){return true;}
    if (p->get_right() == nullptr && p->get_left() == nullptr ){
        return true;
    }
    else if (p->get_right() == nullptr || p->get_left() == nullptr){
        return false;
    }
    return (is_Full(p->get_right()) && is_Full(p->get_left()));
}

void BinaryTree::removeAll(BinaryTreeNode* p){
    if (p != nullptr){
        BinaryTreeNode* left = p->get_left();
        BinaryTreeNode* rigth = p->get_right();
        removeAll(left);
        removeAll(rigth);
        delete p;
    }
}
