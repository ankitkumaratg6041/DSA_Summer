#include <iostream>
#include <vector>
using namespace std;

int findMinimumInRotatedSortedArray_02(vector<int>&arr){
    int start = 0;
    int end = arr.size()-1;
    int mid = start + ((end-start)/2);

    while(start < end){
        if(arr[mid] <= arr[arr.size()-1]){ // on the right side
            end = mid;
        }
        else if(arr[mid] > arr[arr.size()-1]){ // on the left side
           start = mid + 1;
        }
        mid = start + ((end-start)/2);
    }
    return start;
}

int findMinimumInRotatedSortedArray_01(vector<int>&arr){
    int start = 0;
    int end = arr.size()-1;
    int mid = start + ((end-start)/2);

    while(start < end){
        if(arr[mid] >= arr[0]){ // on the left side
            start = mid+1;
        }
        else if(arr[mid] < arr[0]){ // on the right side
            end = mid; // because we are trying to find pivot = min element
        }
        mid = start + ((end-start)/2);
    }
    return start;
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
    int ans = findMinimumInRotatedSortedArray_01(arr);
    cout << ans << endl;


    return 0;
}