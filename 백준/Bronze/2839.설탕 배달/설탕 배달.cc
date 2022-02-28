#include <stdio.h>
int main()
{
    int n;
    int ans;
    scanf("%d", &n);
    
    if(n % 5 == 0) ans = n / 5;
    else if (n % 5 == 1) ans = n / 5 + 1;
    else if (n % 5 == 2 && n >= 12) ans = n / 5 + 2;
    else if (n % 5 == 3) ans = n / 5 + 1;
    else if (n % 5 == 4 && n >= 9) ans = n / 5 + 2;
    else ans = -1;

    printf("%d", ans);
    return 0;   
}