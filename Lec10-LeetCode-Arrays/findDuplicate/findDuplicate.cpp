/*
Problem statement
You are given an array of integers 'ARR' containing N elements. Each integer is in the range [1, N-1], with exactly one element repeated in the array.

Your task is to find the duplicate element. The duplicate element may be repeated more than twice in the error, but there will be exactly one element that is repeated in the array.

Note :

All the integers in the array appear only once except for precisely one integer which appears two or more times.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 5
1 <= N <= 10^5
1 <= ARR[i] <= N - 1

Time Limit: 1 sec
Sample Input 1:
1
3
1 1 2
Sample Output 1:
1
Explanation of Sample Input 1:
1 is repeated in the array, hence function returns 1.
Sample Input 2:
3
5
1 3 4 2 2
5
3 1 3 4 2
3
1 1 1
Sample Output 2:
2
3
1
*/

#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int> &arr, int n){
    int ans = 0;
    // XORing all array elements with itself
    for(int i=0; i<n; i++){
        ans ^= arr[i];
    }

    // XORing all array elements with numbers 1 to N-1
    for(int i=1; i<n; i++){
        ans ^= i;
    }

    return ans;
}

int main(void){
    int size;
    cout << "Enter size: ";
    cin >> size;
    vector<int> arr(size);
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    int duplicateElement = findDuplicate(arr, size);
    cout << duplicateElement << endl;

    return 0;
}