#include<stdio.h>//程序填空
int main() {
	int n, numOfZero = 0, numOfTwo = 0, numOfFive = 0;
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp == 0) numOfZero++;
		else if (tmp == 2) numOfTwo++;
		else if (tmp == 5) numOfFive++;
	}
	int mn = numOfZero;
	if (numOfTwo / 2 < mn) mn= numOfTwo / 2;
	if (numOfFive < mn) mn = numOfFive;
	printf("%d",mn);
	return 0;
}
