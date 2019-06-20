//
// Created by Acka on 2017. 10. 10..
//

#include <stdio.h>

int get_gcd(int a, int b){
    int temp;
    while(b){
        temp = a;
        a = b; b = temp % b;
    }
    return a;
}

char day[7][10] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

int main()
{
    int s1, s2, t1, t2, h, m;
    scanf("%d:%d", &h, &m); s1 = h * 60 + m;
    scanf("%d:%d", &h, &m); s2 = h * 60 + m;
    scanf("%d:%d", &h, &m); t1 = h * 60 + m;
    scanf("%d:%d", &h, &m); t2 = h * 60 + m;
    if(s1 < s2){
        int temp = s1; s1 = s2; s2 = temp;
        temp = t1; t1 = t2; t2 = temp;
    }

    int G = get_gcd(t1, t2), t, ans = -1;
    for(int i = 0; i < t2 / G; i++){
        t = s1 + i * t1;
        if((t - s2) % t2 == 0){
            ans = t;
            break;
        }
    }

    if(ans < 0) printf("Never\n");
    else{
        ans %= 7 * 24 * 60;
        printf("%s\n", day[ans / (24 * 60)]);
        ans %= 24 * 60;
        printf("%02d:%02d\n", ans / 60, ans % 60);
    }
    return 0;
}
