#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int age[n];
	int hei[n];
	int wei[n];
	double tem[n];
	for (int i = 0; i < n; i++){
		cin >> age[i] >> hei[i] >> wei[i] >> tem[i];
	}
	double mtem = 0;
	int num = 0;
	for (int i = 0; i < n; i++){
		if (age[i] >= 60 or (hei[i] - wei[i]  > 110) or (hei[i] - wei[i] < 90)){
			mtem += tem[i];
			num++;
		}
	}
	if (num != 0){
		double mean = mtem / num;
		cout << setprecision(5) << mean << "\n";
	} else {
		cout << "0\n";
	}

return 0;
}