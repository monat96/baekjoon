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

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<int, vector<int>, greater<int>> que;
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        que.push(x);
    }
    int cnt = 0;
    while(que.size() > 1) {
        int first = que.top();
        que.pop();
        int second = que.top();
        que.pop();
        cnt += (first + second);
        que.push(first + second);
    }
    cout << cnt;
    return 0;
}
