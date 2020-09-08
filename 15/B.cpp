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
	int st[n];
	int maxlen = 0;
	for (int i = 0; i < n; i++){
		cin >> st[i];
	}
	for (int i = 0; i < n; i++){
		if (st[i] == 1){
			int maxipos = n;
			for (int j = 0; j < n; j++){
				if (st[j] == 2 and abs(i - j) < maxipos){
					maxipos = abs(i - j);
				}
			}
			if (maxipos > maxlen){
				maxlen = maxipos;
			}
		}
	}
	cout << maxlen << "\n";
return 0;
}