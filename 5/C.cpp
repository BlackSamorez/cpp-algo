#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <algorithm>

int main(){
	int n;
	std::cin >> n;
	std::vector<int> vecc(n, 0);
	std::vector<int> vecc0(n, 0);
	for (int i = 0; i < n; i++){
		std::cin >> vecc0[i];
	}

	for (int i = 0; i < n; i++){
		int j;
		if (i - 1 < 0){j = n - 1;} else {j = i - 1;}
		vecc[i] = (vecc0[j] + vecc0[i] + vecc0[(i + 1) % n]) / 3;
	}



	for (int i = 0; i < n - 1; i++){
		std::cout << vecc[i] << " ";
	}
	std::cout << vecc[n - 1] << "\n";

return 0;
}