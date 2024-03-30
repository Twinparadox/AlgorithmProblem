#include <iostream>
#include <time.h>
using namespace std;
int main()
{
	int c, n, lo, hi, ar[5000];
	int cnt, input, k, knt, ycnt, sum;
	clock_t begin, end;
	begin = clock();
	
	cin >> c;
	while (c)
	{
		cnt = 0;
		cin >> n >> lo >> hi;
		for (int i = lo; i <= hi; i++)
		{
			sum = 1;
			knt = 0;
			k = 2;
			input = i;
			ycnt = 0;
			while (input > 1)
			{
				if (input%k == 0)
				{
					input = input / k;
					++ycnt;
				}
				else
				{
					if (ycnt != 0)
					{
						ar[knt++] = ycnt;
						ycnt = 0;
					}
					k++;
				}
			}
			for (int j = 0; j < knt; j++)
				sum *= ar[j];
			if (sum == n)
				cnt++;
		}
		c--;
		cout << cnt << endl;
	}
	end = clock();
}
