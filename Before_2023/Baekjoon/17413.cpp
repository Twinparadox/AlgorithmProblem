/*
[S3] 17413 - 단어 뒤집기 2
문자열 구현 문제
띄어쓰기 처리 등을 고려해야 함
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	string str;
	string sub1 = "", sub2 = "";
	vector<string> arr;
	int len = 0;
	bool flag = false;

	getline(cin, str);

	len = str.length();
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '<')
		{
			if (sub2 != "")
			{
				arr.push_back(sub2);
				sub2 = "";
			}
			flag = true;
			sub1 = "<";
		}
		else if (str[i] == '>')
		{
			sub1 += ">";
			arr.push_back(sub1);
			flag = false;
			sub1 = "";
		}
		else if (str[i] == ' ' && !flag)
		{
			sub2 = ' ' + sub2;
			arr.push_back(sub2);
			sub2 = "";
		}
		else
		{
			if (flag)
				sub1 += str[i];
			else
				sub2 += str[i];
		}
	}
	if (flag)
		arr.push_back(sub1);
	else if (sub2 != "")
		arr.push_back(sub2);

	int size = arr.size();
	for (int i = 0; i < size; i++)
	{
		if (arr[i][0] == '<')
		{
			int len = arr[i].length();
			for (int j = 0; j < len; j++)
				cout << arr[i][j];
		}
		else
		{
			int len = arr[i].length();
			for (int j = len - 1; j >= 0; j--)
				cout << arr[i][j];
		}
	}
}