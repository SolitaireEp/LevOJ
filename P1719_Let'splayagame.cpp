#include <bits/stdc++.h>
using namespace std;
/*元素删除，最多删次数n，尽可能少地删除。
尽可能让需要删除的数字落在2的次幂的位置上。
我们要计算待删除数字离2的次幂有多远。
新数组：描述的是待删除数据到直接删除的次数。
删除：
  当数字刚好落在2的次幂上，直接删除，串行；
  如果数字不是落在2的次幂上，前面删除的数字一定会让后面的数字往前挪一位并行删除。*/
int main()
{
	int n,k,i;
	cin>>n>>k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<int> dis;
	int base =1;
	for(i=0;i<=n;i++)
	{
		if(i>=base*2)
			base=base*2;
		if (a[i-1]==k)
			dis.push_back(i-base);
	}
	int num=0;
	for( i=0; i < (int)dis.size();i++)
		num=max(dis[i],num)+1;
	cout<<num;
	return 0;
}
