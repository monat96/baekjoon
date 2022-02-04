#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 21;

int arr[MAX];
int answer = 0;
int target;

void func(int size, int idx, int sum)
{
    if(size == idx)
    {
        if(sum == target) answer++;
        return ;
    }
    func(size, idx + 1, sum);
    func(size, idx + 1, sum + arr[idx]);
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n >> target;

    for(int i = 0; i < n; i++) cin >> arr[i];

    func(n, 0, 0);
    if(target==0)answer--;
    cout << answer;
    return 0;
}
