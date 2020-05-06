#include <iostream>
#include <vector>
using namespace std;
int N, cnt;
vector<int> arr;
vector<bool> visit, check;
void dfs(int idx)
{
    visit[idx] = true;
    int want = arr[idx];

    if (!visit[want])
        dfs(want);

    else if (!check[want])
    {
        for (int i = want; i != idx; i = arr[i])
            cnt++;
        cnt++;
    }
    check[idx] = true;
}
int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> N;

        visit = vector<bool>(N + 1, false);
        check = vector<bool>(N + 1, false);
        arr = vector<int>(N + 1);
        for (int j = 1; j <= N; j++)
            cin >> arr[j];

        cnt = 0;
        for (int j = 1; j <= N; j++)
            if (!visit[j])
                dfs(j);

        cout << N - cnt << '\n';
    }
}