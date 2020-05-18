#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h> 
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> parties(0);
	vector<int> votes(0);
	string temp;
	getline(cin, temp);
	for (int i = 0; i < n; i++){
		string name;
    	getline(cin, name);
		if(find(parties.begin(), parties.end(), name) != parties.end()) {
			int place = 0;
			while (parties[place] != name){
				place++;
			}
			votes[place] += 1;
		} else {
    		parties.push_back(name);
    		votes.push_back(1);
		}
	}
	for (int i = 0; i < parties.size(); i++){
		int max = 0;
		int place = 0;
		for (int j = 0; j < parties.size(); j++){
			if (votes[j] > max){
				max = votes[j];
				place = j;
			}
		}
		cout << parties[place] << "\n";
		votes[place] = -1;
	}
return 0;
}