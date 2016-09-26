#include <iostream>
using namespace std;
int main()
{
	int a[10], b[10], awin = 0, bwin = 0, i;
	for (i = 0; i < 10; i++)
		cin >> a[i];
	for (i = 0; i < 10; i++)
		cin >> b[i];
	for (i = 0; i < 10; i++)
	{
		if (a[i]>b[i])
			awin++;
		else if (a[i] < b[i])
			bwin++;
	}
	if (awin == bwin)
		cout << "D";
	else if (awin > bwin)
		cout << "A";
	else
		cout << "B";
	return 0;
}