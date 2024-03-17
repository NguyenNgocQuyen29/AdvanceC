#ifndef _IOTDEVICECONTROLSYSTEM_H
#define _IOTDEVICECONTROLSYSTEM_H

#include <stdio.h>
#include <stdarg.h>



typedef enum{
    LIGHT,
    AIR_CONDITIONER,
    FINGERPRINT_LOCK,
    MUSIC_PLAYER,
}DeviceType;

typedef enum{
    ON,            //light
    OFF,
    SET_TEMPERATURE, //air_conditioner
    SET_MODE,
    UNCLOCK,        //fingerprint_lock
    LOCK,
    INCREASE_VOLUME, //music_player
    DECREASE_VOLUME,
    CHANGE_TRACK,
} CommandType;

void Process(DeviceType device,...){
    va_list arg;
    va_start(arg, device);
    CommandType command2 = va_arg(arg, CommandType); //biến số thứ 2 nhập vào
    switch (device){
        //trường hợp 1: input Process(LIGHT,ON/OFF)
        case LIGHT:
            switch(command2){
                case ON:
                    printf("LIGHT is turned on \n");
                    break;
                case OFF:
                    printf("LIGHT is turned off \n");
                    break;
                default:
                    printf("Khong hop le!\n");
                    break;
            }
        break;
        //trường hợp 2: input Process(AIR_CONDITIONER, ON, SET_TEMPERATURE, 30)   
        case AIR_CONDITIONER:
            switch(command2){
                case ON:
                    CommandType command3 = va_arg(arg, CommandType); // thứ 3
                    switch (command3){
                        case SET_TEMPERATURE:
                            float tem = va_arg(arg, double); //thứ 4
                            printf("AIR CONDITIONER is turned on %.2f degree\n", tem);
                            break;
                        case SET_MODE:  //mode là chế độ của điều hòa: làm ấm, làm lạnh, quạt, auto....
                            char *mode = va_arg(arg, char*);
                            printf("AIR CONDITIONER is turned on with mode: %s\n", mode);
                            break;
                        default:
                            printf("Không hợp lệ\n");
                            break;
                    }
                    break;
                case OFF:
                    printf("AIR_CONDITIONER is turn off \n");
                    break;
            }
        break;
        //trường hợp 3: Process(FINGERPRINT_LOCK, UNLOCK); 
        case FINGERPRINT_LOCK:
            switch(command2){
                case LOCK:
                    printf("FINGERPRINT LOCK is locked \n");
                    break;
                case UNCLOCK:
                    printf("FINGERPRINT LOCK is unlocked \n");
                    break;
                default:
                    printf("Không hợp lệ \n");
                    break;
            }
        break;
        //trường hợp 4:Process(MUSIC_PLAYER, ON, CHANGE_TRACK,"Cause I Love You");
        case MUSIC_PLAYER:
            switch(command2){
                case ON:
                    CommandType command3 = va_arg(arg, CommandType);
                    switch(command3){
                        case INCREASE_VOLUME:
                            int volume = va_arg(arg, int);
                            printf("MUSIC PLAYER is turned on and volume is increased to %d\n", volume);
                        break;
                        case DECREASE_VOLUME:
                            int volume1 = va_arg(arg, int);
                            printf("MUSIC PLAYER is turned on and volume is decreased to %d\n", volume1);
                        break;
                        case CHANGE_TRACK:
                            char* new_hit = va_arg(arg, char*);
                            printf("MUSIC_PLAYER is turned on and moving on to a new song called: %s\n", new_hit);
                        break;
                        default:
                            printf("Không hợp lệ \n");
                        break;
                    }
                break;
                case OFF:
                    printf("MUSIC is turned off \n");
                    break;
                default:
                    printf("Khong hop le \n");
                    break;
            }
        break;
        default:
            printf("Không hợp lệ vui lòng nhập lại \n");
        break;


    }
    va_end(arg);

}

#endif