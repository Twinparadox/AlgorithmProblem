#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string start, end;
	int s[3], e[3], ans[3];
	cin >> start;
	cin >> end;
	s[0] = stoi(start.substr(0, 2));
	s[1] = stoi(start.substr(3, 2));
	s[2] = stoi(start.substr(6, 2));
	e[0] = stoi(end.substr(0, 2));
	e[1] = stoi(end.substr(3, 2));
	e[2] = stoi(end.substr(6, 2));

	if (e[2] >= s[2])
		ans[2] = e[2] - s[2];
	else
		ans[2] = 60 + e[2] - s[2], e[1]--;
	if (e[1] >= s[1])
		ans[1] = e[1] - s[1];
	else
		ans[1] = 60 + e[1] - s[1], e[0]--;
	if (e[0] >= s[0])
		ans[0] = e[0] - s[0];
	else
		ans[0] = 24 + e[0] - s[0];

	if (ans[2] == 0 && ans[1] == 0 && ans[0] == 0)
		ans[0] = 24;

	for (int i = 0; i < 3; i++)
	{
		if (ans[i] < 10)
			cout << '0' << ans[i];
		else
			cout << ans[i];
		if (i != 2)
			cout << ':';
	}
}