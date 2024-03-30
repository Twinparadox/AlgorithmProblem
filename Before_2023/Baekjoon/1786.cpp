#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> getTable(string subStr)
{
	int len = subStr.length(), j = 0;
	vector<int> table(len, 0);

	for (int i = 1; i < len; i++)
	{
		while (j && subStr[i] != subStr[j])
			j = table[j - 1];

		if (subStr[i] == subStr[j])
			table[i] = ++j;
	}
	return table;
}
vector<int> KMP(string mainStr, string subStr)
{
	vector<int> ans;
	vector<int> table = getTable(subStr);
	int mainLen = mainStr.length(), subLen = subStr.length(), j = 0;

	for (int i = 0; i < mainLen; i++)
	{
		while (j && mainStr[i] != subStr[j])
			j = table[j - 1];
		if (mainStr[i] == subStr[j])
		{
			if (j == subLen - 1)
			{
				ans.push_back(i - subLen + 1);
				j = table[j];
			}
			else
				j++;
		}
	}
	return ans;
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	string mainStr, subStr;
	vector<int> ans;

	getline(cin, mainStr);
	getline(cin, subStr);

	ans = KMP(mainStr, subStr);

	int size = ans.size();
	cout << size << '\n';
	for (int i = 0; i < size; i++)
		cout << ans[i] + 1 << '\n';
}