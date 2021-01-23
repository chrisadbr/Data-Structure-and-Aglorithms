#include <iostream>

using namespace std;

struct ListNode{
    int value;
    ListNode *next;

    ListNode(int num, ListNode *next1 = nullptr){
        value = num;
        next = next1;
    }
};
//
void addNode(int num){
    if (head == nullptr){
        head = new ListNode(num);
    }else{
        ListNode *nodePtr = head;
        while (nodePtr != nullptr){
            nodePtr = nodePtr->next;
        }
        nodePtr->next = new ListNode(num);
    }
}
void displayNode(ListNode *ptr){
    while(ptr != nullptr){
        cout << ptr->value << " ";
        displayNode(ptr->next);
    }
}
int main(){
    ListNode *nodePtr = nullptr;
    addNode(15);
    addNode(32);
    addNode(21);
    displayNode(nodePtr);
    return 0;
}
