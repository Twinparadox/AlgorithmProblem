#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	double A[7] = { 9.23076, 1.84523, 56.0211, 4.99087, 0.188807, 15.9803, 0.11193 },
		B[7] = { 26.7, 75, 1.5, 42.5, 210, 3.8, 254 },
		C[7] = { 1.835, 1.348, 1.05, 1.81, 1.41, 1.04, 1.88 };
	int t;
	cin >> t;
	while (t--)
	{
		int p[7];
		double result[7], sum = 0;;
		for (int i = 0; i < 7; i++)
		{
			cin >> p[i];
			if (i == 0 || i == 3 || i == 6)
				result[i] = floor(A[i] * pow((B[i] - p[i]), C[i]));
			else
				result[i] = floor(A[i] * pow((p[i] - B[i]), C[i]));
			sum += result[i];
		}
		cout << (int)sum << '\n';
	}
}
