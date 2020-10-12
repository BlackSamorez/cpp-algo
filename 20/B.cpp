#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h>
#include <map>
using namespace std;

map <string, int> amino = {{"A", 0},{"C", 1},{"G", 2},{"T", 3}};
map <int, string> number = {{0, "A"}, {1, "C"}, {2, "G"}, {3, "T"}};

bool aminocp(vector<int> v1, vector<int> v2){
	if (v1[0] > v2[0]){
		return false;
	}
	if (v1[0] == v2[0] and v1[3] > v2[3]){
		return false;
	}
	return true;
}

int main(){
	int n;
	cin >> n;
	n *= 4;
	vector<vector<int>> automaton(n, vector<int>(4));
	for (int i = 0; i < n; ++i)
	{
		string amino1, amino2;
		cin >> automaton[i][0] >> amino1 >> automaton[i][2] >> amino2;
		automaton[i][1] = amino[amino1];
		automaton[i][3] = amino[amino2];
	}
	sort(automaton.begin(), automaton.end(), aminocp);

	string prot;
	cin >> prot;

	int state = 1;

	for (int i = 0; i < prot.size(); ++i)
	{
		string s(1, prot[i]);
		cout << number[automaton[4 * (state - 1) + amino[s]][1]];
		state = automaton[4 * (state - 1) + amino[s]][2];
	}
	cout << "\n";  
return 0;
}