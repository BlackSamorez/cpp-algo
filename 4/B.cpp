#include <iostream>
#include <cmath>
#include <vector>

int main(){
int n, mean = 0, sc = 0;
std::cin >> n;
std::vector<int> numb(n, 0);

for (int i = 0; i < n; i++){
	std::cin >> numb[i];
	mean += numb[i];
}

mean = mean / n;

for (int i = 0; i < n; i++){
	if (numb[i] > mean){
		sc += numb[i];
	}
}

std::cout << sc << "\n";


return 0;
}