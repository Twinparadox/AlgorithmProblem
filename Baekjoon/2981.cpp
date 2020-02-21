#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> arr, ans;
int gcd(int a, int b)
{
    return a % b ? gcd(b, a % b) : b;
}
int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, x, i, cnt = 0;
    cin >> n;

    arr = vector<int>(n);

    for (i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    x = arr[1] - arr[0];
    for (i = 2; i < n; i++)
        x = gcd(x, arr[i] - arr[i - 1]);

    for (i = 1; i * i <= x; i++)
        if (x % i == 0)
        {
            ans.push_back(i);
            if (i != x / i)
                ans.push_back(x / i);
        }

    sort(ans.begin(), ans.end());
    int size = ans.size();
    for (int i = 0; i < size; i++)
        if (ans[i] != 1)
            cout << ans[i] << ' ';
}