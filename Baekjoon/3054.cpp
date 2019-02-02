#include <iostream>
#include <string>
#include <vector> 
using namespace std;
int main(void)
{
	string str;
	int len;
	cin >> str;
	len = str.length();
	vector<string> arr(5);

	arr[0] = "..#..";
	for (int i = 1; i < str.length(); i++)
	{
		if (i % 3 == 2)
			arr[0] += ".*..";
		else
			arr[0] += ".#..";
	}
	arr[4] = arr[0];

	arr[1] = ".#.#.";
	for (int i = 1; i < str.length(); i++)
	{
		if (i % 3 == 2)
			arr[1] += "*.*.";
		else
			arr[1] += "#.#.";
	}
	arr[3] = arr[1];

	arr[2] = "#.";
	arr[2] += str[0];
	arr[2] += ".#";
	for (int i = 1; i < str.length(); i++)
	{
		if (i % 3 == 1)
		{
			arr[2] += ".";
			arr[2] += str[i];
			if (i == str.length() - 1)
				arr[2] += ".#";
			else
				arr[2] += ".*";
		}
		else if (i % 3 == 2)
		{
			arr[2] += ".";
			arr[2] += str[i];
			arr[2] += ".*";
		}
		else
		{
			arr[2] += ".";
			arr[2] += str[i];
			arr[2] += ".#";
		}
	}

	for (int i = 0; i < 5; i++)
		cout << arr[i] << '\n';
}