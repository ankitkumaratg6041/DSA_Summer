string strRepeatTRM(string& str){
    int len = str.length();
    vector<char> stringTape((2*len)+1, 'B'); // tape for turing machine
    // loop to copy all the chars from str into the tape one by one
    for(int i=0; i<len; i++){
        stringTape[i] = str[i];
    }
    // inserting '#' at the end original string copied in the vector i.e. tape
    stringTape[len] = '#';

    int s=0; // here s is equivalent to the head of the tape
    int e= len+1; // keeping e at next pos of '#';
    while(stringTape[s] != '#'){
        stringTape[e++] = stringTape[s++];
    }

    // now we need to conver our vector of char to string
    string output(stringTape.begin(), stringTape.end());
    return output;
}