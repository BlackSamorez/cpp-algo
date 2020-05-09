#include <iostream>
#include <cmath>

int main(){
	int c,count;
	count = 0;
	c = 1;
	while (c != 0){
	std::cin >> c;
	if (c % 2 == 0){
		count++;
	}	
	}
	count--;
	std::cout << count << "\n";


}