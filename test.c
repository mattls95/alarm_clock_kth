#include <stdio.h>


void print_time(int, int, int);
void update_time(int, int);

int main() {
    int present_time; 
    int time_for_alarm;

    printf("What time is it? ");
    scanf("%d", &present_time);

    printf("What time should the alarm be set to? ");
    scanf("%d", &time_for_alarm);

    update_time(present_time, time_for_alarm);
    printf("ALARM");

    return 0;
}

void print_time(int present_hour, int present_min, int present_sec)
{
    printf("%d:%d:%d\n", present_hour, present_min, present_sec);
}

void update_time(int present_time, int time_for_alarm) {
    int present_hour = present_time/10000;
    int present_min = (present_time/100) % 100;
    
    int present_sec = (present_time % 100);
    int alarm_hour = time_for_alarm/10000;

    int alarm_min = (time_for_alarm/100) % 100;
    int alarm_sec = (time_for_alarm % 100);

    while (present_hour != alarm_hour && present_min != alarm_min) {
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
                print_time(present_hour, present_min, present_sec);
            }
        
    }
    while (present_min != alarm_min) {
        if (present_hour == alarm_hour && present_min == alarm_min && present_sec == alarm_sec) {
            printf("ALARM");
        }
        else {
            if (present_sec <= 60) {
                present_sec++;

                if (present_sec == 60) {
                    present_sec = 0;
                    present_min++;
                }
                print_time(present_hour, present_min, present_sec);
            }
        }
    }
    while (present_sec != alarm_sec) {
            print_time(present_hour, present_min, present_sec);
        present_sec++;
    }
}
