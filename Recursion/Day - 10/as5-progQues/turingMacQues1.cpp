#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool findFirstPoundSymbol(vector<char> stringTape, int &ind){
    for(int i=stringTape.size()-1; i>=0; i--){
        if(stringTape[i] == '#'){
            ind = i;
            return true;
        }
    }
    return false;
}

void duplicateString(vector<char>& stringTape, int start, int ind){
    int s=start; // here s is equivalent to the head of the tape
    int e= ind; // keeping e at next pos of '#';
    while(stringTape[s] != '#'){
        stringTape[e++] = stringTape[s++];
    }
}

string strRepeatTRM(string& str){
    int len = str.length();
    vector<char> stringTape((2*len)+1, 'B'); // tape for turing machine
    // loop to copy all the chars from str into the tape one by one
    for(int i=0; i<len; i++){
        stringTape[i] = str[i];
    }

    int ind = -1;
    if(findFirstPoundSymbol(stringTape, ind)){
        stringTape[len] = '#';
        duplicateString(stringTape, ind+1, len+1);
    }else{
        // inserting '#' at the end original string copied in the vector i.e. tape
        stringTape[len] = '#';
        duplicateString(stringTape, 0,len+1);
    }
    // now we need to conver our vector of char to string
    string output(stringTape.begin(), stringTape.end());
    output.erase(output.find_last_not_of('B')+1);
    return output;
}

int main(void){
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Output: " << strRepeatTRM(str) << endl;

    return 0;
}