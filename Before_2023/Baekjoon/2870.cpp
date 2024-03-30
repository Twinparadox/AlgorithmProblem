#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct su
{
	string str;
	unsigned int len;
};
bool compareLength(const struct su a, const struct su b)
{
	if (a.len < b.len)
		return true;
	else if (a.len == b.len)
	{
		bool isAsmaller = false;

		for (int i = 0; i < a.len; i++)
		{
			if (a.str[i] > b.str[i])
			{
				isAsmaller = false;
				break;
			}
			else if (a.str[i] < b.str[i])
			{
				isAsmaller = true;
				break;
			}
			else
				isAsmaller = false;
		}
		return isAsmaller;
	}
	else
		return false;
}
void eraseZero(string& str, int length)
{
	int idx = 0;
	for (idx = 0; idx < length - 1; idx++)
		if (str[idx] != '0')
			break;
	str.erase(0, idx);
}
int main(void)
{
	int N;
	vector<struct su> num;
	cin >> N;

	vector<string> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++)
	{
		int len = arr[i].length();
		string tmp = "";
		for (int j = 0; j < len; j++)
		{
			if (!(arr[i][j] >= '0' && arr[i][j] <= '9'))
			{
				if (tmp == "")
					continue;
				else
				{
					if (tmp[0] == '0' && tmp.length() > 1)
						eraseZero(tmp, tmp.length());
					num.push_back({ tmp, tmp.length() }), tmp = "";
				}
			}
			else
			{
				tmp += arr[i][j];
			}
		}
		if (tmp != "")
		{
			if (tmp[0] == '0' && tmp.length() > 1)
				eraseZero(tmp, tmp.length());
			num.push_back({ tmp,tmp.length() });
		}
	}

	sort(num.begin(), num.end(), compareLength);
	int size = num.size();
	for (int i = 0; i < size; i++)
		cout << num[i].str << '\n';
}