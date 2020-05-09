#include <iostream>
#include <cmath>
#include <string>

int main(){
	int speed, money;
	std::string number;
	money = 0;
	while (1){
		std::cin >> speed >> number;

		if (number == "A999AA"){
			break;
		}
		if (speed > 60){
			if (number[1] == number[2] and number[2] == number[3]){
				money += 1000;
			} else {
				if (number[1] == number[2] or number[2] == number[3] or number[1] == number[3]){
					money += 500;
				} else {
					money += 100;
				}
			}
		}
	}
	std::cout << money << "\n";
return 0;
}