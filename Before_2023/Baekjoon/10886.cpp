#include <iostream>
using namespace std;
int main(void)
{
	int n, ag = 0, disag = 0, tmp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp)
			ag++;
		else
			disag++;
	}
	if (ag > disag)
		cout << "Junhee is cute!";
	else
		cout << "Junhee is not cute!";
}
