#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;

	vector<int> place(n);
	vector<set<int>> cls(n);
	for (int i = 0; i < n; ++i)
	{
		cls[i] = {i};
		place[i] = i;
	}

	int step = 0;

	while (cls[0].size() != n){
		int a, b;
		cin >> a >> b;
		int x, y;
		x = min(place[a], place[b]);
		y = max(place[a], place[b]);

		cls[x].insert(cls[y].begin(), cls[y].end());

		int tp = place[y];
		for (auto it : cls[place[tp]]){
			place[it] = place[x];
		}
		step++;
	}

	cout << step << "\n";

return 0;
}