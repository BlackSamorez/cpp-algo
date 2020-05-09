#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h> 
using namespace std;

void calc(int *x, int *y, int n){
	if (n > 2){
		x[n] = x[n - 1] + y[n - 1];
		y[n] = x[n - 1] + x[n - 2];
	}
	n++;
	if (n < 51){
		calc(x, y, n);
	}

}

int main(){
	int x[51], y[51];
	x[1] = 1; y[1] = 1;
	x[2] = 2; y[2] = 2;
	calc(x, y, 3);
	int n;
	cin >> n;
	cout << x[n] + y[n] << "\n";
return 0;
}