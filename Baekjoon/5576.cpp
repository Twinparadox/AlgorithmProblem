#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[20];
    for (int i = 0; i < 20; i++)
        cin>>a[i];
    sort(a, a + 10);
    sort(a + 10, a + 20);
    cout<<a[7] + a[8] + a[9]<<" "<<a[17] + a[18] + a[19];
    return 0;
}
