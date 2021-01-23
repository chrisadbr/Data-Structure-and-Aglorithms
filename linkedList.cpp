#include <iostream>

using namespace std;

struct ListNode{
    int num;
    string name;
    ListNode *next;
};

int main(){
    //
    ListNode *head = nullptr;
    head = new ListNode; // Allocate new node
    head->num = 100;
    head->next = nullptr;

    ListNode *secondPtr = new ListNode;
    secondPtr->num = 200;
    secondPtr->name = "Shabani";
    secondPtr->next = nullptr;
    head->next = secondPtr;

    ListNode *thirdPtr = new ListNode;
    thirdPtr->num = 400;
    thirdPtr->next = nullptr;
    secondPtr->next = thirdPtr;

    ListNode *fourthPtr = new ListNode;
    fourthPtr->num = 500;
    fourthPtr->next = nullptr;
    thirdPtr->next = fourthPtr;

    ListNode *fifthPtr = new ListNode;
    fifthPtr->num = 23;
    fifthPtr->next = nullptr;
    fourthPtr->next = fifthPtr;

    cout << "First item: " << head->num << endl;
    cout << "Second item: " << head->next->num << " " << head->next->name << endl;
    cout << "Third item: " << secondPtr->next->num << endl;
    cout << "Fourth item: " << thirdPtr->next->num << endl;
    cout << "Fifth item: " << fourthPtr->next->num << endl;
    //
    return 0;
}
