#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	vector<int> nemo(4);
	nemo[0] = 'n' - 'a';
	nemo[1] = 'e' - 'a';
	nemo[2] = 'm' - 'a';
	nemo[3] = 'o' - 'a';
	while (1)
	{
		string str;
		getline(cin, str);
		if (str == "EOI")
			break;

		int len, idx;
		len = str.length();
		bool check = false;
		for (int i = 0; i < len - 4 && !check; i++)
		{
			if (str[i] == 'N' || str[i] == 'n')
			{
				bool flags = false;
				for (int j = i; j < i + 4; j++)
				{
					int asci;
					if (str[j] >= 'A' && str[j] <= 'Z')
						asci = str[j] - 'A';
					else if (str[j] >= 'a' && str[j] <= 'z')
						asci = str[j] - 'a';
					else
					{
						flags = true;
						break;
					}
					if (asci != nemo[j - i])
					{
						flags = true;
						break;
					}
				}

				if (!flags)
					check = true;
			}
		}

		if (check)
			cout << "Found\n";
		else
			cout << "Missing\n";
	}
}