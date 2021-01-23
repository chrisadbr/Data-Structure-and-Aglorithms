#include <iostream>

using namespace std;

struct guard{
    string name;
    string location;
    int employeeId;
    guard *next;

    guard(string jina, string loc, int n, guard *ptr = nullptr){
        name = jina;
        employeeId = n;
        location = loc;
        next = ptr;
    }
};
guard *frontPtr;
guard *rearPtr;
//
void addQueue(){
    guard *guardPtr;
    int empId;
    string name;
    string location;
    for (int idx = 0; idx < 5; idx++){
        cout << "Enter employee id: ";
        cin >> empId;
        cout << "Enter employee name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter employee's station: ";
        cin >> location;
        if (frontPtr == nullptr){
            frontPtr = new guard(name, location, empId);
            rearPtr = frontPtr;
        }else{
            rearPtr->next = new guard(name, location, empId);
            rearPtr = rearPtr->next;
        }
    }
}
//
void deQueue(){
    guard *temp = nullptr;
    int empId;
    string name;
    string location;
    cout << "\nPerforming dequeing operation" << endl;
     while (frontPtr)
     {
        name = frontPtr->name;
        empId = frontPtr->employeeId;
        location = frontPtr->location;
        temp = frontPtr;
        frontPtr = frontPtr->next;
        cout << "Employeee Id: " << empId << endl;
        cout << "Name: " << name << endl;
        cout << "Location: " << location << "\n\n";
        delete temp;
    }
}
//
int main(){
    addQueue();
    deQueue();
    return 0;
}
