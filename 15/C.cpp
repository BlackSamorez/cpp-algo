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
	vector<vector<int>> sq(n, vector<int> (n));
	int sum = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> sq[i][j];
			sum += sq[i][j];
		}
	}
	if (sum % n != 0){
		cout << "NO\n";
	} else {
		sum = sum / n;
		bool truth = 1;
		for (int i = 0; i < n; i++){
		 	int sumi = 0;
		 	int sumj = 0;
			for (int j = 0; j < n; j++){
				sumi += sq[i][j];
				sumj += sq[j][i];
			}
			if (sumi != sum or sumj != sum){
				truth = 0;
			}
		}
		int sumd1 = 0, sumd2 = 0;
		for (int i = 0; i < n; i++){
			sumd1 += sq[i][i];
			sumd2 += sq[i][n - i - 1];
		}
		if (sumd1 != sum or sumd2 != sum){
			truth = 0;
		}
		if (truth){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
return 0;
}