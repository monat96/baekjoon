#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define SIZE 5

const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};

string board[5];
bool mask[25];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ans = 0;

    for(int i = 0; i < 5; i++)
        cin >> board[i];

    fill(mask + 7, mask + 25, true);
    do
    {   
        queue<pair<int, int>> que;
        bool visited[SIZE][SIZE] = {};
        bool is7[SIZE][SIZE] = {};
        int dasom = 0, cnt = 0;
        for(int i = 0; i < SIZE*SIZE; i++)
            if(!mask[i]) {
                int y = i / SIZE, x = i % SIZE;
                is7[y][x] = true;
                if(que.empty()) {
                    que.push({y, x});
                    visited[y][x] = true;
                }
            }   
        while(!que.empty()) {
            int y, x;
            tie(y, x) = que.front();
            que.pop();
            cnt++;
            dasom += board[y][x] == 'S';
            for(int dir = 0; dir < 4; dir++) {
                int ay = y + dy[dir];
                int ax = x + dx[dir];

                if(ay < 0 || ax < 0 || ay >= SIZE || ax >= SIZE || visited[ay][ax] || !is7[ay][ax]) continue;
                que.push({ay, ax});
                visited[ay][ax] = true;
                
            }
        }
        ans += (cnt >= 7 && dasom >= 4);
    } while (next_permutation(mask, mask + 25));
    
    cout << ans;
    return 0;
}
