#include <iostream>
using namespace std;
int main(void)
{
	int n, w, h, tmp;
	cin >> n >> w >> h;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp > w && tmp > h && tmp*tmp > (w*w + h*h))
			cout << "NE\n";
		else
			cout << "DA\n";
	}
}
