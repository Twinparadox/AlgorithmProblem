#include <iostream>
using namespace std;
int main(void)
{
	int n, tmp, y = 0, m = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		y += (tmp / 30) * 10;
		y += 10;
		m += (tmp / 60) * 15;
		m += 15;
	}
	if (y < m)
		cout << "Y " << y;
	else if (y > m)
		cout << "M " << m;
	else
		cout << "Y M " << y << '\n';
}
