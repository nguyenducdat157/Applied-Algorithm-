#include <bits/stdc++.h>

using namespace std;

int n;
int temp[25];

void Try(int k) {
    for (int i = 0; i <= 1; i++) {
        temp[k] = i;
        if (k == n) {
            for (int j = 1; j <= n; j++) {
                cout << temp[j];
            }
            cout << endl;
        } else Try(k + 1);
    }
}

int main() {
    freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);
    cin >> n;
    Try(1);

    return 0;
}