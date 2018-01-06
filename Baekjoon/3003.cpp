#include <iostream>
using namespace std;
int main(void)
{
	int arr[6] = { 1,1,2,2,2,8 }, input[6];
	for (int i = 0; i < 6; i++)
		cin >> input[i];
	for (int i = 0; i < 6; i++)
		cout << arr[i] - input[i] << ' ';
}
