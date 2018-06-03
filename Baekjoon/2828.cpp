#include <iostream>
using namespace std;
int main(void)
{
	int n, m, j, apple, mov = 0, start, end;
	cin >> n >> m >> j;
	start = 1, end = m;
	for (int i = 0; i < j; i++)
	{
		cin >> apple;
		if (start <= apple && end >= apple)
			continue;
		if (start > apple)
		{
			mov += start - apple;
			end -= start - apple;
			start = apple;
		}
		else
		{
			mov += apple - end;
			start += apple - end;
			end = apple;
		}
	}
	cout << mov;
}
