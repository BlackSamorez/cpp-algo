#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h> 
using namespace std;

void subvec(vector<int>* v){
    for (int i = 0; i < v->size(); i++){
        for (int j = 0; j <= i; j++){
            cout << v[0][j] << " ";   
        }
        cout << "\n";
    }
    if (v->size() != 1){
        v->erase(v->begin());
        subvec(v);
    }
}   

vector<int> getclause() {
  char c;
  vector<int> cl;
  std::string line;
  std::getline(cin, line);
  std::istringstream iss(line);
  while ( iss >> c) {    
    cl.push_back(c - '0');
  }
  return cl;
}

int main(){
    vector<int> v;
    v = getclause();
    subvec(&v);
return 0;
}