#include <iostream>
#include <bitset>
using std::cin;
using std::cout;
using std::endl;
using std::bitset;


int main(){
	float a, b;
	a = 0.000000000000000000000000000000000000000000001;
	b = 1;
	//Проверим денормализованные числа
	cout << a << "\n";
	//Они есть

	//Проверим скорости
	uint64_t max = 10000000000;
	for (uint64_t i = 0; i < max; i++){
		a = a * 1;
	}
	cout << a << "\n";
	//26 секунд
	for (uint64_t i = 0; i < max; i++){
		b = b * 1;
	}
	cout << b << "\n";
	//26 секунд - не вижу разницы в производительности


return 0;
}