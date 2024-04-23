#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct compare
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.second > b.second;
	}
};

// idx v, pair<w, c>
vector<vector<pair<int, int>>> graph(10001);
bool visited[10001] = {false};

priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int v, w, c;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> v >> w >> c;
		graph[v].push_back(make_pair(w, c));
		graph[w].push_back(make_pair(v, c));
	}

	// start 1
	while (!graph[1].empty())
	{
		pq.push(graph[1].back());
		graph[1].pop_back();
	}

	visited[1] = true;
	long long ans = 0;

	while (!pq.empty())
	{
		pair<int, int> cur = pq.top();
		pq.pop();

		if (visited[cur.first])
		{
			continue;
		}

		visited[cur.first] = true;
		ans += cur.second;

		for (int i = 0; i < graph[cur.first].size(); i++)
		{
			if (!visited[graph[cur.first][i].first])
			{
				pq.push(graph[cur.first][i]);
			}
		}
	}
	cout << ans << '\n';
}
