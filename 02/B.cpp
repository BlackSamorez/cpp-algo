#include <iostream>
#include <cmath>

int main(){
	int a,b;
	std::cin >> a;
	if (((a % 4 == 0) and (a % 100 != 0))  or (a % 400 == 0)){
		std::cout << "YES\n";

	} else {
		std::cout << "NO\n";
	}


}