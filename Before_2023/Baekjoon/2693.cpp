#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
	int t, arr[10];
	cin >> t;
	while (t)
	{
		for (int i = 0; i < 10; i++)
			cin >> arr[i];
		sort(arr, arr + 10);
		cout << arr[7] << "\n";
		t--;
	}
}
