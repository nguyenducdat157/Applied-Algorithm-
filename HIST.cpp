#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000

long long MaxArea(int n) {
    int temp;
    vector<int> hist;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        hist.push_back(temp);
    }
    hist.push_back(0);
    stack<int> st;
    long long maxArea = 0;
    for (int i = 0; i < hist.size(); i++) {

    }
}

int main()
{
    auto * hist = new long long[MAX];
    int n;
    while (cin >> n) {
        if (n == 0) break;
        else cout << MaxArea(n) << endl;
    }

    return 0;
}
