#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h> 
using namespace std;

int Sposob(int x, int y, int N)
{   
   if (y == 8) return N;
   if (x==1)
    return Sposob(2, y+1, N);
   if (x==8)
    return Sposob(7, y+1, N);
  return Sposob(x+1, y+1, N) + Sposob(x-1, y+1, N);
}
int main()
{ int x, y;
    cin >> x >> y;
    cout << Sposob(x, y, 1) << "\n";
    return 0;
}