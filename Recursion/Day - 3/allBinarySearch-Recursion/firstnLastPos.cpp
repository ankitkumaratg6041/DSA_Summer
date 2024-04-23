#include <iostream>

using namespace std;

void leftMostOccur(int arr[], int key, int s, int e, int ans[], int leftIndex){
    // base case
    if(s > e){
        ans[0] = leftIndex;
        return;
    }

    int mid = s + (e-s)/2;

    if(arr[mid] == key){
        leftIndex = mid;
        leftMostOccur(arr, key, s, mid-1, ans, leftIndex); 
    }
    else if(arr[mid] < key){
        leftMostOccur(arr, key, mid+1, e, ans, leftIndex);
    }
    else{
        leftMostOccur(arr, key, s, mid-1, ans, leftIndex);
    }
}

void rightMostOccur(int arr[], int key, int s, int e, int ans[], int rightIndex){
    // base case
    if(s > e){
        ans[1] = rightIndex;
        return;
    }

    int mid = s + (e-s)/2;

    // processing and recursion
    if(arr[mid] == key){
        rightIndex = mid;
        rightMostOccur(arr, key, mid+1, e, ans, rightIndex);
    }
    else if(arr[mid] < key){
        rightMostOccur(arr, key, mid+1, e, ans, rightIndex);
    }
    else{
        rightMostOccur(arr, key, s, mid-1, ans, rightIndex);
    }
}

void firstNlastPos(int arr[], int key, int s, int e, int ans[]){
    int mid = s + (e-s)/2;
    leftMostOccur(arr, key, s, e, ans, -1);

    rightMostOccur(arr, key, s, e, ans, -1);
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
    
    int ans[2] = {-1, -1};
    firstNlastPos(arr, k, 0, size-1, ans);
    cout << "First Occur: " << ans[0] << " Last Occur: " << ans[1] << endl;
}