#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int t, len, st, size;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string arr;
		getline(cin, arr);
		st = 0, size = arr.size();
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == ' ')
			{
				for (int j = i - 1; j >= st; j--)
					cout << arr[j];
				cout<<" ";
				st = i + 1;
			}
		}
		for (int i = size - 1; i >= st; i--)
			cout << arr[i];
		cout << "\n";
	}
}
