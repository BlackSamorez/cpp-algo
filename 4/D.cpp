#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <algorithm>

int main(){
int N, ans = 1, temp = 1;
std::cin >> N;
std::vector<int> stones(N, 0);
for (int i = 0; i < N; i++){
	std::cin >> stones[i];
}
std::sort(stones.begin(), stones.end());

for (int i = 0; i < N - 1; i++){
	if (stones[i + 1] == stones[i]){
		if (temp == 0){
			ans = 0;
		}
		temp = 0;
	} else {
		temp = 1;
	}
}

std::cout << ans << "\n";

return 0;
}