#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int N, len;
	string origin, dest;
	bool check = true;

	cin >> N;
	cin >> origin >> dest;

	len = origin.length();
	if (N % 2 == 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (origin[i] != dest[i])
			{
				check = false;
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			if (origin[i] == dest[i])
			{
				check = false;
				break;
			}
		}
	}

	if (check)
		cout << "Deletion succeeded";
	else
		cout << "Deletion failed";
}