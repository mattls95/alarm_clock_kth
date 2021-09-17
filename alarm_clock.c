/*
Mattias Lindgren
mattls@kth.se
*/


#include <stdio.h>
#include <stdlib.h>


void print_number(int);
void update_time(int, int);
void check_time(int, int ,int ,int ,int ,int);

int main() 
{
    int present_time; 
    int alarm_time;

    printf("What time is it? ");
    scanf("%d", &present_time);

    printf("What time should the alarm be set to? ");
    scanf("%d", &alarm_time);

    update_time(present_time, alarm_time);
    return 0;
}

/*
The function prints time and adds a ':' between hours,minutes and seconds an a extra zero if needded
Example: 0:0:0 becomes 00:00:00
*/

void print_time(int present_hour, int present_min, int present_sec)
{
    printf("%02d:%02d:%02d\n", present_hour, present_min, present_sec);
}

/*
Checks if condition for alarm has been meet and exits program if it has
*/

void check_time(int present_hour, int present_min, int present_sec, int alarm_hour, int alarm_min, int alarm_sec)
{
    if (present_hour == alarm_hour && present_min == alarm_min && present_sec == alarm_sec)
    {
        printf("Alarm!");
        exit(0);
    }
}

/*
The function updates the time in three steps first it compares the hours and updates hours, minutes and seconds if 
nedded. It then compares minutes and updates minutes and seconds if needed, finally it updates seconds.
After each check it calls the check_time and print_time function.
*/

void update_time(int present_time, int alarm_time) 
{
    int present_hour = present_time/10000;
    int present_min = (present_time/100) % 100;
    int present_sec = (present_time % 100);

    int alarm_hour = alarm_time/10000;
    int alarm_min = (alarm_time/100) % 100;
    int alarm_sec = alarm_time % 100;

    while (present_hour != alarm_hour) {
            if (present_sec < 60) {
                present_sec++;
                if (present_sec == 60) {
                    present_sec = 0;
                    present_min++;
                }
                if (present_min == 60) {
                    present_min = 0;
                    present_hour++;
                }
                if (present_hour == 24) {
                    present_hour = 0;
                }
                check_time(present_hour, present_min, present_sec, alarm_hour, alarm_min, alarm_sec);
                print_time(present_hour, present_min, present_sec);
            }
        
    }

    while(present_min != alarm_min)
    {
       if(present_sec < 60) {
                present_sec++;

                if (present_sec == 60) {
                    present_sec = 0;
                    present_min++;
                }
        check_time(present_hour, present_min, present_sec, alarm_hour, alarm_min, alarm_sec);
        print_time(present_hour, present_min, present_sec);
    }

    }
 while(present_sec != alarm_sec)
    {
        present_sec++;
        check_time(present_hour, present_min, present_sec, alarm_hour, alarm_min, alarm_sec);
        print_time(present_hour, present_min, present_sec);
    }

}


