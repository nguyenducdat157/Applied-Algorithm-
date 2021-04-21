#include <bits/stdc++.h>

using namespace std;
const int N = 15;

int n; // num of passengers
int cost[N][N]; // matrix of distance between 2 point
int temp[N]; // current path
int tempCost = 0;
int record = INT_MAX;
bool visited[N] = {false};
int c_min = INT_MAX;

void input();
void Try(int k);

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/Training3/0.INP", "r", stdin);

    input();
    Try(1);
    cout << record;
    return 0;
}

void input() {
    cin >> n;
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            cin >> cost[i][j];
            if (cost[i][j] == 0) {
                cost[i][j] = INT_MAX;
                continue;
            }
            c_min = min (cost[i][j], c_min);
        }
    }
}

bool check(int i) {
    if (visited[i]) return false;
    if (i > n) return visited[i-n];
    return true;
}

void Try(int k) {
    for (int i = 1; i <= 2 * n; i++) {
        if(check(i)) {
            temp[k] = i;
            visited[i] = true;
            tempCost += cost[temp[k-1]][i];
            if (k == 2 * n) {
                record = min(record, tempCost + cost[temp[2*n]][0]);
            } else {
                if (tempCost + c_min*(2*n + 1 - k) < record) Try(k + 1);
            }
            visited[i] = false;
            tempCost -= cost[temp[k-1]][i];

        }
    }
}
