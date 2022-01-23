#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

#define WALL '#'

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
string board[1002];
int fire[1002][1002];
int person[1002][1002];

int n, m;
queue<pair<int, int>> fireQue;
queue<pair<int, int>> personQue;

void fire_bfs()
{
    while(!fireQue.empty())
    {
        pair<int, int> curr = fireQue.front(); fireQue.pop();

        for(int dir = 0; dir < 4; dir++)
        {
            int ay = curr.first + dy[dir];
            int ax = curr.second + dx[dir];

            if(ay < 0 || ax < 0 || ay >= n || ax >= m) continue;
            if(fire[ay][ax] >= 0 || board[ay][ax] == WALL) continue;
            fire[ay][ax] = fire[curr.first][curr.second] + 1;
            fireQue.push({ay, ax});
        }
    }
}

void person_bfs()
{
    while(!personQue.empty())
    {
        pair<int, int> curr = personQue.front(); personQue.pop();

        for(int dir = 0; dir < 4; dir++)
        {
            int ay = curr.first + dy[dir];
            int ax = curr.second + dx[dir];

            if(ay < 0 || ax < 0 || ay >= n || ax >= m) {
                cout << person[curr.first][curr.second] + 1 << '\n';
                return ;
            } 
            
            if(person[ay][ax] >= 0 || board[ay][ax] == WALL) continue;
            if(fire[ay][ax] != -1 && person[curr.first][curr.second] + 1 >= fire[ay][ax]) continue;

            person[ay][ax] = person[curr.first][curr.second] + 1;
            personQue.push({ay, ax});
        }
    }
    cout << "IMPOSSIBLE";
    return ;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    

    for(int i = 0; i < n; i++)
    {
        fill(person[i], person[i] + m, -1);
        fill(fire[i], fire[i] + m, -1);
    }

    for(int i = 0; i < n; i++) cin >> board[i];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'F') {
                fireQue.push({i, j});
                fire[i][j] = 0;
            }
            if(board[i][j] == 'J') {
                personQue.push({i, j});
                person[i][j] = 0;
            }
        }
    }
    fire_bfs();
    person_bfs();
    return 0;
}
