#include <kipr/botball.h>

void drive_forward();
void turn_left_90();
void turn_around();
//void lift_arm();
//void close_claw();

int main()
{
    create_connect();
    drive_forward();
    msleep(3000);
    
    turn_left_90();
    turn_around();
    create_stop();
    create_disconnect();
    return 0;
}


void drive_forward(){
    create_drive_direct(100, 100);
}

void turn_left_90(){
    set_create_total_angle(0);
    while (get_create_total_angle() < 90){
        create_drive_direct(-200, 200);
    }
}

void turn_around(){
    set_create_total_angle(0);
    while (get_create_total_angle() < 180){
        create_drive_direct(-200, 200);
    }
}
