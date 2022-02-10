#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    queue<pair<int, int>> que;
    que.push({n, 0});

    while(true)
    {
        pair<int, int> curr = que.front();
        que.pop();

        int val = curr.first;
        int cnt = curr.second;

        if(val == 1) {cout << cnt; break;}    
        
        if(val % 3 == 0) que.push({val/3, cnt+1});
        if(val % 2 == 0) que.push({val/2, cnt+1});
        que.push({val-1, cnt+1});
    }
    return 0;
}