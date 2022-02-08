#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int min = MAX;
        int sum = 0;
        for(int i = 0; i < 7; i++)
        {
            int x;
            cin >> x;
            if(x % 2 == 0)
            {
                sum += x;
                if(x < min) min = x;
            }
        }
        cout << sum << ' ' << min << '\n';
    }


    return 0;
}
