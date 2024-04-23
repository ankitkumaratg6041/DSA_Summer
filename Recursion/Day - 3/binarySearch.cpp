#include <iostream>

using namespace std;

bool binarySearch(int arr[], int k, int s, int e){
    int mid = s + (e-s)/2;
    // base case
    if(s > e){
        return 0;
    }

    // processing
    if(arr[mid] == k){
        return 1;
    }
    if(arr[mid] < k){
        return binarySearch(arr, k, s+1, e);
    }
    else{
        return binarySearch(arr, k, s, mid-1);
    }
}

int main(void){
    int k = 0;
    cout << "Enter key: ";
    cin >> k;

    int size;
    cout << "Enter size: ";
    cin >> size;

    int arr[100];
    cout << "Enter array: ";
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    
    bool ans = binarySearch(arr, k, 0, (size-1));
    cout << "ans: " << ans << endl;
}