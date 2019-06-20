#include<iostream>
#define ISLEAP(x) (x % 4 == 0 && x % 100 != 0) || (x % 400 == 0)

int DayOfMonth[13][2] = {
    0,0,
    31,31,
    28,29,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
};

struct Day{
    int d, m, y;
    void next_day(){
        d++;
        if(d > DayOfMonth[m][ISLEAP(d)]){
            d = 1;
            m++;
            if(m > 12){
                m = 1;
                y++;
            }
        }
    }
};

int hash[5001][13][32];
int abs(int x){
    return x > 0 ? x : -x;
}

int main(){
    Day tmp_day;
    tmp_day.d = 1;
    tmp_day.m = 1;
    tmp_day.y = 0;
    int count = 0;
    while(tmp_day.y < 5001){
        hash[tmp_day.y][tmp_day.m][tmp_day.d] = count;
        count++;
        tmp_day.next_day();
    }
    
    int y1, m1, d1;
    while(scanf("%4d%2d%2d", &y1, &m1, &d1) != EOF){
        int y2, m2, d2;
        scanf("%4d%2d%2d", &y2, &m2, &d2);
        int diff = abs(hash[y1][m1][d1] - hash[y2][m2][d2]) + 1;
        printf("%d\n", diff);
    }
    return 0;
}