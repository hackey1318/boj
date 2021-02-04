#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int arr[21][21];
int n, result = 987654321;
void DFS(string s, int start_team, int link_team) {
	if (s.size() == n) {
		vector<int> start, link;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '1')
				start.push_back(i);
			else
				link.push_back(i);
		}
		int start_state = 0, link_state = 0;
		for (int i = 0; i < start.size(); i++) {
			for (int j = i + 1; j < start.size(); j++) {
				start_state += (arr[start[i]][start[j]] + arr[start[j]][start[i]]);
			}
		}
		for (int i = 0; i < link.size(); i++) {
			for (int j = i + 1; j < link.size(); j++) {
				link_state += (arr[link[i]][link[j]] + arr[link[j]][link[i]]);
			}
		}
		result = min(result, abs(start_state - link_state));
		return;
	}
	if (start_team < (n / 2))
		DFS(s + "1", start_team + 1, link_team);
	if (link_team < (n / 2))
		DFS(s + "0", start_team, link_team + 1);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	DFS("", 0, 0);
	cout << result;
}