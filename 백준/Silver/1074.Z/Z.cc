#include <stdio.h>
#include <math.h>

int main()
{
    int num , n, m ;
    int cnt = 0;
    scanf("%d %d %d", &num, &n, &m);

    while(num > 0) {
        int div_1 = int(pow(2, num - 1));
        int div_2 = int(pow(2, num));
        int power_num = div_1 * div_1;
        if(0 <= n && n < div_1 && 0 <= m && m < div_1)  
            cnt += 0 * power_num;
        else if(0 <= n && n < div_1 && div_1 <= m && m < div_2)
            cnt += 1 * power_num;
        else if(div_1 <= n && n < div_2 && 0 <= m && m < div_1)
            cnt += 2 * power_num;
        else if(div_1 <= n && n < div_2 && div_1 <= m && m < div_2)
            cnt += 3 * power_num;
        num--;
        n %= div_1;
        m %= div_1;
    }
    printf("%d", cnt);
    return 0;
}
