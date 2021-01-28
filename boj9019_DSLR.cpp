#include<iostream>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
const int MAX = 10000;
bool visited[MAX];

string BFS(int s, int e) {
	queue<pair<int, string>>q;
	q.push(make_pair(s, ""));
	visited[s] = true;
	while (!q.empty()) {
		int pos_num = q.front().first;
		string s = q.front().second;
		q.pop();
		if (pos_num == e) {
			return s;
		}
		int num = (2 * pos_num) % MAX;	// 1 D
		if (!visited[num]) {
			visited[num] = true;
			q.push(make_pair(num, s + "D"));
		}
		num = (pos_num - 1) < 0 ? 9999 : pos_num - 1;	// 2 S
		if (!visited[num]) {
			visited[num] = true;
			q.push(make_pair(num, s + "S"));
		}
		num = (pos_num % 1000) * 10 + pos_num / 1000;	// 3 L
		if (!visited[num]) {
			visited[num] = true;
			q.push(make_pair(num, s + "L"));
		}
		num = (pos_num % 10) * 1000 + (pos_num / 10);	// 4 R
		if (!visited[num]) {
			visited[num] = true;
			q.push(make_pair(num, s + "R"));
		}
	}
}
int main() {
	int t, s, e;
	cin >> t;
	for (int i = 0; i < t; i++) {
		memset(visited, false, sizeof(visited));
		cin >> s >> e;
		cout << BFS(s, e) << "\n";
	}
}