#include <bits/stdc++.h>
using namespace std;

#define MAX 100005

int dp[MAX];
int n;
pair<int, int> period[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> period[i].first;
        cin >> period[i].second;
    }

    return 0;
}