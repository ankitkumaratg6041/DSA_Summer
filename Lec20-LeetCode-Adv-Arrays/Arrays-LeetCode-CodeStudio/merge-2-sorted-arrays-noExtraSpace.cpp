/*
    
    - In this questions given two sorted arrays have the size exactly equal to 
    the number of elements that they have 
    - You cannot use any 3rd array to solve this question

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int>& arr1, vector<int>& arr2){
    cout << "Merged and sorted array is: ";
    for(auto i: arr1){
        cout << i << " ";
    }
    for(auto i: arr2){
        cout << i << " ";
    }
    cout << '\n';
}

void mergeSortedArrayNoExtraSpace(vector<int>& arr1, int size1, vector<int>& arr2, int size2){
    int left = size1-1;
    int right = 0;

    while(left >= 0 && right < size2){
        if(arr1[left] > arr2[right]){
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else{
            break;
        }
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    print(arr1, arr2);
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

    int size2;
    cout << "Enter size2: ";
    cin >> size2;
    vector<int> arr2(size2);
    cout << "Enter vector 2: ";
    for(int i=0; i<size2; i++){
        cin >> arr2[i];
    }

    mergeSortedArrayNoExtraSpace(arr1, size1, arr2, size2);

    return 0;
}