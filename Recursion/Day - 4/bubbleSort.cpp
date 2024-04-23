#include <iostream>

using namespace std;

void bubbleSort_01(int arr[], int size){
    // base case
    if(size == 0 || size == 1){
        return;
    }

    // processing and recursion
    for(int i=0; i<size-1; i++){
        if(arr[i] >= arr[i+1]){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }

    bubbleSort_01(arr, size-1);
}

int main(void){
    int size;
    cout << "Enter size: ";
    cin >> size;

    int arr[1000];
    cout << "Enter array elements: ";
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    bubbleSort_01(arr, size);

    cout << "Ans: ";
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }

    return 0;
}