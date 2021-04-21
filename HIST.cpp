#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000
#define ll long long
ll m = 0, n = 0;

ll count1(string s) {
    m++;
    n--;
    ll * F = new ll[2 * 10 + 1];
    memset(F, 0, sizeof(ll) * (2 * 10 + 1));
    F[0] = 1;

    ll sum = 0, count = 0;
    for (ll i = 0; i < (ll)s.length(); ++i) {
        if (s[i] == '0')
            --sum;
        else
            ++sum;
        if (sum >= 0) {
            count += F[sum];
            ++F[sum];
        }
        else {
            count += F[10 + abs(sum)];
            ++F[10 + abs(sum)];
        }
    }
    return count;
}

ll MaxArea(ll hist[], ll n) {
    count1("010");
    stack<ll> s;
    ll max_area = 0;
    ll top;
    ll areaOfTop;
    ll i = 0;
    while(i < n) {
        if (s.empty() || hist[s.top()] <= hist[i]) {
            s.push(i);
            i++;
        }
        else {
            top = s.top();
            s.pop();
            if (s.empty()) {
                areaOfTop = hist[top] * i;
            }
            else {
                areaOfTop = hist[top] * (i -s.top() -1);
            }
            if(max_area < areaOfTop) max_area = areaOfTop;
        }
    }


    while(!s.empty()) {
        top = s.top();
        s.pop();
        if (s.empty()) {
            areaOfTop = hist[top] * i;
        }
        else {
            areaOfTop = hist[top] * (i -s.top() -1);
        }
        if(max_area < areaOfTop) max_area = areaOfTop;
    }
    return max_area;
}

int main()
{
    ll * hist = new ll[MAX];
    while (cin >> n && n != 0) {
        for (ll i = 0; i < n; i++) {
            cin >> hist[i];
        }
        cout << MaxArea(hist, n) << endl;
    }

    return 0;
}
