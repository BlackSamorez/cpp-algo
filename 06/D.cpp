#include <iostream>
using std::cin;
using std::cout;
using std::endl;


int main(){
	int a, b, c;
	cin >> a >> b;
	c = do_some_awesome_work(&a, &b);
	cout << c << "\n";
}