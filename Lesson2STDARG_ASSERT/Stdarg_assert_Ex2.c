#include <stdio.h>
#include <stdarg.h>

int sum(int count,...){
    va_list abc;
    va_start(abc, count);
    int res = 0;
    for(int i=0;i<count;i++){
        res += va_arg(abc, int);
    }
    va_end(abc);
    return res;
}
int main(){
    printf("Sum is: %d ", sum(5, 2, 7, 9, 5, 8));
    return 0;
}