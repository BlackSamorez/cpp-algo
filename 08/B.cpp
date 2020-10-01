#include <iostream>
#include <bitset>
#include <array>
using std::cin;
using std::cout;
using std::endl;
using std::bitset;


int main(){
	int n;
	cin >> n;
	int numbers[n];
	int bad[n];
	int nbad = 0;
	for (int i = 0; i < n; i++){
		cin >> numbers[i];
		if (((numbers[i] % 4 == 0) and (numbers[i] / 1000 != 4) and (numbers[i] / 1000 != 5)) or ((numbers[i] % 7 == 0) and (numbers[i] / 1000 != 7) and (numbers[i] / 1000 != 1)) or ((numbers[i] % 9 == 0) and (numbers[i] / 1000 != 9) and (numbers[i] / 1000 != 8))){
			bad[nbad] = numbers[i];
			nbad++;
		}
	}
	for (int i = 0; i < nbad - 1; i++){
		cout << bad[i] << "\n";
	}
	if (nbad != 0){
		cout << bad[nbad - 1] << "\n";
	} else {
		cout << "0\n";
	}

return 0;
}