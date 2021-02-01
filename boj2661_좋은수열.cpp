#include<iostream>
#include<string>
using namespace std;
void func_num(char c, int n, int cnt, string s) {
	if (cnt - 1 == n) {
		cout << s << "\n";
		exit(0);
	}
	s += c;
	for (int i = 1; i <= cnt / 2; i++) {
		string a = s.substr(cnt - i, i), b = s.substr(cnt - i * 2, i);
		if (!a.compare(b)) {
			s.erase(cnt - 1);
			return;
		}
	}
	for (int i = 1; i <= 3; i++)
		func_num(i + '0', n, cnt + 1, s);
	s.erase(cnt - 1);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= 3; i++) {
		func_num(i + '0', n, 1, "");
	}
}