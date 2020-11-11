#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdint.h>
#include <set>
using namespace std;

map<char, int> Amino = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
map<int, char> bach = {{0, 'A'}, {1, 'C'}, {2, 'G'}, {3, 'T'}};

int str_to_int(string s){
	int ans = 0;
	int p = 1;
	for (int i = 0; i < 10; ++i)
	{
		ans += Amino[s[9 - i]] * p;
		p *= 4; 
	}
	return ans;
}

string int_to_str(int n){
	string str(10, '*');
	for (int i = 0; i < 10; ++i){
		str[9 - i] = bach[n % 4];
		n = n / 4;
	}
	return str;
}

int main(){
	string input;
	vector<bool> encountered(1048576, false);
	vector<bool> answer(1048576, false);
    getline(cin, input);


    if (input.size() < 10){
    	exit(0);
    }

    for (int i = 0; i < input.size() - 9; ++i){
    	if (encountered[str_to_int(input.substr(i, 10))]){
    		answer[str_to_int(input.substr(i, 10))] = true;
    	}
    	encountered[str_to_int(input.substr(i, 10))] = true;
    }

    for (int i = 0; i < 1048576; ++i)
    {
    	if (answer[i]){
    		cout << int_to_str(i) << " ";
    	}
    }
}