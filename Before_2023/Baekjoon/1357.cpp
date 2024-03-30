#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int xr, yr, res;
	string x, y, rex = "", rey = "", result = "";
	cin >> x >> y;
	for (int i = x.length() - 1; i >= 0; i--)
		rex += x[i];
	for (int i = y.length() - 1; i >= 0; i--)
		rey += y[i];
	xr = stoi(rex);
	yr = stoi(rey);
	res = xr + yr;
	x = to_string(res);
	for (int i = x.length() - 1; i >= 0; i--)
		result += x[i];
	res = stoi(result);
	cout << res;
}
