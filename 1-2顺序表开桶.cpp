#include <iostream>
#include <vector>

int main() {
	using namespace std;
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector <int> numdata(m + 1, 0);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		numdata[x]++;
	}
	for (int i = 1; i <= m; i++) {
		cout << numdata[i] << endl;
	}
	cout << endl;
}
