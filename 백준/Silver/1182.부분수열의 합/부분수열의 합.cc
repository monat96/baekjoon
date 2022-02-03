#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int arr[21];
int target;
int cnt = 0;

void func(int size, int pick, int calc)
{
    if(size == pick)
    {
        if(target == calc)
            cnt++;
        return ;
    }
    func(size, pick+1, calc);
    func(size, pick+1, calc + arr[pick]);
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n >> target;

    for(int i = 0; i < n; i++) cin >> arr[i];
    func(n, 0, 0);
    if(target==0) cnt--;
    cout << cnt;
    return 0;
}