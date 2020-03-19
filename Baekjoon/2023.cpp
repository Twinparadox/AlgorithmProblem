#include <iostream>
using namespace std;
int N;
int sosu(int N)
{
	for (int i = 2; i*i < N; i++)
		if (N%i == 0)
			return false;
	return true;
}
void print(int len, int last, int three)
{
	if (len == N)
	{
		if (sosu(last))
			cout << last << '\n';
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			if (i % 2 == 0 || i == 5)
				continue;

			if ((three + i) % 3 == 0)
				continue;

			if (sosu(last * 10 + i))
				print(len + 1, last * 10 + i, three + i);
		}
	}
}
int main(void)
{
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;

	print(1, 2, 2);
	print(1, 3, 3);
	print(1, 5, 5);
	print(1, 7, 7);
}