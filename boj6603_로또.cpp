#include<iostream>
#include<vector>
using namespace std;
void DFS(int n, vector<int>& num, vector<int>&answer, int idx) {
	if (answer.size() > 6)
		return;
	if (answer.size() == 6) {
		for (int i = 0; i < 6; i++) {
			cout << num[answer[i]] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = idx + 1; i < n; i++) {
		if (answer.size() + (n - i) < 6)
			return;
		answer.push_back(i);
		DFS(n, num, answer, i);
		answer.pop_back();
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	while (cin >> n && n) {
		vector<int> num, v;
		num.assign(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}
		for (int i = 0; i < n; i++) {
			v.push_back(i);
			DFS(n, num, v, i);
			v.pop_back();
		}
		cout << "\n";
	}
}