#include <iostream>

using namespace std;
//
int arrList[] = {12, 67, 24, 19, 53, 21, 9, 61, 10};

void arrSwap(int first, int second){
    int temp;
    temp = arrList[first];
    arrList[first] = arrList[second];
    arrList[second] = temp;
}
int arrPartition(int firstIndex, int lastIndex){
//
    int pivot, smallIndex;
    arrSwap(firstIndex, (firstIndex + lastIndex) / 2);
    pivot = arrList[firstIndex];
    smallIndex = firstIndex;
//
    for (int idx = firstIndex + 1; idx <= lastIndex; idx++){
        if (arrList[idx] < pivot){
            smallIndex++;
            arrSwap(smallIndex, idx);
        }
    }
    arrSwap(firstIndex, smallIndex);
    return smallIndex;
}
int recQuicksort(int first, int last){
    int pivotLoc;
    if (first < last){
        pivotLoc = arrPartition(first, last);
        recQuicksort(first, pivotLoc - 1);
        recQuicksort(pivotLoc + 1, last);
    }
}
int quicksort(int last){
    recQuicksort(0, (last - 1));
}


int main()
{
    int lastIndex = sizeof(arrList) / sizeof(arrList[0]);
    cout << "Output before quicksort algorithm" << endl;
    for (int idx = 0; idx < lastIndex; idx++)
        cout << arrList[idx] << " ";
    quicksort(lastIndex);
    cout << "\nOutput after quicksort algorithm" << endl;
    for (int idx = 0; idx < lastIndex; idx++)
        cout << arrList[idx] << " ";
    return 0;
}
