#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <set>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> numbers(n);
	for (int i = 0; i < n; ++i){
		cin >> numbers[i];
	}
	set<vector<int>> answer;
	int req;
	cin >> req;

	for (int i = 0; i < n; ++i){
        for (int j = i + 1; j < n; ++j){
            for (int k = j + 1; k < n; ++k){
                for (int p = k + 1; p < n; ++p){
                    if (numbers[i] + numbers[j] + numbers[k] + numbers[p] == req){
                        vector<int> squad;
                        squad.push_back(numbers[i]);
                        squad.push_back(numbers[j]);
                        squad.push_back(numbers[k]);
                        squad.push_back(numbers[p]);
                        sort(squad.begin(), squad.end());
                        answer.insert(squad);
                    }
                }
            }
        }
    }

    for (auto it = answer.begin(); it != answer.end(); ++it){
        cout << (*it)[0] <<" "<< (*it)[1] << " " << (*it)[2] << " " << (*it)[3] << "\n";
    }
    //O(n^4), класс

return 0;
}