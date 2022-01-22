#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int board[303][303];
int melt[303][303];
bool visited[303][303];

void init_visited(int sizeY, int sizeX)
{
    for(int i = 0; i < sizeY; i++)
        fill(visited[i], visited[i] + sizeX, false);
}

void meltDown(int sizeY, int sizeX)
{
    for(int y = 0; y < sizeY; y++) {
        for(int x = 0; x < sizeX; x++) {
            if(board[y][x] == 0) continue;
            int cnt = 0;
            for(int dir = 0; dir < 4; dir++) {
                int ay = y + dy[dir];
                int ax = x + dx[dir];

                if(board[ay][ax] == 0) cnt++;
            }
            melt[y][x] = cnt;
        }
    }
    for(int i = 0; i < sizeY; i++) {
        for(int j = 0; j < sizeX; j++) {
            if(melt[i][j] == 0 || board[i][j] == 0) continue;
            board[i][j] = board[i][j] - melt[i][j] > 0 ? board[i][j] - melt[i][j] : 0;
        }
    }
}
void dfs(int y, int x, int sizeY, int sizeX)
{
    stack<pair<int, int>> stck;
    
    stck.push({y, x});
    visited[y][x] = true;

    while(!stck.empty())
    {
        pair<int, int> curr = stck.top(); stck.pop();
        
        for(int dir = 0; dir < 4; dir++)
        {
            int ay = curr.first + dy[dir];
            int ax = curr.second + dx[dir];

            if(ay < 0 || ax < 0 || ay >= sizeY || ax >= sizeX) continue;
            if(board[ay][ax] == 0 || visited[ay][ax]) continue;
            
            stck.push({ay, ax});
            visited[ay][ax] = true;
        }
    }
}
int getCnt(int sizeY, int sizeX)
{
    int cnt = 0;
    
    for(int i = 0; i < sizeY; i++) {
        for(int j = 0; j < sizeX; j++) {
            if(board[i][j] == 0 || visited[i][j]) continue;
            dfs(i, j, sizeY, sizeX);
            cnt++;
        }
    }
    init_visited(sizeY, sizeX);
    return cnt;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;    
    
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    int ans = 0;
    int cnt = 0;
    while(true)
    {
        cnt = getCnt(n, m);
        meltDown(n, m);
        if(cnt > 1 || cnt == 0) break;
        ans++;
    }
    if(cnt == 0) cout << 0;
    else cout << ans;
    return 0;
}
