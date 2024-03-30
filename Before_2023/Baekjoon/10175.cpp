#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	while (n--)
	{
		string area, species;
		cin >> area >> species;

		int len = species.length(), s[4] = { 0, };
		for (int i = 0; i < len; i++)
		{
			switch (species[i])
			{
			case 'B':
				s[0] += 2;
				break;
			case 'C':
				s[1] += 1;
				break;
			case 'M':
				s[2] += 4;
				break;
			case 'W':
				s[3] += 3;
				break;
			default:
				break;
			}
		}

		int max = s[0];
		for (int i = 1; i < 4; i++)
			if (max < s[i])
				max = s[i];

		int check = 0, idx = 0;
		for (int i = 0; i < 4; i++)
			if (max == s[i])
				check++, idx = i;

		cout << area << ": ";

		if (check > 1)
			cout << "There is no dominant species";
		else
		{
			switch (idx)
			{
			case 0:
				cout << "The Bobcat is the dominant species";
				break;
			case 1:
				cout << "The Coyote is the dominant species";
				break;
			case 2:
				cout << "The Mountain Lion is the dominant species";
				break;
			case 3:
				cout << "The Wolf is the dominant species";
				break;
			default:
				break;
			}
		}
		cout << "\n";
	}
}