#include <iostream>

using namespace std;

int main()
{
    int N,s = 0;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    for (int l = 1; l < N; l++){
        for (int i = 1; i < N; i++){
            int j = i - 1;
            while (((A[i] != 0 and  A[i] * A[j] <= 0)  or (A[i] == 0 and A[j] <= 0)) and j >= 0 ){
                    j--;
            }
            if (j >= 0 and  ((( abs(A[j]) > abs(A[i])) and (A[i] != 0)) or ((A[i] == 0) and (A[j] > 0)) )){
                    A[j] = A[j] + A[i];
                    A[i] = A[j] - A[i];
                    A[j] = A[j] - A[i];
                    for (int k = 0; k < N; k++){
                        cout << A[k] << " ";
                    }
                    cout << endl;
            }
        }
    }
    return 0;
}