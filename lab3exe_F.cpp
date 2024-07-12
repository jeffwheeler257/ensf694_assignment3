/*
 *  lab3exe_F.cpp
 *  ENSF 694 Lab 3 - Exercise F
 *  Created by Mahmood Moussavi
 *  Completed by Jeff Wheeler
 *  Submission date: July 17, 2024
 */

#include<vector>
#include<string>
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;

typedef vector<string> String_Vector;

// REQUIRES:
//    sv.size() >= 1
//    All the strings in sv are the same length, and that length is >= 1.
// PROMISES:
//    Return value is the "transpose" of sv, as defined in the Exercise B
//    instructions.
String_Vector transpose(const String_Vector& sv);

int main() {
    
    const int ROWS = 5;
    const int COLS = 4;
    
    char c = 'A';
    String_Vector sv;
    sv.resize(ROWS);
    
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++) {
            sv.at(i).push_back(c);
            c++;
            if(c == 'Z' + 1)
                c = 'a';
            else if (c == 'z' + 1)
                c = 'A';
        }
    
    cout << "Original string vector\n";

    for(int i = 0; i < ROWS; i++) {
        cout<< sv.at(i);
        cout << endl;
    }
    
    cout << "\nTranspose string vector\n";

    String_Vector vs = transpose(sv);
    for(int i = 0; i < (int)vs.size(); i++)
        cout << vs.at(i) << endl;

    return 0;
}



String_Vector transpose (const String_Vector& sv) {
    String_Vector new_vs;
    new_vs.resize(sv.at(0).size());
    for (int i = 0; i < (int)new_vs.size(); i++){
        for(int j = 0; j < (int)sv.size(); j++){
            new_vs.at(i).push_back(sv.at(j).at(i));
        }
    }
    return new_vs;
    
}


