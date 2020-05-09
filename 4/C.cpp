#include <iostream>
#include <cmath>
#include <vector>

int main(){
	int N;
	std::cin >> N;
	std::vector<bool> vect(N + 1, 1);
	vect[0] = 0;
	vect[1] = 1;
	for (int i = 2; i < N + 1; i++){
		if (vect[i] == 1){
			std::cout << i << " ";
			int j = i;
			while (j <= N){
				vect[j] = 0;
				j += i;
			}
		}
	}
	std::cout << "\n";



return 0;
}