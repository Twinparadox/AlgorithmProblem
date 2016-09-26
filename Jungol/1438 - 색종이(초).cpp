#include <iostream>
using namespace std;
int arr[100][100];
void draw(int y, int x)
{
	int i, j;
	for (i = y; i < y + 10; i++)
		for (j = x; j < x + 10; j++)
			arr[i][j]++;
}
int main(void)
{
	int n;
	int location[100][2];
	int i , j;
	int site=0;
	cin >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j < 2; j++)
			cin >> location[i][j];
	for (i = 0; i < n; i++)
		draw(location[i][0], location[i][1]);

	for (i = 0; i < 100; i++)
		for (j = 0; j < 100; j++)
			if (arr[i][j] > 0)
				site++;
	cout << site;
}