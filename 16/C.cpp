#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<int> arr;
    int tmp;
    while (cin >> tmp)
        arr.push_back(tmp);
    int n = arr.size();
    for (int i = 0; i < n; i++){
        for (int k = 0; k <= i; k++){
            for (int j = k; j <= i; j++)
                cout << arr[j] << " ";
            cout << endl;
        }
    }
}
