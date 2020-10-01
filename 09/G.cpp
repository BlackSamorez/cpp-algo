#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
using namespace std;

bool diff(int *a, int *b){
	if (a[3] == b[3]) {
		return a[0] < b[0];
	} else {
		return a[3] > b[3];
	}
}

int main() {
	int n;
	cin >> n;
	int data[n][3];
	for (int i = 0; i < n; i++) {
		data[i][0] = i;
		cin >> data[i][1] >> data[i][2];
	}
	sort(data, data + n, diff);

	for (int i = 0; i < n; i++) {
		cout << data[i][1] << "\n";
	}
}