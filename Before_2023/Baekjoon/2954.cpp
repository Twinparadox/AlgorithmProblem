#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string arr;
	int len;
	getline(cin, arr);
	len = arr.size();
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
			cout << arr[i], i += 2;
		else
			cout << arr[i];
	}
}
