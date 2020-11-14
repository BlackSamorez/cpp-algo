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
	int x, y;
	cin >> x >> y;
	x--;
	y--;
	vector<vector<int>> mat(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> mat[i][j];
			if (mat[i][j] == -1){
				mat[i][j] = 32000000;
			}
		}
	}
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
		}
	}

	if (mat[x][y] == 32000000){
		cout << "-1\n";
		exit(0);
	}

	cout << mat[x][y] << "\n";

	return 0;
}