#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    int cnt = 0, num = 666;
    cin >> n;
    while(cnt < n)
    {
        string stringNum = to_string(num);
        if(stringNum.find("666") != string::npos)
            cnt +=1;
        num += 1;
    }
    cout << num-1;
    return 0;
}