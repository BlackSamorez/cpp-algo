#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h> 
using namespace std;

int main() {
	string s;
	getline(cin, s);
	int n = s.length();
	vector<int> d1(n);
	int l=0, r=-1;
	for (int i=0; i<n; ++i) {
	  int k = i>r ? 1 : min (d1[l+r-i], r-i+1);
	  while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
	  d1[i] = k;
	  if (i+k-1 > r)
	    l = i-k+1,  r = i+k-1;
	}
	for (int i = 0; i < n; i++){
		cout << 2 * (d1[i]) - 1 << " ";
	}
	cout << "\n";
return 0;
}