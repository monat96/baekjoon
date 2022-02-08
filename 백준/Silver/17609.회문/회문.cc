#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int isPalindrome(string str)
{
    int size = str.length();
    string strReverse = str;
    reverse(strReverse.begin(), strReverse.end());
    if(str == strReverse) return 0;
    else
    {
        int idx = 0;
        string tmp_str = str;
        string tmp_reverse = strReverse;

        for(; idx < size; idx++)
            if(str[idx] != strReverse[idx]) 
                break;
        str.erase(str.begin() + idx, str.begin() + idx + 1);
        strReverse.erase(strReverse.begin() + size-idx-1, strReverse.begin()+size-idx);
        tmp_str.erase(tmp_str.begin() + size-idx-1, tmp_str.begin()+size-idx);
        tmp_reverse.erase(tmp_reverse.begin() + idx, tmp_reverse.begin() + idx + 1);    
        if(str == strReverse || tmp_str == tmp_reverse)
            return 1;
        return 2;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    while(n--)
    {
        string str;
        cin >> str;
        cout << isPalindrome(str) << '\n';
    }
    return 0;
}