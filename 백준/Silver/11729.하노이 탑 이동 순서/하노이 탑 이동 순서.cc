#include <iostream>
#include <vector>

using namespace std;

void func(int start, int end, int n)
{
    if(n == 1)
    {
        cout << start << ' ' << end << '\n';
        return ;
    }
    func(start, 6-start-end, n-1);
    cout << start << ' ' << end << '\n';
    func(6-start-end, end, n-1);
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    cout << (1 << k) - 1 <<'\n';
    func(1, 3, k);
    return 0;
}
