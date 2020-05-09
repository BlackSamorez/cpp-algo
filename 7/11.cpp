#include <iostream>
#include <bitset>
#include <array>
#include <cmath>
#include <iomanip> 
#include <math.h>
using std::cin;
using std::cout;
using std::endl;
using std::bitset;

double f1(int n){
	double j, sum = 0;
	for (int i = 0; i < n; i++){
		j = (double) i;
		if (i%2 == 0){
			sum += 1 / (1 + 2 * j);
		} else {
			sum -= 1 / (1 + 2 * j);
		}
	}
	cout << std::setprecision(30) << -std::log(std::abs(4 * sum - M_PI)) << "\n";
}

double f2(int n){
	double sum = 1;
	for (int i = 0; i <= n; i++){
		sum = sum * ((i / 2) * 2 + 2) / (((i + 1) / 2) * 2 + 1);
	}
	cout << std::setprecision(30) << -std::log(std::abs(2 * sum - M_PI)) << "\n";
}

double f3(int n){
	double sum, j = 0;
	sum = 1;
	for (int i = 0; i <= n; i++){
		j = std::sqrt(2 + j);
		sum = sum * j / 2;
	}
	cout << std::setprecision(30) << -std::log(std::abs(2 / sum - M_PI)) << "\n";
}

double f4(int n){
	double sum = 0;
	for (int i = 0; i < n; i++){
		if (i % 2 == 0){
			sum += 1 / (std::pow(3, i) * (2*i + 1));
		} else {
			sum -= 1 / (std::pow(3, i) * (2*i + 1));
		}
	}
	cout << std::setprecision(30) << -std::log(std::abs(2 * std::sqrt(3) * sum - M_PI)) << "\n";
}

double f5(int n){
	double j, sum = 3;
	j = 0;
	for (int i = 0; i < n; i++){
		j = (double) i;
		if (i % 2 == 0){
			sum += 4 / ((2 * j + 2) * (2 * j + 3) * (2 * j + 4));
		} else {
			sum -= 4 / ((2 * j + 2) * (2 * j + 3) * (2 * j + 4));
		}
	}
	cout << std::setprecision(30) << -std::log(std::abs(sum - M_PI)) << "\n";
}

double f6(int n){
	double j, sum = 0;
	for (int i = 1; i <= n; i++){
		j = (double) i;
		sum += 1 / (j * j);
	}
	cout << std::setprecision(30) << -std::log(std::abs(sqrt(6 * sum) - M_PI)) << "\n";
}


int main(){
	int a;
	cin >> a;
	cout << std::setprecision(30) << std::log(a) << "\n";
	f1(a);
	f2(a);
	f3(a);
	f4(a);
	f5(a);
	f6(a);
return 0;
}