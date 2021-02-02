#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int arr[1001][1001];
int dp[1001][1001];
int main() {
	int a, b, maxsum = 0;
	string s;
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		cin >> s;
		for (int j = 1; j <= b; j++) {
			arr[i][j] = s[j - 1] - '0';
		}
	}
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			if (arr[i][j] == 1) {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				maxsum = max(maxsum, dp[i][j]);
			}
		}
	}
	cout << maxsum * maxsum << "\n";
}