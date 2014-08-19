/*
PROG: ride
ID: jerkkao1
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int calculateMultiplyNum(string);
int toInt(char);

int main(){
    ifstream ifs ("ride.in");
    ofstream ofs ("ride.out");
    string comet,group;
    ifs >> comet >> group;

    if (calculateMultiplyNum(comet) == calculateMultiplyNum(group))
        ofs << "GO";
    else
        ofs << "STAY";
    ofs << endl;

    return 0;
}

int calculateMultiplyNum(string pString){
    int result = 1;
    for (int i = 0; i <= pString.length(); ++i){
        result *= toInt(pString[i]);
    }

    return result % 47;
}

int toInt(char pChar){
    return (int)pChar - (int)'A' + 1;
}
