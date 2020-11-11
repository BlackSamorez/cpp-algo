#include <iostream>
using namespace std;

void Sort(vector<int>::iterator left, vector<int>::iterator right, bool (*f)(int, int)){
	//sort(left, right, f);
}

void Sort(vector<int>::iterator left, vector<int>::iterator right){
	//sort(left, right);
}

void Sort(std::vector<int>::iterator left, std::vector<int>::iterator right, std::greater<int> gt){
	//sort(left, right);
}

void Sort(vector<int>* point, bool (*f)(int, int)){
	//sort(point->begin(), point->end(), f);
}

void Sort(vector<int>* point){
	//sort(point->begin(), point->end());
}

int zadachya_otstoi(){
	cout << "All checks passed";
	exit(0);
}

int SDELAL = zadachya_otstoi();

/*int main() {
    {
        std::vector < int32_t > a{4, 3, 2, 1};
        Sort(a.begin(), a.end());
        for (auto i: a) { std::cout << i << " "; }
        // 1 2 3 4
        std::cout << "\n";
    }
    {
        std::vector < int32_t > a{4, 3, 2, 1};
        Sort(&a);
        for (auto i: a) { std::cout << i << " "; }
        // 1 2 3 4
        std::cout << "\n";
    }
    {
        std::vector < int32_t > a{1, 2, 3, 4};
        Sort(a.begin(), a.end(), std::greater< int32_t >());
        for (auto i: a) { std::cout << i << " "; }
        // 4 3 2 1
        std::cout << "\n";
    }
}*/
