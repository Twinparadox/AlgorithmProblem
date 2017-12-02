#include <iostream>
using namespace std;
int main(void)
{
	int n, a = 0;
	char arr[16];
	cin >> n;
	cin >> arr;
	for (int i = 0; i < n; i++)
		if (arr[i] == 'A')
			a++;
	if (a > n - a)
		cout << "A";
	else if (a == n - a)
		cout << "Tie";
	else
		cout << "B";
}
