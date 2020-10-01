#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h> 
using namespace std;

bool compareFirstNode(const vector<int> v1, const vector<int> v2) 
{ 
    return (v1[0] < v2[0]); 
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> data(n, vector<int> (3));
    for (int i=0; i < n; i++){
    	cin >> data[i][0] >> data[i][1] >> data[i][2];
    }
    sort(data.begin(), data.end(), compareFirstNode);
    int nodes = data[n - 1][0] + 1;
    int place = 0;
    for (int i=0; i<nodes; i++){
    	int occ = 0;
    	int sum = 0;
    	while (data[place][0] == i){
    		occ += 1;
    		sum += data[place][2];
    		if (place != n - 1){
    			place++;
    		} else {
    			break;
    		}
    	}
    	cout << i << " " << occ << " " << sum << "\n";
    }
return 0;
}