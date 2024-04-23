#include <iostream>
#include <vector>

using namespace std;

void bubbleSortRec(vector<int>& arr, int size){
    // base case
    if(size == 0 || size == 1){
        return;
    }

    // processing & recursive case
    // size - 1 so that i doesn't go out of bounds
    bool flag = 0;
    for(int i=0; i<size-1; i++){
        if(arr[i] > arr[i+1]){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
            flag = 1;
        }
    }

    if(flag == 0){
        return;
    }

    bubbleSortRec(arr, size-1);
}


int main(void){
    int size;
    cout << "Enter size: ";
    cin >> size;

    cout << "Enter array: ";
    vector<int> arr(size);
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    bubbleSortRec(arr, size);

    cout << "Sorted array: ";
    for(auto i: arr){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}