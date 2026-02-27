#include <iostream>
#include <vector>

using namespace std;
int main() {
	int N;
	cout << " Input size Array N ";
	cin >> N;

	vector<int> A(N);
	cout << " Input Array A \n";
	for (int i = 0; i < N; i++) {
		cout << " A[ " << i << "] ";
		cin >> A[i];
	}
	int countzero = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] == 0) {
			countzero++;
		}
	}
	cout << " Count zero = " << countzero << endl;
	return 0;

}
