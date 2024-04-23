#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int>& arr){
    cout << "Rotated array: ";
    for(auto i: arr){
        cout << i << " ";
    }
    cout << endl;
}

void rotateAlternateElement(vector<int>& arr, int rotateNum){
    int len = arr.size();
    for(int i=0; i<len/2; i++){
        swap(arr[i], arr[(i+rotateNum)%len]);
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

    cout << "Rotate by: ";
    int rotateNum;
    cin >> rotateNum;
    rotateNum %= size1;

    rotateAlternateElement(arr1, rotateNum);

    return 0;
}