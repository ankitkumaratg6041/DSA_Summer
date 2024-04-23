#include <iostream>
#include <vector>

using namespace std;

void solve(string arr, vector<string>& ans, string output, int ind){
    // base case
    if(ind >= arr.length()){
        ans.push_back(output);
        return;
    }

    // processing and recursion
    // not taking any char or string
    solve(arr, ans, output, ind+1);

    // taking the elements from the string
    char element = arr[ind];
    output.push_back(element);

    solve(arr, ans, output, ind+1);
}

vector<string> subsequences(string arr){
    vector<string> ans;
    string output;
    int ind = 0;

    solve(arr, ans, output, ind);

    return ans;
}

int main(void){
    string s;
    cout << "Enter the string: ";
    cin >> s;

    vector<string>ans;
    ans = subsequences(s);

    for(int i=0; i<ans.size(); i++){
        if(ans[i].length() == 0){
            cout << '"' << '"';
        }
        for(int j=0; j<ans[i].length(); j++){
            cout << ans[i][j];
        }
        cout << " ";
    }

    cout << endl;


    return 0;
}