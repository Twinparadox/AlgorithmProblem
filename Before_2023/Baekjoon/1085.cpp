#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int arr[4] = { w - x,x,h - y,y };
	sort(arr, arr + 4);
	cout << arr[0];
}
