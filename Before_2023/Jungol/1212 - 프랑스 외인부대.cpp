#include <iostream>
using namespace std;
typedef struct
{
	int gender;
	int age;
	int app;
} Status;
int main(void)
{
	Status st;
	int n, cnt = 0, list[100];
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> st.gender >> st.age >> st.app;
		if (!(st.gender == 1 && ((st.age > 18 && st.age <= 40) || (st.age >= 17 && st.age <= 18 && st.app == 1))))
			list[cnt++] = i;
	}
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++)
		cout << list[i] << " ";
	return 0;
}