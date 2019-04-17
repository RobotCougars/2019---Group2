#include <kipr/botball.h>


//Functions for Servo's to pick up blue poms and put it in the blue container:
int pomsPickup(){
    enable_servos();
    set_servo_position(0,0);
    set_servo_position(1,900);
    msleep(1000);
    set_servo_position(1,700);
    msleep(3000);
    motor(3,40);
    msleep(500);
    motor(3,0);
    set_servo_position(0,600);
    msleep(1000);
    set_servo_position(1,900);
    msleep(3000);
	motor(3,-50);
    msleep(500);
    
    return 0;
}


//Following the black/silver tapes:
int WalkTheLine(AnalogValueZero, AnalogValueOne){
	if (analog(0) >= AnalogValueZero && analog(1) >= AnalogValueOne){
		motor(0,80);
		motor(2,80);
    }
    else if (analog(0) < AnalogValueZero || analog(1) < AnalogValueOne){
        if (analog(0) < AnalogValueZero){
            sharpRight();
        }
        if (analog(1) < AnalogValueOne){
            sharpLeft();
        }
    }
    return(0);
}


//Movement Functions:
int sharpLeft(x,t){
    msleep(t);
    motor(0,x);
    return 0;
}             

int sharpRight(y,t){
    msleep(t);
    motor(1,y);
    return 0;
}

int movement(x,y,t){
    msleep(t);
    motor(0,x);
    motor(1,y);
    return 0;
}

//First two black tape readings:
int blackReadingone(black){
    typedef enum { false, true } bool;
      
	if (analog(0) == black){
		bool firstblack = true;
		while (firstblack){
            movement(80,80);
			if (analog(0) == black && analog(1) == black){
				firstblack = false;
                }
        }
    }
	return (1);
}



//Main code for the Lego's actions:
int main(){
    typedef enum { false, true } bool;
    bool start = true;
    int black = 3000;
    int blue = 180;
    int silver = 200;
    int white = 190;
    while (start) {
        motor(0,80);
        motor(1,80);
        int firstblack = blackReadingone(black);
        if ( firstblack == 1) {
            sharpLeft(80,1500);
            break;
        }
    } 
    WalkTheLine(black, silver);
    if (analog(3) > 3000){
        movement(-30,-30,1000);
        sharpRight(80,1500);
    }
    pomPiles = 0;
    while (pomPiles != 5){
        motor(0,30);
        motor(1,30);
        if (analog(3) > 2500){
            pomsPickup();
            pomPiles += 1;
        }
        if (pomPiles == 5){
            break;
        }
    }
    
    ao();
    
    return 0;
    
}




