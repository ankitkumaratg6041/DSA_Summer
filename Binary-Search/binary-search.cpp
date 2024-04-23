#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &arr, int key){
    int low = 0;
    int high = arr.size()-1;
    // int mid = (low + high) / 2;
    int mid = low + ((high - low)/2); // to avoid errors in case of huge values for low & high
    while(low <= high){
        if(arr[mid] == key) return mid;
        else if(key < arr[mid]) high = mid - 1;
        else if(key > arr[mid]) low = mid + 1;
        // mid = (low + high) / 2;
        mid = low + ((high - low)/2);
    }
    return -1;
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

    int key;
    cout << "Enter key: ";
    cin >> key;

    int index = binarySearch(arr, key);
    cout << "Index: " << index << endl;

    return 0;
}