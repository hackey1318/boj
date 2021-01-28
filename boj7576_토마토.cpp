#include<iostream>
#include<queue>
using namespace std;
const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };
int map[1001][1001];
int n, m, emp;
queue<pair<int, int>>q;
bool finish(int t) {
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1)
				cnt++;
		}
	}
	return t == cnt;
}
int BFS(int n, int m, int t) {
	int day = 0;
	while (!q.empty()) {
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			pair<int, int> pos = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = pos.first + dy[i], nx = pos.second + dx[i];
				if (0 <= ny && ny < m && 0 <= nx && nx < n && map[ny][nx] == 0) {
					map[ny][nx] = 1;
					q.push(make_pair(ny, nx));
				}
			}
			if (q.size() == 0 && finish(t)) {
				return day;
			}
			else if (q.size() == 0 && !finish(t)) {
				return -1;
			}
		}
		day++;
	}
	return -1;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));
			}
			else if (map[i][j] == -1) {
				emp++;
			}
		}
	}
	if (q.size() == n * m - emp) {
		cout<<"0\n";
	}
	else {
		int result = BFS(n, m, n * m - emp);
		cout << result;
	}
}