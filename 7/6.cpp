#include <iostream>
#include <bitset>
using std::cin;
using std::cout;
using std::endl;
using std::bitset;


int main(){
	float a, b, c, d, e;
	a = 0.00000000000000000000001;
	b = 1;
	c = 10000000000000000;
	d = a * a * c * c;
	e = a * c * a * c;
	cout << d << " " << e << "\n";
return 0;
}