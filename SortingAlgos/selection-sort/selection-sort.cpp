#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void print(vector<int>& arr){
    cout << "Sorted array: ";
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int min, int i, vector<int> &arr){
    int temp = arr[min];
    arr[min] = arr[i];
    arr[i] = temp;
}

void selectionSort(vector<int>&arr){
    int len = arr.size();

    // test case: 8 6 3 0 2 9
    // test case: 1 2 3 4 5 6

    for(int i=0; i<len-1; i++){
        int min = i;
        for(int j=i; j<len; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(min, i, arr);
    }

    print(arr);
}

int main(void){

    int size;
    cout << "Enter size: ";
    cin >> size;

    cout << "Enter the array values: ";
    vector<int> arr(size);
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    selectionSort(arr);

    return 0;
}