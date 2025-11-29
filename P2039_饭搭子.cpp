#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,W;
	cin>>n>>W;
	vector<int> f(n);
	for(int i=0;i<n;i++) cin>>f[i];
	sort(f.begin(),f.end());
	int num=0;
	for(int i=0,j=n-1;i<=j;j--)
	{
		if(f[i]+f[j]<=W)
			i++;
		num++;
	}
	cout<<num;
	return 0;
}
