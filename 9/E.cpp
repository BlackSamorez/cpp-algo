#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int main(){
	int age, state;
	vector<int> rec(200);
	vector<int>	cas(200);
	while (1){
		cin >> age >> state;
		if (state != 3){
			if (state != 1){
				cas[age]++;
				if (state == 2){
					rec[age]++;
				}
			}
		} else {
			break;
		}
	}
	for (int i = 0; i < 200; i++){
		if (cas[i] != 0){
			double probability = round(100 * rec[i] / double (cas[i]));
			cout << i << " " << probability << "\n";
		}
	}
return 0;
}