#include <bits/stdc++.h>
using namespace std;
//模拟（穷举）法：两层循环，寻找从i开始不大于V的最大值。时间复杂度为O(n^2)。
//贪心策略:设置滑动窗口，若未超过总量则尽可能向右扩张，否则左边界右移。时间复杂度O(n).
int main() 
{
    int n, V;
    cin >> n >> V;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0, curv = 0, maxv = 0;
    for (int r = 0; r < n; r++) 
	{
        curv += a[r];
        while (curv > V && l <= r) 
		{
            curv -= a[l];
            l++;
        }
        if (curv <= V)
            maxv = max(maxv, curv);
    }
    cout << maxv;
    return 0;
}
