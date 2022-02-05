#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dura[10];
int weight[10];
int mx = 0;
int cnt = 0;

void func(int size, int pick)
{
    if(pick == size)
    {
        mx = max(cnt, mx);
        return ;
    }
    if(dura[pick] <= 0 || cnt == size-1)
    {
        return func(size, pick + 1);
    }
    for(int next = 0; next < size; next++)
    {
        if(next == pick || dura[next] <= 0) continue;
        dura[pick] -= weight[next];
        dura[next] -= weight[pick];
        if(dura[pick] <= 0) cnt++;
        if(dura[next] <= 0) cnt++;
        func(size, pick + 1);
        if(dura[pick] <= 0) cnt--;
        if(dura[next] <= 0) cnt--;
        dura[pick] += weight[next];
        dura[next] += weight[pick];
    }

}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) cin >> dura[i] >> weight[i];
    func(n, 0);
    cout << mx;
    return 0;
}
