void print_array(int* p){
		for (int i = 0; i < 6; i++){
			std::cout << p[i];
			if (i == 5){
				std::cout << "\n";
			} else {
				std::cout << " ";
			}
		}
	return;
	}
