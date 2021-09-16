/*
Mattias Lindgren
1995-05-05-6235
mattls@kth.se
*/

#include <stdio.h>

int get_time();
int update_time();
void print_time(int);
int check_time();


int time_delay();

//@MattiasLindgren278
int main()
{
    int present_time, time_for_alarm;
    puts("What time is it?");
    present_time = get_time();
    puts("What time should the alarm be set to?");
    time_for_alarm = get_time();
    return 0;
}

int get_time()
{
    int time;
    scanf("%d", &time);
    return time;
}

void check_print_time(int time)
{
    if(time < 10)
    {
        printf("0%d", time);
    } else
    {
        printf("%d", time);
    }
}


