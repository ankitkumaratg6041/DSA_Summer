#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& nums, int ind, int i){
    int temp = nums[ind];
    nums[ind] = nums[i];
    nums[i] = temp;
}

void solve(vector<int> nums, vector<vector<int>>& ans, int ind){
    // base case
    if(ind >= nums.size()){
        ans.push_back(nums);
        return;
    }

    // processing and recursion
    for(int i=ind; i<nums.size(); i++){
        swap(nums[ind], nums[i]);
        solve(nums, ans, ind+1);
        swap(nums[ind], nums[i]);
    }
}

void print(vector<vector<int>> ans){
    cout << "Result: ";
    for(auto i: ans){
        for(auto j: i){
            cout << j;
        }
        cout << " ";
    }
    cout << endl;
}

void permutations(vector<int> nums){
    vector<vector<int>> ans;
    int ind = 0;

    solve(nums, ans, ind);

    print(ans);
}

int main(void){
    int size;
    cout << "Enter size: ";
    cin >> size;
    vector<int> nums(size);
    cout << "Enter string: ";
    for(int i=0; i<size; i++){
        cin >> nums[i];
    }

    permutations(nums);

    return 0;
}