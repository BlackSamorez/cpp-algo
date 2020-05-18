#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h> 
using namespace std;

bool hit(int x, int y, int kx, int ky){
	if ((abs(kx - x) == 1 and abs(ky - y) == 2) or (abs(kx - x) == 2 and abs(ky - y) == 1) or (x == kx and y == ky)){
		return 1;
	} else {
		return 0;
	}
}

int main() {
	char c;
	cin >> c;
	int x = c - 'a'; // нумерация с 0
	int y;
	cin >> y;
	y = y - 1;
	vector<vector<int>> ways(9, vector<int> (9, 0));
	if (not hit(0, 0, x, y)){
		ways[1][1] = 1;
	} else {
		ways[1][1] = 0;
	}
	ways[1][1] = 1;
	for (int i = 1; i < 9; i++){
		for (int j = 1; j < 9; j++){
			if (not hit(i - 1, j - 1, x, y)){
				ways[i][j] += ways[i - 1][j];
				ways[i][j] += ways[i][j - 1];
				ways[i][j] += ways[i - 1][j - 1];
			}
		}
	}
	cout << ways[8][8] << "\n";
return 0;
}