#include <stdio.h>

void f();
void a(int n, int *two, int *five);

int main()
{
    f();
    return 0;    
}
void f()
{
    int n, result;
    int two = 0, five = 0;
    scanf("%d", &n);

    while(n > 1) {
        a(n, &two, &five);
        n -= 1;    
    }
    result = (two > five ? five : two);
    printf("%d", result);
}
void a(int n, int *two, int *five)
{
    while(n % 5 == 0) {
        *five += 1;
        n /= 5;
    }
    while(n % 2 == 0) {
        *two += 1;
        n /= 2;
    }
}