#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	string str;
	vector<char> ans;
	stack<char> stChar;
	int len;

	cin >> str;
	len = str.length();
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '(')
			stChar.push('(');
		else if (str[i] == ')')
		{
			while (!stChar.empty() && stChar.top() != '(')
			{
				ans.push_back(stChar.top());
				stChar.pop();
			}
			stChar.pop();
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
			ans.push_back(str[i]);
		else if (str[i] == '*' || str[i] == '/')
		{
			while (!stChar.empty() && (stChar.top() == '*' || stChar.top() == '/'))
			{
				ans.push_back(stChar.top());
				stChar.pop();
			}
			stChar.push(str[i]);
		}
		else
		{
			while (!stChar.empty() && stChar.top() != '(')
			{
				ans.push_back(stChar.top());
				stChar.pop();
			}
			stChar.push(str[i]);
		}
	}
	while (!stChar.empty())
	{
		ans.push_back(stChar.top());
		stChar.pop();
	}
	len = ans.size();
	for (int i = 0; i < len; i++)
		cout << ans[i];
}