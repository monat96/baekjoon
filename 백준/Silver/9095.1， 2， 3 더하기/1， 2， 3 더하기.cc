#include <stdio.h>

int recursion(int n);

int main()
{
    int n;
    int index;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &index);
        printf("%d\n", recursion(index));
    }   
    return 0;
}
int recursion(int n)
{
    if(n == 0)
        return 1;
    else if(n < 0)
        return 0;
    else 
        return recursion( n - 1 ) + recursion( n - 2 ) + recursion( n - 3 );
}