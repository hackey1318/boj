#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j < n - (i + 1)) {
				cout << " ";
			}
			else {
				cout << "*";
			}
		}
		for (int j = n; j < 2 * n - 1; j++) {
			if (j < n + i) {
				cout << "*";
			}
			else {
				break;
			}
		}
		cout << "\n";
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j < i) {
				cout << " ";
			}
			else {
				cout << "*";
			}
		}
		for (int j = n; j < 2 * n - 1; j++) {
			if (j < 2 * n - 1 - i) {
				cout << "*";
			}
			else {
				break;
			}
		}
		cout << "\n";
	}
}