#include <iostream>
using namespace std;
int main(void)
{
	int apple = 0, banana = 0, point;
	for (int i = 0; i < 3; i++)
	{
		cin >> point;
		apple += point * (3 - i);
	}
	for (int i = 0; i < 3; i++)
	{
		cin >> point;
		banana += point * (3 - i);
	}
	if (apple > banana)
	{
		cout << 'A';
	}
	else if (apple < banana)
	{
		cout << 'B';
	}
	else
	{
		cout << 'T';
	}
}