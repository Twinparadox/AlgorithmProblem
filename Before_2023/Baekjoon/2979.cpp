#include <iostream>
using namespace std;
int main(void)
{
	int a, b, c, time[101] = { 0, };
	int s, e, sum = 0;
	cin >> a >> b >> c;
	for (int i = 0; i < 3; i++)
	{
		cin >> s >> e;
		for (int j = s; j < e; j++)
			time[j]++;
	}
	for (int i = 1; i <= 100; i++)
	{
		if (time[i] == 1)
			sum += a;
		else if (time[i] == 2)
			sum += b * 2;
		else if (time[i] == 3)
			sum += c * 3;
	}
	cout << sum;
}
