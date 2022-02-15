#include <stdio.h>
#define MAX 1001

int min(int a, int b);
int main()
{
    int ary[MAX][3] = {0};
    int n;
    int lwr;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int r,g,b;
        scanf("%d %d %d", &r, &g, &b);
        ary[i][0] = r + min(ary[i-1][1] , ary[i-1][2]);
        ary[i][1] = g + min(ary[i-1][0] , ary[i-1][2]);
        ary[i][2] = b + min(ary[i-1][0] , ary[i-1][1]);
    }
    lwr = min(min(ary[n][0] , ary[n][1]), ary[n][2]);
    printf("%d", lwr);
    return 0;
}
int min(int a, int b)
{
    return (a < b ? a : b);
}