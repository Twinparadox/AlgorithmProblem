#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	double n, h, w, cross, height, width;
	cin >> n >> h >> w;
	cross = sqrt(h*h + w*w);
	height = (h * n / cross);
	width = (w * n / cross);
	cout << (int)height << " " << (int)width;
}
