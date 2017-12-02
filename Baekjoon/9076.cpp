#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
	int t, arr[5];
	cin >> t;
	while (t--)
	{
		for (int i = 0; i < 5; i++)
			cin >> arr[i];
		sort(arr, arr + 5);
		if ((arr[3] - arr[1]) >= 4)
			cout << "KIN\n";
		else
			cout << arr[1] + arr[2] + arr[3] << '\n';
	}
}
