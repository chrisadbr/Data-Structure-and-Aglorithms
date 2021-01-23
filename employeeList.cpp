#include <iostream>
using namespace std;

class Employee{
    protected:
        struct employeeList{
            string name;
            employeeList *next;
            //
            employeeList(string empName, employeeList *next1 = nullptr)
            {
                name = empName;
                next = next1;
            }
        };
        employeeList *head;
    public:
         Employee(){ head = nullptr; }
         void addStaff(string);
         void displayStaff() const;
         void removeStaff(string);
};
void Employee::addStaff(string emp_name)
{
    if (head == nullptr)
    {
        head = new employeeList(emp_name);
    }else{
        employeeList *emPtr = head;
        while (emPtr->next != nullptr)
            emPtr = emPtr->next;
        //
        emPtr->next = new employeeList(emp_name);
    }

}
//
void Employee::displayStaff() const{
    employeeList *empNode = head;
    while(empNode){
        cout << empNode->name << endl;
        empNode = empNode->next;
    }
}
//
void Employee::removeStaff(string empName){
    employeeList *nodePtr, *nodePrevPtr;
    if (!head){
        return;
    }else{
        nodePtr = head;
        while (nodePtr != nullptr && nodePtr->name != empName){
            nodePrevPtr = nodePtr;
            nodePtr = nodePtr->next;
        }
        if(nodePtr){
            nodePrevPtr->next = nodePtr->next;
            cout << endl << nodePtr->name << " has been terminated" << endl;
            delete nodePtr;
        }else{
            cout << empName << " doesn't exit " << endl;
        }
    }
}
int main(){
    Employee emp;
    string name;
    cout << "Old employee's list" << endl;
    /*emp.addStaff("Rukia Zabron");
    emp.addStaff("Amina Jumbe");
    emp.addStaff("Joseph Mihayo");
    emp.addStaff("Rehema Stanley");*/
    //
    cout << "Enter employee name: ";
    cin >> name;
    while (name != "quit")
    {
        emp.addStaff(name);
        cout << "Enter employee name: ";
        cin >> name;
    }
    emp.displayStaff();
    emp.removeStaff("John Manase");
    //
    cout << endl << "New employee's list" << endl;
    emp.displayStaff();
    emp.removeStaff("Joseph Mihayo");
    //
    return 0;
}
