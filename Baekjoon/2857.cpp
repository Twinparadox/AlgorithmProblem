#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string s[5];
	int arr[5], size = 0, len;
	for (int i = 0; i < 5; i++)
		cin >> s[i];
	for (int i = 0; i < 5; i++)
	{
		len = s[i].length();
		for (int j = 0; j < len - 2; j++)
			if (s[i][j] == 'F' && s[i][j + 1] == 'B' && s[i][j + 2] == 'I')
				arr[size] = i + 1, size++;
	}
	if (size == 0)
		cout << "HE GOT AWAY!";
	else
		for (int i = 0; i < size; i++)
			cout << arr[i] << ' ';
}
