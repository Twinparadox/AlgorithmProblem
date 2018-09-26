#include <iostream>
using namespace std;
int main(void)
{
	int n, arr[100];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < arr[i]; j++)
			cout << "=";
		cout << '\n';
	}
}
