#include <bits/stdc++.h>
using namespace std;
//模拟算法
int main()
{
	int h,m,s,T;
	cin >> h >> m >> s;
	cin >> T;
	int currentSeconds = 0;
	if (h<9)
		currentSeconds = h*3600+m*60+s;
	else if (h<17)
		currentSeconds = 9*3600+(h-9)*10000+m*100+s;
	else
		currentSeconds = 9*3600+8*10000+(h-17)*900+m*30+s;
	int futureSeconds = currentSeconds + T;
	int totalSeconds = 9*3600+8*10000+7*900;
	futureSeconds = futureSeconds % totalSeconds;
	if (futureSeconds < 9*3600)
	{
		h = futureSeconds / 3600;
		m = (futureSeconds - h*3600)/60;
		s = futureSeconds - h*3600 - m*60;
	}
	else if (futureSeconds < 9*3600+8*10000)
	{
		h = (futureSeconds - 9*3600)/10000 + 9;
		m = (futureSeconds - 9*3600-(h-9)*10000)/100;
		s = futureSeconds - 9*3600 - (h-9)*10000 - m*100;
	}
	else
	{
		h = (futureSeconds - 9*3600-8*10000)/900 + 17;
		m = (futureSeconds - 9*3600-8*10000-(h-17)*900)/30;
		s = futureSeconds - 9*3600 - 8*10000 - (h-17)*900 - m*30;
	}
	cout << h << " " << m << " " << s;
	return 0;
}
