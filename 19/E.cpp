#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h> 
using namespace std;

int main() {
    int num;
    int iszero = 0;
    vector<int> vec;
    while (!iszero){
    	cin >> num;
    	if (num == 0){
    		iszero = 1;
    	}
    	if (num > 0){
    		vec.push_back(num);
    	} 
    	if (num < 0){
    		if (vec.size() > 0){
    			if (vec[vec.size() - 1] > -num){
    				vec[vec.size() - 1] += num;
    			} else {
    				vec.pop_back();
    			}
    		}
    	}
    }
    if (vec.size() > 0){
    	cout << vec.size() << " " << vec[vec.size() - 1] << "\n";
    } else {
    	cout << "0 -1\n";
    }
return 0;
}