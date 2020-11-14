#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<vector<bool>> con(n, vector<bool>(n, false));

	int m;
	cin >> m;

	for (int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		con[a][b] = true;
		con[b][a] = true;
	}
	vector<int> dist(n, n);
	dist[0] = 0;

	int step = 1;

	set<int> upd = {0};
	while (find(dist.begin(), dist.end(), n) != dist.end()){
		set<int> np;
		for (auto it = upd.begin(); it != upd.end(); it++){
			for (int i = 0; i < n; ++i)
			{
				if (con[*it][i] && dist[i] == n){
					np.insert(i);
					dist[i] = step;
				}
			}
		}
		upd = np;
		++step;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << dist[i] << "\n";
	}

	return 0;
}