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

void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int left, int right){
    if(arr1[left] > arr2[right]) {
        swap(arr1[left], arr2[right]);
    }
}

void gapMethodMerge2Arrays(vector<int>& arr1, vector<int>& arr2, int size1, int size2){
    int len = size1 + size2;
    // this done to get the ceiling value like for len = 9 
    // gap = 4(int value) + 1(remainder) = 5 (ceiling value)
    int gap =  (len/2) + (len%2);
    
    while(gap > 0){
        int left = 0; // since left index always starts from 0 for ever new gap
        int right = left + gap; // since it is gap steps away from left
        while(right < len){ // condition to check when right goes out of bounds
            // means left is in arr1 and right is in arr2
            if(left<size1 && right >= size1){
                // // because right is actually a continuation of len while 
                //when it is in arr2 it's indexing starts from 0
                swapIfGreater(arr1, arr2, left, (right - size1));
            }
            // means left is in arr2 and means right will definitely be in arr2 too
            else if(left >= size1){
                // since both pointer are in arr2 so swapping needs to be done there
                swapIfGreater(arr2, arr2, (left - size1), (right - size1));
            }
            // means both left and right is in arr1
            else{
                // since both pointer are in arr1 so swapping needs to be done there
                swapIfGreater(arr1, arr1, left, right);
            }
            left++;
            right++;
        }
        if(gap == 1) break;
        gap = (gap/2) + (gap%2);
    }

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

    gapMethodMerge2Arrays(arr1, arr2, size1, size2);

    return 0;
}