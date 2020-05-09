#include <iostream>
#include <cmath>
#include <string>

int main(){
	int n = 0, x, maxx = 0, max = 0, minn, min;
	std::cin >> n;
	for (int l = 0; l < n; l++){
		std::cin >> x;
		if (l == 0){
			minn = x;	
		}
		if (l == 1){
			if (x < minn){
				min = minn;
				minn = x;
			} else {
				min = x;
			}
		}
		if (x >= maxx){
			max = maxx;
			maxx = x;
		} else {
			if (x > max){
				max = x;
			}
		}
		if (l != 1 and l != 0){
		if (x <= minn){
			min = minn;
			minn = x;
		} else {
			if (x < min){
				min = x;
			}
		}	
		}

	}
	int a = minn + min;
	int b = maxx + max;
	std::cout << a << " " << b << "\n"; 
return 0;
}