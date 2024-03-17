#include <stdio.h>
#include <stdarg.h>

typedef struct Data{
    int x;
    double y;
}Data;
void display(int count,...){
    va_list abc;
    va_start(abc, count);
    int res;
    for(int i=0;i<count;i++){
        Data tmp = va_arg(abc, Data);
        printf("Data.x at %d is: %d\n", i, tmp.x);
        printf("Data.y at %d is: %f\n", i, tmp.y);
    }
    va_end(abc);
}
int main(){
    display(3, (Data){2,5.0}, (Data){10, 58.0}, (Data){30, 48.0});
    return 0;

}