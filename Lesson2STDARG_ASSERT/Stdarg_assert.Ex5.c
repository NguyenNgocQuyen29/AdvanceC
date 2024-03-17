#include <stdio.h>
#include <stdarg.h>

typedef enum {
    TURN_ON,
    TURN_OFF,
    SET_LEVEL,
    SEND_MESSAGE
}CommandType;

void sendCommand(CommandType Type,...){
    va_list abc;
    va_start(abc, Type);

    switch(Type){
        case TURN_ON:
        case TURN_OFF:{
            int ID = va_arg(abc, int);
            printf("Command: %s, DeviceID: %d\n", Type == TURN_ON?"TURN ON":"TURN OFF", ID);
            break;
        }
        case SET_LEVEL:{
            int ID = va_arg(abc, int);
            int level = va_arg(abc, int);
            printf("Set level of deviceID %d to %d\n", ID, level);
            break;
        }
        case SEND_MESSAGE:{
            char *mess = va_arg(abc, char*);
            printf("Send message: %s\n", mess);
            break;
        }
    }
    va_end(abc);
}
int main(){
    sendCommand(TURN_ON, 1);
    sendCommand(TURN_OFF, 2);
    sendCommand(SET_LEVEL, 1, 3);
    sendCommand(SEND_MESSAGE, "NgocQuyen");
    return 0;
}