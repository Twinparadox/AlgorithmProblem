#include <iostream>
using namespace std;
int main(void)
{
	const int SIZE = 100;
	int n, tmp, cnt = 0;
	bool seat[101];
	for (int i = 1; i <= SIZE; i++)
		seat[i] = false;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (seat[tmp] == false)
			seat[tmp] = true;
		else
			cnt++;
	}
	cout << cnt;
}
