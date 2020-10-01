#include <iostream>
#include <string>
using namespace std;

int main(){
    int sec;
    string s1, s2;
    cin >> s1 >> s2;
    sec = 36000*(s2[0]- s1[0]) + 3600*(s2[1]- s1[1])+600*(s2[3]-s1[3]) + 60*(s2[4]- s1[4])+0*(s2[6]- s1[6])+(s2[7]- s1[7]);
    if (sec<0) sec+= 24*3600;
    cout << sec << endl;
    return 0;
}
