#include <iostream>
using namespace std;
int main(void)
{
	int n, row, col;
	cin >> n;
	row = n / 2;
	col = n - row;
	cout << (row + 1)*(col + 1);
}