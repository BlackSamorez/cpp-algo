#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

template<typename T>
void pop_front(std::vector<T>& vec){
    vec.erase(vec.begin());
}

int main(){
	int n;
	cin >> n;
	vector<vector<bool>> con(n, vector<bool>(n, false));
	vector<bool> visited(n, false);
	vector<int> queue = {0};
	visited[0] = true;

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		con[a][b] = true;
		con[b][a] = true;
	}
	
	while (queue.size()){
		for (int i = 0; i < n; ++i){
			if (con[queue[0]][i] && !visited[i]){
				visited[i] = true;
				queue.push_back(i);
			}
		}
		pop_front(queue);
	}

	int n_vis = 0;
	for (int i = 0; i < n; ++i){
		if (visited[i]){
			n_vis++;
		}
	}

	if (n_vis == n){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
return 0;
}