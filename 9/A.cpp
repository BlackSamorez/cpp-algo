#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, c, d, e, f, g, h, i, j;
	float b;
	cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
	int state = 0;
	if (a == 1 or b >= 37.5){
		if (c == 1){
			if (d == 1){
				state = 1;
			} else {
				state = 2;
			}
		} else {
			if (e == 1 or f == 1){
				state = 2;
			} else {
				if (g == 1){
					state = 2;
				} else {
					state = 3;
				}
			}
		}
	} else {
		if (c == 1){
			if (i == 1 or j == 1){
				state = 2;
			} else {
				if (e == 1 or f == 1){
					state = 3;
				} else {
					state = 4;
				}
			}
		} else {
			if (g == 1 or h == 1){
				state = 3;
			} else {
				state = 4;
			}
		}
	}
	cout << state << "\n";
return 0;
}