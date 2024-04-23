/*
Problem statement
You have been given an array/list(ARR) of size N. You need to swap every pair of alternate elements in the array/list.

You don't need to print or return anything, just change in the input array itself.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
Time Limit: 1sec
Sample Input 1:
1
6
9 3 6 12 4 32
Sample Output 1 :
3 9 12 6 32 4
Sample Input 2:
2
9
9 3 6 12 4 32 5 11 19
4
1 2 3 4
Sample Output 2 :
3 9 12 6 32 4 11 5 19 
2 1 4 3 
*/


#include <iostream>
using namespace std;

void print(int* arr, int size){
    int i = 0;
    while(size != 0){
        cout << arr[i] << " ";
        i++;
        size--;
    }
    cout << endl;
}

void swapAlternate(int* arr, int size){
    int prev = 0, next = 1;
    int temp = 0;
    while(next < size){
        temp = arr[prev];
        arr[prev] = arr[next];
        arr[next] = temp;

        prev += 2;
        next += 2;
    }

    print(arr, size);
}

int main(void){
    int size;
    cout << "Enter size: "; cin >> size;
    int arr[size];

    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    swapAlternate(arr, size);

    return 0;
}