#include <bits/stdc++.h>
using namespace std;
//模拟（穷举）法：两层循环，寻找从i开始不大于V的最大值。时间复杂度为O(n^2)。
//贪心策略:设置滑动窗口，若未超过总量则尽可能向右扩张，否则左边界右移。时间复杂度O(n).
int main()
{
  int n,V,i,l=0,r=0;
	int curv=0,maxv=0;
	cin>>n>>V;
	vector<int> a(n);
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	while(true)
	{
		if(curv<=V)
		{
			maxv=max(curv,maxv);
			r++;
			if(r==n) break;
			curv=curv+a[r];
		}
		else
		{
			l++;
			curv=curv-a[l];
		}
	}
	cout<<maxv;
	return 0;
}
