#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void isSortedAndRotated(vector<int>& arr){
    int len = arr.size();
    int count = 0;
    for(int i=1; i<len; i++){
        if(arr[i-1] > arr[i]) count++;
    }
    if(arr[len-1] > arr[0]) count ++;

    count <= 1 ? cout << "True" << endl : cout << "False" << endl;
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

    isSortedAndRotated(arr1);

    return 0;
}