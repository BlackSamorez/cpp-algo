#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int state[100][100];
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			state[i][j] = 0;
		}
	}
	for (int i = 0; i < 100; i++){
		state[i][i] = 1;
	}
	for (int i = 0; i < n; i++){
		int in, out;
		cin >> out >> in;
		for (int j = 0; j < 100; j++){
			if (state[j][in] == 1){
				state[j][out] = 1;
			}
		}
	}
	state[0][0] = -1;
	for (int i = 0; i < 100; i++){
		if (state[i][0] == 1){
			state[i][i] = -1;
		}
	}
	int count = 0;
	for (int i = 0; i < 100; i++){
		if (state[i][i] == -1){
			count++;
		}
	}
	cout << count << "\n";

return 0;
}