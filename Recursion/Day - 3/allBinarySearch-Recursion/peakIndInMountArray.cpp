#include <iostream>

using namespace std;

int peakIndex(int arr[], int s, int e){
    // base case
    if(s >= e){
        return s;
    }
    // processing and recursion
    int mid = s + (e-s)/2;

    if(arr[mid] < arr[mid+1]){
        return peakIndex(arr, mid+1, e);
    }
    else if(arr[mid] < arr[mid-1]){
        return peakIndex(arr, s, mid);
    }
    else{
        return mid;
    }
}


int main(void){

    int size;
    cout << "Enter size: ";
    cin >> size;

    int arr[100];
    cout << "Enter array: ";
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    
    int ans = peakIndex(arr, 0, size-1);
    cout << "Peak Index: " << ans << endl;
}