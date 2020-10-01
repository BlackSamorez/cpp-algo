#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++){
		cin >> num[i];
	}
	vector<int> d(n);
	for (int i = 0; i < n; i++){
		d[i] = 1;
		for (int j = 0; j < i; j++)
			if (num[j] < num[i])
				d[i] = max (d[i], 1 + d[j]);
	}
 
	int ans = d[0];
	for (int i=0; i<n; ++i)
		ans = max(ans, d[i]);
	cout << ans << endl;

}