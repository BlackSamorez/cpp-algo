#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h> 
using namespace std;


int main(){
	int n;
	cin >> n;
	vector<int> pl(n);
	for (int i = 0; i < n; i++){
		cin >> pl[i];
	}
	vector<int> men(n);
	men[0] = 0;
	if (n > 1){
		men[1] = abs(pl[1] - pl[0]);
	}
	//cout << men[0] << " " << men[1] << " ";
	for (int i = 2; i < n; i++){
		men[i] = min(men[i - 1] + abs(pl[i] - pl[i - 1]), men[i - 2] + 3 * abs(pl[i] - pl[i - 2]));
		//cout << men[i] << " ";
	}
	cout << men[n - 1] << "\n";


return 0;
}