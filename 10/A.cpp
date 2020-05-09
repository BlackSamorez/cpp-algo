#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void F(int n, int *b) {
        *b += n;
        if (n >= 3) {
            F(n / 2, b);
            F(n - 1, b);
        }
}


int main(){
	int *sum = new int;
	int a;
	*sum = 0;
	cin >> a;
	F(a, sum);
	cout << *sum << "\n";
	delete [] sum;
return 0;
}