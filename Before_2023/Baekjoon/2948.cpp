#include <iostream>
using namespace std;
int main(void)
{
	int m, d, sum = 0;
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	cin >> d >> m;
	for (int i = 0; i < m - 1; i++)
		sum += month[i];
	sum += (d - 1);
	switch (sum%7)
	{
	case 0:
		cout << "Thursday";
		break;
	case 1:
		cout << "Friday";
		break;
	case 2:
		cout << "Saturday";
		break;
	case 3:
		cout << "Sunday";
		break;
	case 4:
		cout << "Monday";
		break;
	case 5:
		cout << "Tuesday";
		break;
	case 6:
		cout << "Wednesday";
		break;
	default:
		break;
	}
}
