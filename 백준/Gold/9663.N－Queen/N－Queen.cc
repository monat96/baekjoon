#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const int MAX = 15;

bool vertical[MAX];
bool isValid1[2*MAX-1];
bool isValid2[2*MAX-1];

int cnt = 0;

void nQueen(int size, int row)
{
    if(size == row)
    {
        cnt++;
        return ;
    }
    for(int col = 0; col < size; col++)
    {
        if(vertical[col] || isValid1[row + col] || isValid2[size+row-col-1]) continue;
        vertical[col]=true;
        isValid1[row+col]=true;
        isValid2[size+row-col-1]=true;
        nQueen(size, row+1);
        vertical[col]=false;
        isValid1[row+col]=false;
        isValid2[size+row-col-1]=false;
    }

}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    nQueen(n, 0);
    cout << cnt;
    
    return 0;
}