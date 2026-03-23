#include <stdio.h>
int joseph(int numbers, int k, int i) //Josephus问题-https://oi-wiki.org/misc/josephus/
{
	if (i == 1)
		return (k - 1) % numbers + 1;
	return (joseph(numbers - 1, k, i - 1) + k - 1) % numbers + 1; //递归
}
int next_k(int k, int number) //优化技巧！快速跳过一个无效的 k 区间从而减少尝试次数（一开始TLE原因）
{
	if (number % k == 0)
		return k + number / 2 + 1;
/*当 k 能整除 2m 时，约瑟夫淘汰过程会呈现周期性。例如，第一个被淘汰的人是 (k-1) % (2m) + 1，后续的淘汰位置会按照 k 的倍数在环上移动。
在这种情况下，前 m 个被淘汰的人中很可能已经包含了好人（编号 ≤ m）。而如果我们只增加 1，可能会连续很多个 k 都仍然导致好人被淘汰。
通过跳转到 k + m + 1，可以避开这一整段“危险区域”，因为 k 与 k + m + 1 在模 2m 的意义下会改变淘汰顺序的“相位”，从而更快找到可行解。*/
	else
		return k + 1;
}

int main()
{
	int m,i;
	scanf("%d", &m);
	int total = m * 2 , k = m + 1;
	for (i = 0; i < m; i++)
	{
		if (joseph(total, k, i + 1) <= m)
		{
			i = -1;
			k = next_k(k, total);
			continue;
		}
	}
	printf("%d", k);
	return 0;
}
