#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h>
#include <map>
using namespace std;

map<int, map<char, vector<int>>> automaton;
string word;
vector<int> term;
bool answer = 0;

void step(int state, int pos){
	if (pos < word.size() - 1){
		for (int i = 0; i < automaton[state][word[pos]].size(); ++i){
			step(automaton[state][word[pos]][i], pos + 1);
		}
	} else {
		for (int i = 0; i < automaton[state][word[pos]].size(); ++i){
			if (find(term.begin(), term.end(), automaton[state][word[pos]][i]) != term.end()){
				answer = 1;
			}
		}
	}
}

int main(){
	int alph, atm, n;
	cin >> alph >> atm >> n;
	for (int i = 0; i < n; ++i){
		char letter;
		std::vector<int> line(2);
		cin >> line[0] >> line[1] >> letter;
		// cout << "ima alive" << endl;
		automaton[line[0]][letter].push_back(line[1]);
		// cout << "still alive" << endl;
	}
	// cout << "!" << endl;
	int t;
	cin >> t;
	term.resize(t);
	for (int i = 0; i < t; ++i)
	{
		cin >> term[i];
	}
	int k;
	cin >> k;
	for (int wd = 0; wd < k; ++wd){
		cin >> word;
		answer = 0;
		step(0, 0);
		cout << answer << " ";
	}
	cout << "\n";
return 0;
}