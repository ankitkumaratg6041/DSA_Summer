/*
Problem statement
You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'.

Note:

Each pair should be sorted i.e the first value should be less than or equals to the second value. 

Return the list of pairs sorted in non-decreasing order of their first value. In case if two pairs have the same first value, the pair with a smaller second value should come first.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 10^3
-10^5 <= ARR[i] <= 10^5
-2 * 10^5 <= S <= 2 * 10^5

Time Limit: 1 sec
Sample Input 1:
5 5
1 2 3 4 5
Sample Output 1:
1 4
2 3
Explaination For Sample Output 1:
Here, 1 + 4 = 5
      2 + 3 = 5
Hence the output will be, (1,4) , (2,3).
Sample Input 2:
5 0
2 -3 3 3 -2
Sample Output 2:
-3 3
-3 3
-2 2
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector <int>> pairSum(vector<int> &arr, int s){
    vector<vector<int>> ans;
    for(int i=0; i < arr.size(); i++){
        for(int j=i+1; j<arr.size(); j++){
            if(arr[i] + arr[j] == s){
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                ans.push_back(temp);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main(void){
    int size;
    cout << "Enter size: ";
    cin >> size;
    int s;
    cout << "Enter pair sum: ";
    cin >> s;
    cout << "Enter array: ";
    vector<int> arr(size);
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    vector<vector<int>> PairSumAnswer;
    PairSumAnswer = pairSum(arr, s);

    for(int i=0; i<PairSumAnswer.size(); i++){
        for(int j=0; j<PairSumAnswer[i].size(); j++){
            cout << PairSumAnswer[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
