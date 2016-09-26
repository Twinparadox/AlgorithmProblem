#include <stdio.h>

int main()
{
	int cows[80000];
	int n;
	int cn = 0;
	long long sum = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int hi;
		scanf("%d", &hi);
		while (cn > 0 && cows[cn - 1] <= hi) cn--;
		sum += cn;
		cows[cn++] = hi;
	}
	printf("%u\n", sum);
}