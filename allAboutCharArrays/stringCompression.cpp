#include <iostream>
#include <vector>

using namespace std;

void compressString(vector<char> Str){
    int ansIndex = 0;
    for(int i=0; i<Str.size(); i++){
        int j = i+1;
        for(j; (j<Str.size()) && (Str[i] == Str[j]); j++);
        Str[ansIndex++] = Str[i];
        int count = j-i;
        if(count > 1){
            string cnt = to_string(count);
            for(auto i: cnt){
                Str[ansIndex++] = i;
            }
        }
        i=j-1;
    }
    cout << "Compressed string: ";
    for(int i=0; i<ansIndex; i++){
        cout << Str[i];
    }
    cout << " and it's length is: " << ansIndex << endl;
}


int main(void){
    cout << "Enter the string: ";
    string s;
    cin >> s;
    vector<char> Str(s.begin(), s.end());

    compressString(Str);

    return 0;
}