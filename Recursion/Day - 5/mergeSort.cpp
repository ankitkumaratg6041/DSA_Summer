#include <iostream>

using namespace std;

void merge(int* arr, int s, int e){
    int mid = s + (e-s)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *leftArr = new int[len1];
    int *rightArr = new int[len2];

    for(int i=0, k=s; i<len1; i++){
        leftArr[i] = arr[k++];
    }

    for(int i=0, k=mid+1; i<len2; i++){
        rightArr[i] = arr[k++];
    }

    // merging the arrays together
    int index1 = 0;
    int index2 = 0;
    int mainArrayIndex = s;
    
    while(index1 < len1 && index2 < len2){
        if(leftArr[index1] < rightArr[index2]){
            arr[mainArrayIndex++] = leftArr[index1++];
        }
        else{
            arr[mainArrayIndex++] = rightArr[index2++];
        }
    }

    while(index1 < len1){
        arr[mainArrayIndex++] = leftArr[index1++];
    }
    while(index2 < len2){
        arr[mainArrayIndex++] = rightArr[index2++];
    }

    delete []leftArr;
    delete []rightArr;
    
}

void mergeSort(int* arr, int s, int e){
    // base case
    if(s >= e){
        return;
    }

    // processing and recursion
    int mid = s + (e-s)/2;
    // for left part
    mergeSort(arr, s, mid);
    // for right part
    mergeSort(arr, mid+1, e);

    // merging the two sorted arrays
    merge(arr, s, e);

}

int main(void){
    int size;
    cout << "Enter size: ";
    cin >> size;

    int arr[1000];
    cout << "Enter array: ";
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    mergeSort(arr, 0, size-1);

    cout << "Result: ";
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}