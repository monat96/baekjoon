#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 100'001

bool visited[MAX];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int start, dest;
    int ans_cnt = 0;
    int ans_time = 0;

    cin >> start >> dest;
        
    queue<pair<int, int>> que;
    que.push({start, 0});

    while(!que.empty())
    {
        pair<int, int> curr = que.front();
        int curr_pos = curr.first;
        int curr_time = curr.second;
        que.pop();

        visited[curr_pos]=true;

        if(ans_cnt > 0 && curr_pos == dest && curr_time == ans_time)
        {
            ans_cnt += 1;
        }
        if(ans_cnt == 0 && curr_pos == dest)
        {
            ans_time = curr_time;
            ans_cnt+=1;
        }

        for(auto val : {curr_pos-1, curr_pos+1, curr_pos*2}) {
            if(val < 0 || val > MAX || visited[val]) continue;
            que.push({val, curr_time + 1});
        }
    }
    cout << ans_time << '\n' << ans_cnt << '\n';
    return 0;
}