#include <iostream>
#include <vector>

using namespace std;

void solve(string str, vector<string>& ans, int ind){
    // base case
    if(ind >= str.length()){
        cout << "-> " << str << "   ";
        ans.push_back(str);
        return;
    }


    // processing and recursion
    for(int i=ind; i<str.length(); i++){
        swap(str[ind], str[i]);
        solve(str, ans, ind+1);
        swap(str[ind], str[i]);
    }
}

void print(vector<string> ans){
    cout << "Result: ";
    for(auto i: ans){
        for(auto j: i){
            cout << j;
        }
        cout << " ";
    }
    cout << endl;
}

void permutations(string str){
    vector<string> ans;
    int ind = 0;

    solve(str, ans, ind);

    print(ans);
}

int main(void){
    string str;
    cout << "Enter string: ";
    cin >> str;

    permutations(str);

    return 0;
}