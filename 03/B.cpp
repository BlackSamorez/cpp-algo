#include <iostream>
#include <cmath>
#include <string>

int main(){
	int numb = 0, x = 0, y = 0, c1 = 0, c2 = 0, c3 = 0 , c4 = 0;
	std::cin >> numb;
	for (int l = 0; l < numb; l++){
		std::cin >> x >> y;
		if ((x > 0) and (y > 0)){c1++;}
		if ((x < 0) and (y > 0)){c2++;}
		if ((x < 0) and (y < 0)){c3++;}
		if ((x > 0) and (y < 0)){c4++;}
	}
	if ((c1 >= c2) and (c1 >= c3) and (c1 >= c4)){
		std::cout << "1" << " " << c1 << "\n";
	}
	if ((c2 > c1) and (c2 >= c3) and (c2 >= c4)){
		std::cout << "2" << " " << c2 << "\n";
	}
	if ((c3 > c1) and (c3 > c2) and (c3 >= c4)){
		std::cout << "3" << " " << c3 << "\n";
	}
	if ((c4 > c1) and (c4 > c2) and (c4 > c3)){
		std::cout << "4" << " " << c4 << "\n";
	}
return 0;
}