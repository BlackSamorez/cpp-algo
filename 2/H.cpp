#include <iostream>
#include <cmath>

int main(){
	int a,i,check;
	std::cin >> a;
	i = 2;
	check = 0;
	while (a != 1){
		i = 2;
		check = 0;
		while (i < a){
			if (a % i == 0){
				check = 1;
				break;
			}
			++i;
		}
		if (check == 0){
			std::cout << a << "\n";
			break;
		}
		std::cout << i << "\n";
		a = a / i;
	}	
}