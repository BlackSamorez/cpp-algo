#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void check_the_match(int *a, int &it, int k){
    int start = it;
    while (a[start] == a[it]) {
        it += k;
    }
    
}

void trinity(int *numbers, int &n) {
    
    sort(numbers, numbers + n);
    
    for (int it = 0; it < n; check_the_match(numbers, it, 1)) {
        auto left = it + 1;
        auto right = n - 1;
        while (left < right) {
            auto sum = numbers[it] + numbers[left] + numbers[right];
            if (sum < 0) {
                check_the_match(numbers, left, 1);
            } else if (sum > 0) {
                check_the_match(numbers, right, -1);
            } else {
                cout << numbers[it] << " " <<  numbers[left] << " " << numbers[right] << " ";
                check_the_match(numbers, left, 1);
                check_the_match(numbers, right, -1);
            }
        }
    }
}

int main(){
    int a;
    cin >> a;
    int* array = new int[a];

    for (int i = 0; i < a; ++i){
        cin >> array[i];
    }
    
    trinity(array, a);
    
    cout << "\n";
    
    delete [] array;
    
    return 0;
}