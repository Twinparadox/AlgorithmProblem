#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	bool result = false, win = false;
	int size = 9;
	vector<int> ulim(size);
	vector<int> other(size);

	for (int i = 0; i < size; i++)
		cin >> ulim[i];
	for (int i = 0; i < size; i++)
		cin >> other[i];

	int u = 0, o = 0;
	for (int i = 0; i < size; i++)
	{
		u += ulim[i];
		if (u > o)
			win = true;

		o += other[i];
		if (u > o)
			win = true;
	}
	if (win == true)
		cout << "Yes";
	else
		cout << "No";
}