#include <iostream>
#include <cmath>

int main(){
	int c,max,count;
	count = 0;
	c = 1;
	max = 0;
	while (c != 0){
	std::cin >> c;
	if (c == max and max != 0){
		++count;
	}
	if (c > max){
		max = c;
		count = 1;
	}


	}	
	std::cout << count << "\n";


}