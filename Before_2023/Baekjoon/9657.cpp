#include <iostream>
using namespace std;
int main(void)
{
	bool arr[1001] = { false,true,false,true,true, };
	int n;
	cin >> n;
	for (int i = 5; i <= n; i++)
		arr[i] = !arr[i - 1] | !arr[i - 3] | !arr[i - 4];
	if (arr[n])
		cout << "SK";
	else
		cout << "CY";
}
