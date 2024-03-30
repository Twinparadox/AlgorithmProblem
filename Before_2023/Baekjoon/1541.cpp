#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	int len, start, end;
	string str, substr = "";
	vector<int> intArr;
	vector<char> opArr;

	cin >> str;
	len = str.length();
	start = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '+' || str[i] == '-')
		{
			end = i;
			substr = str.substr(start, end - start);
			start = i + 1;
			intArr.push_back(stoi(substr));
			opArr.push_back(str[i]);
		}
		else if (i == len - 1)
		{
			substr = str.substr(start, len - start);
			intArr.push_back(stoi(substr));
		}
	}

	int opSize, opFlag = 1, ans = intArr[0];
	opSize = opArr.size();
	for (int i = 0; i < opSize; i++)
	{
		if (opArr[i] == '+')
		{
			if (opFlag)
				ans += intArr[i + 1];
			else
				ans -= intArr[i + 1];
		}
		else
		{
			if (opFlag)
			{
				opFlag = 0;
				ans -= intArr[i + 1];
			}
			else
			{
				ans -= intArr[i + 1];
			}
		}
	}

	cout << ans;
}