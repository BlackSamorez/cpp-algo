#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h> 
using namespace std;

bool calc_price(int *price, int* map, int* status, int m, int n){
	bool fin = 0;
	for (int i = 0; i < m - 1; i++){
		for (int j = 0; j < n - 1; j++){
			if (status[n * (i + 1) + (j)] == 1 and status[n * (i) + (j + 1)] == 1 and status[n * (i) + (j)] == 0){
				status[n * (i) + (j)] = 1;
				map[n * (i) + (j)] = min(map[n * (i + 1) + (j)], map[n * (i) + (j + 1)]) + price[n * (i) + (j)];
				fin = 1;
			}
		}
	}
	for (int i = 0; i < m - 1; i++){
		if (status[n * (i + 1) + (n - 1)] == 1 and status[n * (i) + (n - 1)] == 0){
			status[n * (i) + (n - 1)] = 1;
			map[n * (i) + (n - 1)] = map[n * (i + 1) + (n - 1)] + price[n * (i) + (n - 1)];
			fin = 1;
		}
	}
	for (int j = 0; j < n - 1; j++){
		if (status[n * (m - 1) + (j + 1)] == 1 and status[n * (m - 1) + (j)] == 0){
			status[n * (m - 1) + (j)] = 1;
			map[n * (m - 1) + (j)] = map[n * (m - 1) + (j + 1)] + price[n * (m - 1) + (j)];
			fin = 1;
		}
	}
	return fin;
}

int main(){
	int n, m;
	cin >> m >> n;
	int price[m * n];
	int status[m * n];
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cin >> price[n * i + j];
			status[n * i + j] = 0;
		}
	}
	int mon;
	cin >> mon;
	int map[m * n];
	map[m * n - 1] = price[m * n - 1];
	status[m * n - 1] = 1;
	bool work = 1;
	while (work){
		work = calc_price(price, map, status, m, n);
	}
	mon = mon - map[0];
	if (mon >= 0){
		cout << mon << "\n";
	} else {
		cout << "Impossible\n";
	}
return 0;
}