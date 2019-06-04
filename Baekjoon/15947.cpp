#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string pattern[14] = {
		"baby","sukhwan","tururu","turu",
		"very","cute","tururu","turu",
		"in","bed","tururu","turu",
		"baby","sukhwan"
	};
	int N, idx, size = 14, cnt = 0;
	int pat1[3] = { 2,6,10 }, pat2[3] = { 3,7,11 };
	cin >> N;
	idx = (N - 1) % size;
	cnt = (N - 1) / size;

	int check = 0;
	for (int i = 0; i < 3; i++)
		if (pat1[i] == idx)
			check = 1;
	for (int i = 0; i < 3; i++)
		if (pat2[i] == idx)
			check = 2;

	if (check)
	{
		string result = "tu";
		if (check == 1)
		{
			if (cnt >= 3)
				result = result + "+ru*" + to_string((cnt + 2));
			else
				for (int i = 0; i < cnt + 2; i++)
					result += "ru";
		}
		else
		{
			if (cnt >= 4)
				result = result + "+ru*" + to_string((cnt + 1));
			else
				for (int i = 0; i < cnt + 1; i++)
					result += "ru";
		}
		cout << result;
	}
	else
	{
		cout << pattern[idx];
	}
}