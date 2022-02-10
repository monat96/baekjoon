#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int moving[101];
bool visited[101];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n + m; i++)
    {
        int start, end;
        cin >> start >> end;
        moving[start] = end;
    }
    
    queue<pair<int, int>> que;
    que.push({1, 0});
    visited[1] = true;

    while (!que.empty())
    {
        pair<int, int> curr = que.front();
        que.pop();

        int loc = curr.first;
        int cnt = curr.second;
        if (loc == 100)
        {
            cout << cnt;
            break;
        }

        for (int dist = 1; dist <= 6; dist++)
        {
            int nloc = loc + dist;

            if (nloc > 100 || visited[nloc])
                continue;
            if (moving[nloc] != 0)
                nloc = moving[nloc];
            que.push({nloc, cnt + 1});
            visited[nloc] = true;
        }
    }

    return 0;
}