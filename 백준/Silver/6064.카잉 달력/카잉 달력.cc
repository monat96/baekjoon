#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    if(b > a) return gcd(b, a);
    if(a % b == 0) return b;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int func(int n, int m, int x, int y)
{
    if(x == n) x = 0;
    if(y == m) y = 0;
    
    int l = lcm(n, m);

    for(int i = x; i <= l; i += n) {
        if(i % n == x && i % m == y)
            return i;
    }
    return -1;
}


int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        cout << func(n, m ,x, y) << '\n';
    }
    

    return 0;
}