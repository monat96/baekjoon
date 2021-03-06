#include <stdio.h>

int is_prime(int n);

int main()
{
    int cnt = 0;
    int n, index;
    scanf("%d", &n);
    for(int i = 0; i <  n; i++) {
        scanf("%d", &index);
        if(is_prime(index))
            cnt++;
    }
    printf("%d", cnt);
    return 0;
}
int is_prime(int n)
{
    if( n == 1)
        return 0;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0)
            return 0;
    }
    return 1;
}