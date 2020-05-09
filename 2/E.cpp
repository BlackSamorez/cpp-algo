#include <iostream>
#include <cmath>

int main(){
	int c,max;
	c = 1;
	max = 0;
	while (c != 0){
	std::cin >> c;
	if (c % 2 == 0){
		if (c > max){
			max = c;
		}
	}	
	}
	std::cout << max << "\n";


}