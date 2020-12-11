//DOESN'T WORK


#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int trace(vector<vector<int>>* lab, vector<pair<int, int>>* path){
	int r = 32000000, l = 32000000, u = 32000000, d = 32000000;
	int x, y;

	pair<int ,int> coord;

	int n = (*lab).size();
	int m = ((*lab)[0]).size();

	//right
	//cout << "r1\n";
	x = (*path).back().first;
	y = (*path).back().second;

	while (y < m - 1 and !(*lab)[x][y + 1]){
		y++;
	}

	coord = {x, y};

	if (y != m - 1 and (*lab)[x][y + 1] == 2){
		cout << (*path).size() << "tr\n";
		return (*path).size();
	}

	if (y != m - 1 and (*lab)[x][y + 1] == 1 and find((*path).begin(), (*path).end(), coord) == (*path).end()){
		(*path).push_back({x, y}); 
		r = trace(lab, path);
	}

	if (y == m - 1 and find((*path).begin(), (*path).end(), coord) == (*path).end()){
		(*path).push_back({x, y}); 
		r = trace(lab, path);
	}

	//left
	//cout << "l1\n";
	x = (*path).back().first;
	y = (*path).back().second; 

	while (y > 0 and !(*lab)[x][y - 1]){
		y--;
	}

	coord = {x, y};

	if (y != 0 and (*lab)[x][y - 1] == 2){
		cout << (*path).size() << "tr\n";
		return (*path).size();
	}

	if (y != 0 and (*lab)[x][y - 1] == 1 and find((*path).begin(), (*path).end(), coord) == (*path).end()){
		(*path).push_back({x, y}); 
		l = trace(lab, path);
	}

	if (y == 0 and find((*path).begin(), (*path).end(), coord) == (*path).end()){
		(*path).push_back({x, y}); 
		l = trace(lab, path);
	}

	//down
	//cout << "d1\n";
	x = (*path).back().first;
	y = (*path).back().second; 

	while (x < n - 1 and !(*lab)[x + 1][y]){
		x++;
		cout << x << "down\n";
	}

	coord = {x, y};

	if (x != n - 1 and (*lab)[x + 1][y] == 2){
		cout << (*path).size() << "tr\n";
		return (*path).size();
	}

	if (x != n - 1 and (*lab)[x + 1][y] == 1 and find((*path).begin(), (*path).end(), coord) == (*path).end()){
		(*path).push_back({x, y}); 
		d = trace(lab, path);
	}

	if (x == n - 1 and find((*path).begin(), (*path).end(), coord) == (*path).end()){
		(*path).push_back({x, y}); 
		d = trace(lab, path);
	}

	//up
	//cout << "u1\n";
	x = (*path).back().first;
	y = (*path).back().second; 

	while (x > 0 and !(*lab)[x - 1][y]){
		x--; 
	}

	coord = {x, y};

	if (x != 0 and (*lab)[x - 1][y] == 2){
		cout << (*path).size() << "tr\n";
		return (*path).size();
	}

	if (x != 0 and (*lab)[x - 1][y] == 1 and find((*path).begin(), (*path).end(), coord) == (*path).end()){
		(*path).push_back({x, y}); 
		u = trace(lab, path);
	}

	if (x == 0 and find((*path).begin(), (*path).end(), coord) == (*path).end()){
		(*path).push_back({x, y}); 
		u = trace(lab, path);
	}

	(*path).pop_back();

	return min(min(r, l), min(u, d));
}

int main(){
	int n, m;
	std::cin >> n >> m;

	vector<vector<int>> lab(n, vector<int>(m, 0));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> lab[i][j];
		}
	}

	vector<pair<int, int>> path = {{0, 2}};
	int incl;
	incl = trace(&lab, &path);

	for (int i = 0; i < path.size(); ++i)
	{
		cout << path[i].first << " " << path[i].second << "\n";
	}

	cout << incl << "\n";

return 0;
}