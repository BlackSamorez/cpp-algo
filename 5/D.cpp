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

for (int i = n - 1; i > 0; i--)
    {
    for (int j = 0; j < i; j++)
      if (vecc[j] > vecc[j + 1])
      {
        int tmp = vecc[j];
        vecc[j] = vecc[j + 1];
        vecc[j + 1] = tmp;
      }
    }

for (int i = 0; i < n - 1; i++){
	std::cout << vecc[i] << " ";
}
std::cout << vecc[n - 1] << "\n";

return 0;
}