#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reverseArray(vector<int>& arr, int size, int pos){
    int start = pos+1;
    int end = size-1;

    while(start <= end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    for(auto i: arr){
        cout << i << " ";
    }
    cout << endl;
}

int main(void){
    int size;
    cout << "Enter size: ";
    cin >> size;
    vector<int> arr(size);
    cout << "Enter array: ";

    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    int pos;
    cout << "Enter the position after which array needs to be reversed: ";
    cin >> pos;

    reverseArray(arr, size, pos);

    return 0;
}