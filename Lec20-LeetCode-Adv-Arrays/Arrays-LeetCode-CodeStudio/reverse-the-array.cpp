#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reverseArray(vector<int>& arr, int size){
    int start = 0;
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

    reverseArray(arr, size);

    return 0;
}