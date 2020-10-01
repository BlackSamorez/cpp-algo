#include <iostream>
#include <cmath>

int main(){
	int a,i,yes;
	std::cin >> a;
	i = 2;
	yes = 1;
	while (i < a){
		if (a % i == 0){
			yes = 0;
		}
		++i;
	}
	std::cout << yes << "\n";
	
}