#include <iostream>
using namespace std;
int main(void)
{
	int n, m, vest = 0, helmet = 0, v, h;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> h;
		if (h > helmet)
			helmet = h;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> v;
		if (v > vest)
			vest = v;
	}
	cout << helmet + vest;
}
