#include<iostream>
#include<stack>
#include<vector>
using namespace std;

long long getArea(int n)
{   int tmp;
    vector<int> hist;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        hist.push_back(tmp);
    }
    hist.push_back(0); // sentinel to ensure all indexes get popped off the stack
    stack<int> S;
    long long maxArea = 0;
    for (int i = 0; i < hist.size(); i++) {
        while (!S.empty() && hist[S.top()] >= hist[i]) {
            long long height = hist[S.top()];
            S.pop();
            int left = S.empty() ? 0 : S.top() + 1, right = i - 1;
            maxArea = max(maxArea, (right - left + 1) * height);
        }
        S.push(i);
    }
    return maxArea;
}
int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        else cout << getArea(n) << endl;
    }
    return 0;
}