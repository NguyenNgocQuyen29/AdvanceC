#include <stdio.h>
#include <stdarg.h>
#include "IoTDeviceControlSystem.h"

int main(){
    Process(LIGHT, ON);
    Process(AIR_CONDITIONER, ON, SET_TEMPERATURE, 30.0);
    Process(AIR_CONDITIONER, ON, SET_MODE, "làm mát");
    Process(FINGERPRINT_LOCK, LOCK);
    Process(MUSIC_PLAYER, ON, INCREASE_VOLUME, 10);
    Process(MUSIC_PLAYER, ON, CHANGE_TRACK, "Cause I love You");
    return 0;
}