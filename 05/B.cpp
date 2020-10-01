#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <algorithm>

int main(){
	int n;
	std::cin >> n;
	std::vector<int> vecc(n, 0);
	for (int i = 0; i < n; i++){
		std::cin >> vecc[i];
	}
	std::reverse(std::begin(vecc), std::end(vecc));
	for (int i = 0; i < n - 1; i++){
		std::cout << vecc[i] << " ";
	}
	std::cout << vecc[n - 1] << "\n";

return 0;
}