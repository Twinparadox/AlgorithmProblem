#include <iostream>
using namespace std;
int main(void)
{
	long long n;
	int arr[8] = { 0,1,0,1,1,1,1,0 };
	cin >> n;
	if (arr[n % 7])
		cout << "SK";
	else
		cout << "CY";
}
