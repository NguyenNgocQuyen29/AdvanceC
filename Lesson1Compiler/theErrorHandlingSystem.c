#include <stdio.h>

#define HANDLE_ERROR(condition, action, message) do{ if(condition){action(message);}}while(0)


//Hành động 1: In thông điệp lôi
void printError(const char *message){
    printf("Error: %s\n", message);
}
//Hành động 2: In thông điệp cảnh cáo
void printWarning(const char *message){
    printf("Warning: %s\n",message);
}
//Hành động 3: In thông tin
void printInfor(const char *message){
    printf("Infor: %s\n",message);
}
//Hành động 4: In thông điệp gỡ lỗi
void printDebug(const char *message){
    printf("Debug: %s\n",message);
}
//Hành động 5: In thông điệp khẩn cấp
void printCritical(const char *message){
    printf("SOS: %s\n",message);
}
//Hành động 5: In thông điệp thành công
void printSuccess(const char *message){
    printf("Success: %s\n",message);
}
int main(){
    int C = 7;
    HANDLE_ERROR(C == 10,printError, "C is not equal to 10");
    HANDLE_ERROR(C > 10,printError, "C is not higher than 10");
    HANDLE_ERROR(C < 10,printSuccess, " C is less than 10");
    return 0;
}
