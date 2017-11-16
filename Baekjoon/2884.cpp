#include <iostream>
using namespace std;
int main(void)
{
	int h, m;
	int setH, setM;
	cin >> h >> m;
	if (h == 0 && m < 45)
		setH = 23, setM = (60 + m) - 45;
	else
	{
		if (m < 45)
			setH = h - 1, setM = (60 + m) - 45;
		else
			setH = h, setM = m - 45;
	}
	cout << setH << ' ' << setM;
}