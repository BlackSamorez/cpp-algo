#include <iostream>
#include <array>
#include <cmath>

using namespace std;

float* generator(){
	float *exit = new float[1000000000];
	for (int i = 0; i < 1000000000; i++){
		exit[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	}
	return exit;
}

float calculator(float* a){
	float exit = 0;
	for (int i = 0; i < 1000000000; i++){
		exit += a[i];
	}
	exit = exit / 1000000000;
	return exit;
}

int main(){
	float *a, mean;
	a = generator();
	cout << "start\n";
	mean = calculator(a);
	//: 2.7s
	//O0: 2.7s
	//O1: 1.4s
	//O2: 1.4s 
	//O3: 1.4s
	cout << mean << "\n";
}