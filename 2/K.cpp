#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

int main(){
	int number, des, ed, cel, j, len;
	std::vector<int> v1(10);
	std::string ans;
	std::cin >> number;
	len = 1;
	j = 0;
	while (number > 0){
		v1[j] = number % 60;
		number = number / 60;
		j++;
	}
	std::reverse(v1.begin(), v1.end());
	j = 0;
	while (v1[j] == 0){
		j++;
	}
	j = 9 - j;
	//std::cout <<  j << "\n";
	for (j; j >= 0; j--){
		des = v1[9 - j] / 10;
		ed = v1[9 - j] % 10;
		for (int i = 0; i < des; i++){
			ans.append("<");
		}
		for (int i = 0; i < ed; i++){
			ans.append("v");
		}
		if (j != 0){ans.append(".");}
	}
	


std::cout << ans << "\n";



return 0;
}