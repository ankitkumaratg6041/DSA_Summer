#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int>& arr1){
    cout << "Zeroes moved to right: ";
    for(auto i: arr1){
        cout << i << " ";
    }
    cout << endl;
}

void moveZeroes2Right(vector<int>& arr){
    int back = 0;
    int lead = 1;

    while(lead < arr.size()){
        if(arr[lead] != 0){
            swap(arr[back], arr[lead]);
            back++;
        }
        lead++;
    }

    print(arr);
}

int main(void){
    int size1;
    cout << "Enter size1: ";
    cin >> size1;

    vector<int> arr1(size1);
    cout << "Enter vector 1: ";
    for(int i=0; i<size1; i++){
        cin >> arr1[i];
    }

    moveZeroes2Right(arr1);

    return 0;
}