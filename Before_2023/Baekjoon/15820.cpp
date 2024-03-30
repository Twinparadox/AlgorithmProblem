#include <iostream>
using namespace std;
int main(void)
{
	int s1, s2, sys, user;
	bool ac = true, ww = false;
	cin >> s1 >> s2;
	for (int i = 0; i < s1; i++)
	{
		cin >> sys >> user;
		if (sys != user)
			ac = false;
	}
	for (int i = 0; i < s2; i++)
	{
		cin >> sys >> user;
		if (sys != user)
			ww = true;
	}
	if (!ac)
		cout << "Wrong Answer";
	else if (ac && !ww)
		cout << "Accepted";
	else if (ac && ww)
		cout << "Why Wrong!!!";
}
