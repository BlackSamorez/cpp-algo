#include <iostream>
#include <cmath>

int main(){
	int c,i,yes;
	std::cin >> c;	
	i = 1;
	yes = 0;
	for (i; i <= c; i = i * 2){
		if (i == c){
			yes = 1;
		}
	}
	if (yes == 1){
		std::cout << "YES\n";
	} else{
		std::cout << "NO\n";
	}
}