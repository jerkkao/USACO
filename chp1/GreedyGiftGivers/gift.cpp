/*
ID: jerkkao1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int np;
    fin >> np;

    string* names = new string[np]; // for the order
    map<string, int> moneyBegin;
    map<string, int> moneyGot;

    //map initialize
    for(int i= 0; i < np; ++i){
        string name;
        fin >> name;
        names[i] = name;
        moneyBegin[name] = 0;
        moneyGot[name] = 0;
    }

    for(int i= 0; i < np; ++i){
        string giver;
        int money, peopleNum, moneyGiveEach;
        fin >> giver >> money >> peopleNum;

        moneyBegin[giver] = money;

        if(peopleNum > 0){
            moneyGiveEach = money/peopleNum;
            for(int peopleIndex = 0; peopleIndex < peopleNum; ++peopleIndex){
                string givee;
                fin >> givee;
                moneyGot[givee] += moneyGiveEach;
            }
            moneyGot[giver] += money - moneyGiveEach*peopleNum;
        }
        else{
            moneyGot[giver] += money;
        }
    }

    for(int i= 0; i < np; ++i){
        fout << names[i] << " " << moneyGot[names[i]] - moneyBegin[names[i]] << endl;
    }

    return 0;
}
