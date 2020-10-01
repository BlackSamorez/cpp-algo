#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
}

void generator(bool* free_num, int *n, int free_slots, int new_str, int *out) {
  if (free_slots == 0) {
    if (isPrime(new_str)){
    	*out = *out + 1;
    }
  } else {
    for (int i = 0; i < *n; i++) {
      if (free_num[i]) {
        free_num[i] = false;
        generator(free_num, n, free_slots - 1, new_str * 10 + i + 1, out);
        free_num[i] = true;
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  bool free_num[n];
  for (int i = 0; i < n; i++)
    free_num[i] = 1;
  int *out = new int;
  *out = 0;
  generator(free_num, &n, m, 0, out);
  cout << *out << endl;
}
