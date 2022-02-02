#include <iostream>
#include <vector>

using namespace std;

#define MAX (1 << 7)

int paper[MAX][MAX];
int cnt[2];

bool check(int y, int x, int div)
{
    for(int i = y; i < y + div; i++)
        for(int j = x; j < x + div; j++)
            if(paper[i][j] != paper[y][x])
                return false;
    return true;
}
void func(int y, int x, int n)
{
    if(check(y, x, n)) {
        cnt[paper[y][x]] += 1;
        return ;
    }
    int div = n / 2;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            func(y + div * i, x + div * j, div);
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> paper[i][j];

    func(0, 0, n);
    for(auto ret : cnt) cout << ret << '\n';
 
    return 0;
}
