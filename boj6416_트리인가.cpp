#include<iostream>
#include<unordered_set>
using namespace std;
int main() {
	int k = 1, u, v, cnt = 0;
	unordered_set<int> node;
	while (1) {
		cin >> u >> v;
		if (u == -1 && v == -1) {
			break;
		}
		else if (u == 0 && v == 0) {
			if (cnt == 0 || node.size() == cnt + 1) {
				cout << "Case " << k++ << " is a tree.\n";
			}
			else {
				cout << "Case " << k++ << " is not a tree.\n";
			}
			node.clear();
			cnt = 0;
			continue;
		}
		node.insert(u);
		node.insert(v);
		cnt++;
	}
}