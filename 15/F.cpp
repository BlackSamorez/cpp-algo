#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h> 
using namespace std;

int main() {
	int n;
	cin >> n;
	double sum = 0;
	for (int i = 0; i < n; i++){
		sum += 100 * pow(2 * 0.7, n - i - 1);
	}
	sum = sum * 0.3 + 10;
	cout << static_cast<long>(sum) << "\n";
return 0;
}