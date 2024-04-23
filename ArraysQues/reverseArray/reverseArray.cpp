#include <iostream>
#include <climits>
using namespace std;

void reverseArray(int (&arr)[500], int size){
    int start = 0, end = size-1;
    int temp = 0;

    while((start<end)){
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        end--;
        start++;
    }
}

int main(void){
    int size;
    cout << "Enter size: "; cin >> size;
    int newSize = size;
    int arr[500];

    int i = 0;
    while(size != 0){
        cin >> arr[i];
        i++;
        size--;
    }

    reverseArray(arr, newSize);

    i = 0;
    while(newSize != 0){
        cout << arr[i];
        i++;
        newSize--;
    }

    return 0;
}