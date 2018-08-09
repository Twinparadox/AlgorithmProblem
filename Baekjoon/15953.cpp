#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	std::ios::sync_with_stdio(false);
	int t, a, b;
	int ap[6] = { 500,300,200,50,30,10 }, bp[5] = { 512,256,128,64,32 };
	cin >> t;
	while (t--)
	{
		int sum = 0, rank;
		cin >> a >> b;
		if (a != 0)
		{
			rank = 0;
			for (int i = 1; i <= 6; i++)
			{
				rank += i;
				if (rank - i < a && rank >= a)
				{
					sum += ap[i - 1];
					break;
				}
			}
		}
		if (b != 0)
		{
			rank = 0;
			for (int i = 0; i < 5; i++)
			{
				rank += pow(2, i);
				if (rank - pow(2, i) < b && rank >= b)
				{
					sum += bp[i];
					break;
				}
			}
		}
		cout << sum * 10000 << '\n';
	}
}
