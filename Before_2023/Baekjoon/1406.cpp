#include <iostream>
#include <list>
#include <string>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	string str;
	int len, N;
	list<char> cList;

	cin >> str;
	cin >> N;

	len = str.length();
	cList.push_back('0');
	for (int i = 0; i < len; i++)
		cList.push_back(str[i]);

	list<char>::iterator iter = cList.end();
	iter--;
	list<char>::iterator lastNode = iter;
	iter++;
	while (N--)
	{
		char op;
		cin >> op;
		if (op == 'L' && iter != cList.begin())
			iter--;
		else if (op == 'D' && iter != cList.end())
			iter++;
		else if (op == 'B' && iter != cList.begin())
		{
			if (iter == cList.end())
			{
				cList.erase(lastNode);
				lastNode = --iter;
				iter++;
			}
			else
			{
				auto remove = --iter;
				iter++;
				cList.erase(remove);
			}
		}
		else if (op == 'P')
		{
			char c;
			cin >> c;
			if (iter == cList.begin())
				cList.insert(cList.begin(), c);
			else if (iter == cList.end())
			{
				cList.push_back(c);
				auto tmp = cList.end();
				lastNode = --tmp;
			}
			else
				cList.insert(iter, c);
		}
	}

	for (auto iter = cList.begin(); iter != cList.end(); iter++)
	{
		if (*iter == '0')
			continue;
		cout << *iter;
	}
}