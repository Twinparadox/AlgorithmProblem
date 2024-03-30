#include <iostream>
using namespace std;
int main(void)
{
	bool order = true;
	int n, prev = -1000001;
	while (cin >> n)
	{
		if (order && prev <= n)
			prev = n;
		else
			order = false;
	}
	
	if (order)
		cout << "Good";
	else
		cout << "Bad";
}
