#include <iostream>
using namespace std;
int main(void)
{
	int t, n;
	long long koong[68] = { 1,1,2,4, };
	for (int i = 4; i <= 67; i++)
		koong[i] = koong[i - 1] + koong[i - 2] + koong[i - 3] + koong[i - 4];
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << koong[n] << "\n";
	}
}
