#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
}

int main(){
	int n;
	cin >> n;
	int spec[n];
	for (int i = 0; i < n; i++){
		cin >> spec[i];
	}
	int effect = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (spec[i] + spec[j] > effect){
				if (isPrime(spec[i] + spec[j])){
					effect = spec[i] + spec[j];
				}
			}
		}
	}
	cout << effect << "\n";

return 0;
}