#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	for (int T = 1;; T++)
	{
		string str1, str2;
		cin >> str1 >> str2;

		if (str1 == "END" && str2 == "END")
			break;

		cout << "Case " << T << ": ";
		int len1 = str1.length(), len2 = str2.length();
		if (len1 != len2)
		{
			cout << "different\n";
		}
		else
		{
			vector<int> arr1(26, 0), arr2(26, 0);
			for (int i = 0; i < len1; i++)
				arr1[str1[i] - 'a']++;
			for (int i = 0; i < len2; i++)
				arr2[str2[i] - 'a']++;

			bool check = false;
			for (int i = 0; i < 26; i++)
			{
				if (arr1[i] != arr2[i])
				{
					check = true;
					break;
				}
			}
			if (check)
				cout << "different\n";
			else
				cout << "same\n";
		}
	}
}