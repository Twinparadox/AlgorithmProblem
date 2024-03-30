#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	int n, idx1 = 0, idx2 = 0;
	cin >> n;
	vector<string> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] == "KBS1")
			idx1 = i;
		else if (arr[i] == "KBS2")
			idx2 = i;
	}

	for (int i = 0; i < idx1; i++)
		cout << 1;
	for (int i = 0; i < idx1; i++)
		cout << 4;
	if (idx1 > idx2)
		idx2++;
	for (int i = 0; i < idx2; i++)
		cout << 1;
	for (int i = 0; i < idx2 - 1; i++)
		cout << 4;
}