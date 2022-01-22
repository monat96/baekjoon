#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

#define WALL '#'
#define FIRE '*'
#define PERSON '@'

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

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
            int ny = curr.first + dy[dir];
            int nx = curr.second + dx[dir];

            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(fire[ny][nx] >= 0 || board[ny][nx] == WALL) continue;

            fire[ny][nx] = fire[curr.first][curr.second] + 1;
            fireQue.push({ny, nx});
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
            int ny = curr.first + dy[dir];
            int nx = curr.second + dx[dir];

            if(ny < 0 || nx < 0 || ny >= n || nx >= m) {
                cout << person[curr.first][curr.second] + 1 << '\n';
                personQue = queue<pair<int, int>>();
                return;
            }

            if(person[ny][nx] >= 0 || board[ny][nx] == WALL) continue;
            if(fire[ny][nx] != -1 && person[curr.first][curr.second] + 1 >= fire[ny][nx]) continue;

            person[ny][nx] = person[curr.first][curr.second] + 1;
            personQue.push({ny, nx});
        }
    }
    cout << "IMPOSSIBLE\n";
    return;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        for (int i = 0; i < n; i++)
            cin >> board[i];
        for (int i = 0; i < n; i++)
        {
            fill(person[i], person[i] + m, -1);
            fill(fire[i], fire[i] + m, -1);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == FIRE)
                {
                    fireQue.push({i, j});
                    fire[i][j] = 0;
                }
                if (board[i][j] == PERSON)
                {
                    personQue.push({i, j});
                    person[i][j] = 0;
                }
            }
        }
        fire_bfs();
        person_bfs();
    }
    return 0;
}
