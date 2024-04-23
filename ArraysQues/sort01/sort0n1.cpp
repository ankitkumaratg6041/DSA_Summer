/*
Problem statement
You have been given an integer array/list(ARR) of size N that contains only integers, 0 and 1. Write a function to sort this array/list. Think of a solution which scans the array/list only once and don't require use of an extra array/list.

Note:
You need to change in the given array/list itself. Hence, no need to return or print anything. 
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
Time Limit: 1 sec
Sample Input 1:
1
7
0 1 1 0 1 0 1
Sample Output 1:
0 0 0 1 1 1 1
Sample Input 2:
2
8
1 0 1 1 0 1 0 1
5
0 1 0 1 0
Sample Output 2:
0 0 0 1 1 1 1 1
0 0 0 1 1 

*/

#include <iostream>
#include <vector>
using namespace std;

void findZeroesandOnes_v3(vector<int> &arr, int size){
    int low = 0;
    int high = size - 1;

    while(low <= high){
        while (low < size && arr[low] == 0) low++;
        while (high >= 0 && arr[high] == 1) high--;
        if(low < high){
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }
    }
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void findZeroesandOnes_v2(vector<int> &arr, int size){
    int countZeroes = 0;
    for(int i=0; i<size; i++){
        if(arr[i] == 0) countZeroes++;
    }

    for(int i=0; i<size; i++){
        arr[i] = (i<countZeroes) ? 0 : 1;
    }

    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void findZeroesandOnes_v1(vector<int> arr, int size){
    vector<int> zeroes;
    vector<int>ones;
    vector<vector<int>>ans;
    int i = 0;
    while(size != 0){
        if(arr[i] == 0) zeroes.push_back(0);
        else ones.push_back(1);
        i++;
        size--;
    }
    ans.push_back(zeroes);
    ans.push_back(ones);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
    }
    cout << endl;
    
}

int main(void){
    int size;
    cout << "Enter size: ";
    cin >> size;
    
    vector<int> arr(size);
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    findZeroesandOnes_v3(arr, size);

    return 0;
}