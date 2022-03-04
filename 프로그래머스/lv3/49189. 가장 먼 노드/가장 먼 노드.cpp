#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int MAX = 0;

vector<int> dist(20'001, -1);

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    map<int, vector<int>> graph;
    for(auto e : edge) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    queue<int> que;
    que.push(1);
    dist[1] = 0;
    
    while(!que.empty()) {
        int curr = que.front();
        que.pop();
        
        for(auto e : graph[curr]) {
            if(dist[e] != -1) continue;
            
            que.push(e);
            dist[e] = dist[curr] + 1;
            MAX = max(MAX, dist[e]);
        }
    }
    for(int i = 1; i <= n; i++) answer += dist[i] == MAX;
    return answer;
}