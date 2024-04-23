#include <iostream>
#include <vector>

using namespace std;

void reverseArr(vector<char>& arr, int s){
    // base case
    if(s == arr.size()/2){ return;}
    // processing
    char temp = arr[s];
    arr[s] = arr[arr.size()-1-s];
    arr[arr.size()-1-s] = temp;

    reverseArr(arr, s+1);
}

int main(void){
    int size;
    cout << "Enter size: ";
    cin >> size;

    vector<char>arr(size);
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    cout << "Before: ";
    for(auto ch : arr){
        cout << ch << " ";
    }
    cout << endl;

    reverseArr(arr, 0);

    cout << "After: ";
    for(auto ch : arr){
        cout << ch << " ";
    }
    cout << endl;



    return 0;
}