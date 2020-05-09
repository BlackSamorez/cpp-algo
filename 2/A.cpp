#include <iostream>
#include <cmath>

int main(){
	int a,b,c,c_last,ans;
	std::cin >> a;
	//std::cout << 'a';
	//std::cout << '\n';
	std::cin >> b;
	//std::cout << 'b';
	//std::cout << '\n';

	if (a < b){
		c_last = b;
		b = a;
		a = c_last;
	c_last = 1;
	}
	ans = b;
	//std::cout << '0';
	while (b != 0){
		//std::cout << '1';
		c = a / b;
		c = a - b * c;
		a = b;
		b = c;


	}
	ans = a;
	std::cout << ans;
	std::cout << '\n';




}