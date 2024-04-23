#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isOnes(string str){
    for(char i : str){
        int num = i - '0'; // converting each char in str to int value
        if((num & 1) == 0){  // bitwize '&' to check if num is 1 or 0
            return false;
        }
    }
    return true;
}

void findNext(string str){
    vector<char> tape(str.begin(), str.end());

    if(isOnes(str)){
        // resize the tape vector and initialize it with only zeroes
        tape.resize(str.size()+1);
        int size = tape.size();
        for(int i=0; i<size; i++){
            tape[i] = '0';
        }
    }
    else{
        int i = tape.size()-1;
        while(i>=0 && tape[i] != '0'){ i--; }
        tape[i] = '1';
        for (int j = i + 1; j < tape.size(); j++){
            tape[j] = '0';
        }
    }

    cout << "result: ";
    for(auto i: tape){
        cout << i;
    }
    cout << endl;
}

int main(void){
    string str;
    cout << "Enter string: ";
    cin >> str;
    
    findNext(str);

    return 0;
}