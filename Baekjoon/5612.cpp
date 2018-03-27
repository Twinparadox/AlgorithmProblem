#include <iostream>
using namespace std;
int main(void)
{
	int max = -1, car, n, in, out;
	bool check = true;
	cin >> n >> car;
	for (int i = 0; i < n; i++)
	{
		cin >> in >> out;
		car += (in - out);
		if (max < car)
			max = car;
		if (car < 0)
			check = false;
	}
	if (check)
		cout << max;
	else
		cout << 0;
}
