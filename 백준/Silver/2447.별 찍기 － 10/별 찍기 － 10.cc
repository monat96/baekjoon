#include <iostream>
#include <vector>

using namespace std;

char star[2'200][2'200];

void func(int y, int x, int n)
{
    if(n == 1) {
        star[y][x] = '*';
        return ;
    }

    int div = n / 3;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) 
                continue;
            func(y + div * i, x + div * j, div);
        }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++)
        fill(star[i], star[i] + n, ' ');
    
    func(0, 0, n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << star[i][j];
        cout << '\n';
    }
    return 0;
}
