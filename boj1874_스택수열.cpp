#include<iostream>
//#include<stack>
//#include<vector>
using namespace std;
int main() {
    int n, data, max_num = 0, nidx = 0, cidx = 0;
	//stack<int> st;
    //vector<char> v;
	cin >> n;
    int* nst = new int[n];
    char* cst = new char[2 * n];
	while (n--) {
		cin >> data;
        if (data > max_num) {
            for (int i = max_num + 1; i <= data; i++) {
                //st.push(i);
                //v.push_back('+');
                nst[nidx++] = i;
                cst[cidx++] = '+';
            }
        }
        else {
            if (nst[nidx - 1] != data) {
                //if (st.top() != data) {
                cout << "NO";
                return 0;
            }
        }
        //st.pop();
        //v.push_back('-');
        nst[--nidx] = 0;
        cst[cidx++] = '-';
        if (max_num < data) {
            max_num = data;
        }
	}
    //for (int i = 0; i < v.size(); i++) {
        //cout << v[i] << " ";
    //}
    cout << "\n";
    for (int i = 0; i < cidx; i++) {
        cout << cst[i] << " ";
    }
}