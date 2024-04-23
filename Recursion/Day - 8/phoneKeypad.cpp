#include <iostream>
#include <vector>

using namespace std;

void solve(string s, string output, int ind, vector<string>& ans, string map[]){
    // base case
    if(ind >= s.length()){
        // store the answer
        ans.push_back(output);
        // return back
        return;
    }

    // processing
    int num = s[ind] - '0'; // fetch the digit
    string value = map[num]; // fetch the string associated with it

    // recursion: For every char associated with the number we have to combine it with all other possible chars of other numbers

    for(int i=0; i<value.length(); i++){
        output.push_back(value[i]); // stores current answer
        // Now make all possible combinations with fetched 'char' with all chars of next digit
        solve(s, output, ind+1, ans, map);
        output.pop_back();
    }

}

void print(vector<string> ans){
    cout << "Output: ";
    for(auto i: ans){
        for(auto j: i){
            cout << j;
        }
        cout << " ";
    }
    cout << endl;
}

void phoneKeypad(string s){
    vector<string> ans;
    string output = "";
    int ind = 0;

    string map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    solve(s, output, ind, ans, map);

    print(ans);
}

int main(void){
    string s;
    cout << "Enter keypad number: ";
    cin >> s;

    phoneKeypad(s);

    return 0;
}