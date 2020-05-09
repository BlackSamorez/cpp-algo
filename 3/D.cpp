#include <iostream>
#include <cmath>

int main(){

int x, numb, a, l = 1, j = 2;
std::cin >> numb;
while (l < numb){
	j++;
	int i = 2, prime = 1;
	while (i < j){
		if (j % i == 0){
			prime = 0;
		}
		++i;
	}
	if (prime){
		l++;
	}
}
std::cout << j << "\n";
return 0;
}