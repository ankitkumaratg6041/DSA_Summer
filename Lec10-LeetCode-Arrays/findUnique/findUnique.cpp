/*
Problem statement
You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].

Now, in the given array/list, 'M' numbers are present twice and one number is present only once.

You need to find and return that number which is unique in the array/list.

 Note:
Unique element is always present in the array/list according to the given condition.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= t <= 10^2
0 <= N <= 10^3
Time Limit: 1 sec
Sample Input 1:
1
7
2 3 1 6 3 6 2
Sample Output 1:
1
Explanation: The array is [2, 3, 1, 6, 3, 6, 2]. Here, the numbers 2, 3, and 6 are present twice, and the number 1 is present only once. So, the unique number in this array is 1.
Sample Input 2:
2
5
2 4 7 2 7
9
1 3 1 3 6 6 7 10 7
Sample Output 2:
4
Explanation: In the first test case, the array is [2, 4, 7, 2, 7]. Here, the numbers 2 and 7 are present twice, and the number 4 is present only once. So, the unique number in this array is 4.

10
Explanation: In the second test case, the array is [1, 3, 1, 3, 6, 6, 7, 10, 7]. Here, the numbers 1, 3, 6, and 7 are present twice, and the number 10 is present only once. So, the unique number in this array is 10.
*/

#include <iostream>
#include <climits>
using namespace std;

int findUnique_v1(int* arr, int size){
    int flag = 0;
    for(int i=0; i<size; i++){
        if(arr[i] != INT_MIN){
            for(int j=i+1; j<size; j++){
                if(arr[j] == arr[i]){
                    arr[i] = INT_MIN;
                    arr[j] = INT_MIN;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) return arr[i];
            else flag = 0;
        }
    }
    return 0;
}

int findUnique_v2(int* arr, int size){
    int ans = 0;
    for(int i=0; i<size; i++){
        ans ^= arr[i];
    }
    return ans;
}

int main(void){
    int size;
    cout << "Enter size: "; 
    cin >> size;
    int arr[size];

    for(int i=0; i<size; i++){  
        cin >> arr[i];
    }

    int uniqueElement = findUnique_v2(arr, size);
    cout << uniqueElement << endl;
    return 0;
}