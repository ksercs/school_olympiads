#include <iostream>
#include <fstream>
#include <cstring>
//#include <string>
//#include <conio.h>

using namespace std;


long long ch_count, zcol;
char start, temp, finish;

    ifstream in ("F_.in");
    ofstream out ("F_.out");

void hanoy(int ch, char start, char finish, char temp)
{   
    zcol+=1;
    if (ch == 1){
                    out <<start <<" " <<temp <<" " <<finish <<"\n" <<zcol <<"\n";
                    //return 1, start, finish;
                    }
    else            {
                    hanoy(ch - 1, start, temp, finish);
                    out <<start <<" " <<temp <<" " <<finish <<"\n" <<zcol <<"\n";
                    hanoy(ch - 1, temp, finish, start);  
                    }
}

int main()
{
    in >> ch_count;
    start = 'A'; 
    finish = 'B';
    temp = 'C';
    hanoy(ch_count, start, finish, temp);
return 0;
}
