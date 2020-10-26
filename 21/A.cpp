#include <iostream>
#include <vector>
#include <map>

int size = 100000;

int main(){
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(nullptr);
	
	int n, m;
	std::cin >> n >> m;
	std::vector<std::map<std::pair<int, int>, int>> data(size);
	
	int index, key, value;
	char op;

	for (int i = 0; i < m; ++i){
		std::cin >> index >> op >> key >> value;
		if (op == '+'){
			data[key * (index + 1) % size][{index, key}] = value;
		}
		if (op == '?'){
			auto place = data[key * (index + 1) % size].find({index, key});
			if (place != data[key * (index + 1) % size].end()){
				std::cout << place->second << "\n";
			} else {
				std::cout << value << "\n";
			}
		}
		if (op == '-'){
			data[key * (index + 1) % size].erase({index, key});
		}
	}
return 0;
}