#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int N, cnt = 0, isu = 666;
	string devil = "666";
	cin >> N;

	while (cnt < N)
	{
		string su = to_string(isu);
		if (su.find(devil) != string::npos)
		{
			cnt++;
			if (cnt == N)
				cout << su;
		}
		isu++;
	}
}