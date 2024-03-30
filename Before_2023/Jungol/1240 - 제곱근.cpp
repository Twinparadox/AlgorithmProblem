#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	long long src;
	cin >> src;
	int NUM_REPEAT = 100000;
	int i;
	double j;
	if (src == 1)
	{
		cout << "1";
	}
	else
	{
		double buf = (double)src;
		for (i = 0, j = buf; i < NUM_REPEAT; i++)
		{
			if (j < 1.0000)
				break;
			j = (j*j + buf) / (2.00*j);
		}
		j -= 0.5;
		cout << fixed << setprecision(0) << j;
	}
	return 0;
}