#include <iostream>
#include <string.h>
using namespace std;
int main(void)
{
	int t, len;
	cin >> t;
	while (t--)
	{
		char arr[61];
		cin >> arr;
		len = strlen(arr);
		if ((arr[len - 1] - 48) % 2 == 0)
			cout << "even\n";
		else
			cout << "odd\n";
	}
}
