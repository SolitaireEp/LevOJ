#include<bits/stdc++.h>
using namespace std;

array<int, 201> toIntArray(string num)
{
	array<int, 201> arr{};
	for(int i=num.size()-1;i>=0;i--)
	{
		arr[num.size()-i-1]=num[i]-'0';
	}
	return arr;
}

int main()
{
	string a,b;
	cin >> a;
	cin >> b;
	array<int, 201> aArr = toIntArray(a);
	array<int, 201> bArr = toIntArray(b);
	int increase = 0;
	int totallen = max(a.size(),b.size());
	for(int i=0; i<totallen;i++)
	{
		aArr[i] = aArr[i] + bArr[i] + increase;
		increase = aArr[i] / 10;
		aArr[i] = aArr[i] % 10;
	}
	if(increase!=0)
	{
		aArr[totallen] = increase;
		totallen++;
	}
	for(int i=totallen-1;i>=0;i--)
		cout << aArr[i];
	return 0;
}
