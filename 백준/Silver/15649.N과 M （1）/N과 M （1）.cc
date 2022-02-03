#include <iostream>
#include <vector>

using namespace std;

bool isPick[10];

void backTracking(vector<int> &picked, int range, int toPick, int pick)
{
    if(toPick == pick)
    {
        for(auto ret : picked) cout << ret << ' ';
        cout << '\n';
        return ;
    }
    for(int next = 1; next <= range; next++)
    {
        if(isPick[next]) continue;
        picked.push_back(next);
        isPick[next] = true;
        backTracking(picked, range, toPick, pick + 1);
        picked.pop_back();
        isPick[next] = false;
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> picked;
    backTracking(picked, n, m, 0);

    return 0;
}