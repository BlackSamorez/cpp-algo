#include <iostream>
#include <bitset>
using std::cin;
using std::cout;
using std::endl;
using std::bitset;


int main(){
	float v;
	cin >> v;
	cout << bitset<32>(*reinterpret_cast<unsigned long*>(&v)) << "\n";	
return 0;
}