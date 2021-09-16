#include <stdio.h>


void print_number(int);
void update_time(int, int);

int main() {
    int present_time; 
    int alarm_time;

    printf("What time is it? ");
    scanf("%d", &present_time);

    printf("What time should the alarm be set to? ");
    scanf("%d", &alarm_time);

    update_time(present_time, alarm_time);
    printf("ALARM");

    return 0;
}

void print_time(int present_hour, int present_min, int present_sec)
{
    printf("%02d:%02d:%02d\n", present_hour, present_min, present_sec);
}

void update_time(int present_time, int alarm_time) 
{
    int present_hour = present_time/10000;
    int present_min = (present_time/100) % 100;

    int present_sec = (present_time % 100);
    int alarm_hour = alarm_time/10000;

    int alarm_min = (alarm_time/100) % 100;
    int alarm_sec = (alarm_time % 100);

    while (present_hour != alarm_hour) {
            if (present_sec <= 60) {
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
                //Ändra till do-while
                
                print_time(present_hour, present_min, present_sec);
            }
        
    }
}
