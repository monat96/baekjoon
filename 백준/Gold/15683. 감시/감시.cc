#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 8

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

int pos[MAX][MAX];
int pos_tmp[MAX][MAX];
int n, m;
vector<pair<int, int>> cctv;

bool outOfBound(int y, int x)
{
    return (y < 0 || x < 0 || y >= n || x >= m);
}
void upd(int y, int x, int dir)
{
    dir %= 4;
    while(true)
    {
        y += dy[dir];
        x += dx[dir];
        if(outOfBound(y, x) || pos_tmp[y][x] == 6) return ;
        if(pos_tmp[y][x] != 0) continue;
        pos_tmp[y][x] = 7;
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    int mn = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> pos[i][j];
            if(pos[i][j] != 0 && pos[i][j] != 6)
                cctv.push_back({i, j});
            if(pos[i][j] == 0)
                mn += 1;
        }
    

    for(int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++)
    {
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) pos_tmp[i][j] = pos[i][j];

        int brute = tmp;
        for(int i = 0; i < cctv.size(); i++)
        {
            int dir = brute % 4;
            brute /= 4;
            int y, x;
            tie(y, x) = cctv[i];

            if(pos[y][x] == 1) {
                upd(y, x, dir);
            }
            else if(pos[y][x] == 2) {
                upd(y, x, dir);
                upd(y, x, dir + 2);
            }
            else if(pos[y][x] == 3) {
                upd(y, x, dir);
                upd(y, x, dir + 1);
            }
            else if(pos[y][x] == 4) {
                upd(y, x, dir);
                upd(y, x, dir + 1);
                upd(y, x, dir + 2);
            }
            else {
                upd(y, x, dir);
                upd(y, x, dir + 1);
                upd(y, x, dir + 2);
                upd(y, x, dir + 3);
            }
        }
        int val = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                val += (pos_tmp[i][j] == 0);
        mn = min(mn, val);
    }
    cout << mn;
    return 0;
}