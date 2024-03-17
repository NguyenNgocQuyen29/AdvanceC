#include <stdio.h>
#include <stdarg.h>


typedef enum{
    TEMPERATURE_SENSOR,
    PRESSURE_SENSOR
}SensorType;
void processSensorData(SensorType Type,...){
    va_list arg;
    va_start(arg,Type);
    switch(Type){
        case TEMPERATURE_SENSOR:{
            int number = va_arg(arg,int);
            int sensorId = va_arg(arg,int);
            float temperature = va_arg(arg,double);
            printf("Temperature sensor ID: %d, reading: %.2f degrees \n",sensorId, temperature);
            break;
        }
        case PRESSURE_SENSOR:{
            int number = va_arg(arg,int);
            int sensorID = va_arg(arg,int);
            int pressure = va_arg(arg,int);
            printf("Pressure sensor ID: %d, reading: %d Pa", sensorID, pressure);
            break;
        }
    va_end(arg);
    }
}
int main(){
    processSensorData(TEMPERATURE_SENSOR, 8, 1, 36.5);
    processSensorData(PRESSURE_SENSOR, 2, 2, 101111);
    return 0;
}