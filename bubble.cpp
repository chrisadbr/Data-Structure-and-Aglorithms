#include <iostream>
using namespace std;

void sortBubble(int [], int);
void displayArray(int [], int);
void sortSelection(int [], int);

int main(){
    int num_array[10];
    int arrCpy[10];
    //
    for (int idx = 0; idx < 10; idx++){
        cout << "Enter number: ";
        cin >> num_array[idx];
        arrCpy[idx] = num_array[idx];
    }
    sortBubble(num_array, 10);
    sortSelection(arrCpy, 10);
    return 0;
}

void sortBubble(int arrNums[], int len){
   /* int temp, arrMin;
    //len = sizeof(arrNums);
    //
    int iteratorCounter = 0;
    for (int outer = 0; outer < len; outer++){
        arrMin = arrNums[outer];
        for (int inner = outer + 1; inner < len; inner++){

            if (arrMin > arrNums[inner]){
                temp = arrMin;
                arrMin = arrNums[inner];
                arrNums[inner] = temp;
            }
            iteratorCounter++;
        }
        arrNums[outer] = arrMin;
    }*/

    int index, minVal, iteratorCounter;
    iteratorCounter = 0;
    bool sorted;
    do{
        sorted = false;
        for (index = 0; index < len - 1; index++){
            if (arrNums[index] > arrNums[index + 1]){
                minVal = arrNums[index + 1];
                arrNums[index + 1] = arrNums[index];
                arrNums[index] = minVal;
                sorted = true;
            }
            iteratorCounter++;
        }
    }while(sorted);
    cout << "Number of iterations: " << iteratorCounter << endl;
    displayArray(arrNums, len);
}
void sortSelection(int arr[], int len){
    int startScan, minIndex, minValue, iteratorCounter;
    iteratorCounter = 0;
    for (startScan = 0; startScan < (len - 1); startScan++){

        minIndex = startScan;
        minValue = arr[startScan];
        for (int index = startScan + 1; index < len; index++){
            if (minValue < arr[index]){
                minValue = arr[index];
                minIndex = index;
            }
            arr[minIndex] = arr[startScan];
            arr[startScan] = minValue;
            iteratorCounter++;
        }
    }
    cout << "\nNumber of iterations(selection sort): " << iteratorCounter << endl;
}
void displayArray(int sorted[], int arrLen){
    //
   // arrLen = sizeof(sorted);
    for (int idx = 0; idx < arrLen; idx++){
        cout << sorted[idx] << " ";
    }
}
