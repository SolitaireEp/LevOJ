#include <iostream>

int main() {
	using namespace std;
	cin.tie(nullptr)->sync_with_stdio(false);

	int i, j, d0, dij,x,y;
	int cols,dxy;
	cin >> d0 >> i >> j  >> dij;
	cin >> x >> y;
	cols = (dij - d0 -j) /i;
	dxy = d0 + (cols * x) + y;
	cout << dxy << endl;
	return 0;
}
