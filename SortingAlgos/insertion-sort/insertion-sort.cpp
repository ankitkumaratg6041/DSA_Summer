#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& arr){
    cout << "Sorted array using insertion sort: ";
    for(auto i: arr){
        cout << i << " ";
    }
}

void insertionSort(vector<int>& arr, int size){
    // this loop is for the non-sorted array part
    int j; // this represents index of the last element of the sorted array part
    for(int i=1; i<size; i++){
        int temp = arr[i]; // copy of the first element of second part of non-sorted array
        for(j=i-1; j >= 0; j--){ // this loops runs backwards on sorted array part
            if(arr[j] > temp){
                arr[j+1] = arr[j];
                // doing this means we have one block empty in the array which can be used to store the correct value
            }
            else break; // means last element of sorted array is smaller than first 
            //element of the non sorted array part meaning array is sorted including
            // that element as well
        }
        arr[j+1] = temp;
    }

    print(arr);
}

int main(void){
    int size;
    cout << "Enter size: ";
    cin >> size;
    cout << "Enter vector: ";
    vector<int> arr(size);

    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    insertionSort(arr, size);

    return 0;
}