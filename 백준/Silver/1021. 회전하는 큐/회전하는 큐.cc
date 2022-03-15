#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <cmath>
#include <queue>
#include <list>
#include <stack>
#include <stdio.h>
#include <set>
#include <functional>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    int ans = 0;
    cin >> n >> m;
    deque<int> dq;
    for(int i = 1; i <= n; i++) dq.push_back(i);
    while(m--) {
        int t;
        cin >> t;
        int idx = find(dq.begin(), dq.end(), t) - dq.begin();
        while(dq.front() != t) {
            if(idx > int(dq.size()) - idx) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            else {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            ans++;
        }
        dq.pop_front();
    }
    cout << ans;
    return 0;
}
