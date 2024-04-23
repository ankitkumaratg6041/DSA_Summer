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
        cout << "gap: " << gap << endl;
        int left = 0; // since left index always starts from 0 for ever new gap
        int right = left + gap; // since it is gap steps away from left
        while(right < len){ // condition to check when right goes out of bounds
            // means left is in arr1 and right is in arr2
            if(left<size1 && right >= size1){
                // // because right is actually a continuation of len while 
                //when it is in arr2 it's indexing starts from 0
                swapIfGreater(arr1, arr2, left, (right - size1));
            }
            // means left is in arr2 and means right will defin