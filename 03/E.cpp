#include <iostream>
#include <cmath>
#include <vector>

int main(){
	int n, k, a0, step = 0, x, max;
	std::cin >> n >> k;
	std::vector<int> vect(n, 0);
	std::vector<int> horse(k, 0);
	for (int l = 0; l < n; l++){
		std::cin >> vect[l];
	}

	//std::cout << 0 << "\n";
	
	a0 = vect[0];
	for (int l = 0; l < n; l++){
		vect[l] = vect[l] - a0;
	}
	
	//std::cout << 1 << "\n";

	int s = n - 1;
	max = vect[s];
	step = max / (k - 1) + 1;

	int found = 0;

	//std::cout << 2 << "\n";

	while (1){
		step--;
		//std::cout << "\n" << step << "\n";
		x = step;
		int hit;
		for (int l = 0; l < k - 1; l++){
			hit = 0;
			while (hit == 0 and x <= max){
				for (int i = 0; i < n; i++){
					if (vect[i] == x){
						hit = 1;
					}

				}
				if (hit){
					x += step;
				} else {
					x++;
				}
			}
		}
		if (hit){
			break;
		}
	}
	std::cout << step << "\n";

return 0;
}

