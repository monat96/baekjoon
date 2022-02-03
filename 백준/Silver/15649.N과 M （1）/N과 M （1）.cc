#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int picked[10];
int isPick[10];

void func(int range, int toPick, int pick)
{
    if(toPick == pick)
    {
        for(int i = 0; i < toPick; i++)
            cout << picked[i] << ' ';
        cout << '\n';
        return ;
    }
    for(int next = 1; next <= range; next++)
    {
        if(isPick[next]) continue;
        picked[pick] = next;
        isPick[next] = true;
        func(range, toPick, pick + 1);
        isPick[next] = false;
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    func(n, m, 0);

    return 0;
}