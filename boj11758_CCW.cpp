#include<iostream>
using namespace std;
typedef long long ll;
typedef struct Point {
	int x, y;
	Point(){}
	Point(int x, int y) :x(x), y(y) {}
};
int CCW(Point &A, Point &B, Point &C) {
	return (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
}
int main() {
	Point p[3];
	for (int i = 0; i < 3; i++) {
		cin >> p[i].x >> p[i].y;
	}
	int ccw = CCW(p[0], p[1], p[2]);
	if (ccw > 0) {
		cout << "1\n";
	}
	else if (ccw == 0) {
		cout << "0\n";
	}
	else {
		cout << "-1\n";
	}
}