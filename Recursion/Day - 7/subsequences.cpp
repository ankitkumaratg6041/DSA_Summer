#include <iostream>
#include <vector>

using namespace std;

void solve(string arr, int ind, vector<string>& ans, string output){
    // base case
    if(ind >= arr.length()){
        if(output.length() > 0) // output should not contain empty string
            ans.push_back(output);
        return;
    }

    // processing and recursion
    // not picking up an element
    solve(arr, ind+1, ans, output);
    // picking up the element
    char element = arr[ind];
    output.push_back(element);
    solve(arr, ind+1, ans, output);

}

vector<string> subsequences(string arr){
    vector<string> ans;
    string output = "";
    int ind = 0;

    solve(arr, ind, ans, output);

    return ans;
}

int main(void){
    string arr;
    getline(cin, arr);

    vector<string> ans = subsequences(arr);
    cout << "Result: " << endl;
    for(auto sub: ans){
        if(sub.empty()){
            cout << "\"\"" << " ";
        } else{
            cout << sub << " ";
        }
    }
    cout << endl;
    cout << endl;

    return 0;
}