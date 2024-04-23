#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int>& arr, vector<int> output, int index, vector<vector<int>>& ans){
    // base case
    if(index >= arr.size()){
        ans.push_back(output);
        return;
    }

    // processing and recursion
    // not picking up the element
    solve(arr, output, index+1, ans);

    // picking up the element
    int element = arr[index];
    output.push_back(element);
    solve(arr, output, index+1, ans);
    
}

void subsets(vector<int>& arr){
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(arr, output, index, ans);

    cout << "Result: " << endl;
    cout << "[";
    for(int i=0; i<ans.size(); i++){
        if(ans[i].size() == 0){
                cout << "[],";
        }
        else {
            cout << '[';
            for(int k=0; k<ans[i].size(); k++){
                cout << ans[i][k];
                if(k+1 < ans[i].size()){cout << ",";}
            }
            cout << "]";
            if(i+1 < ans.size()){cout << ",";}
        }
    }
    cout << "]" << endl;
    return;
}

int main(void){
    int size;
    cout << "Enter size: ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter arr: ";
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    subsets(arr);

    return 0;
}