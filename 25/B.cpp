#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> tree(0, vector<int>(3));

bool walk(int place, int small, int big){
	if (place == -1){
		return true;
	}
	if (tree[place][0] >= big || tree[place][0] < small){
		//cout << small << " " << tree[place][0] << " " << big << " ";
		return false;
	}
	return (walk(tree[place][1], small, tree[place][0]) && walk(tree[place][2], tree[place][0], big));
}

int main(){
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i){
		vector<int> tmp = {0, 0, 0};
		cin >> tmp[0] >> tmp[1] >> tmp[2];
		tree.push_back(tmp);
	}

	int small = -320000;
	int big = 320000;

	bool valid;
	valid = walk(0, small, big);

	if (valid){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

return 0;
}