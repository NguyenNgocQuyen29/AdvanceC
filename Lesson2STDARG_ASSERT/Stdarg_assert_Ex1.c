#include <stdio.h>
#include <stdarg.h>


void display(int count, ...) {
    va_list args;   //type for iterating arguments, args is a type of va_list, is a pointer to store addresses transmisson parameters
    va_start(args, count);//create memory areas, count:how many arguments have been passed, initializes ARGS list to point fist variable arguments
   

    for (int i = 0; i < count; i++) {
        printf("Value at %d: %d\n", i, va_arg(args,int)); //va_arg: find the next arguments from the list
    }

    va_end(args);//free up memory 
}

int main()
{
    display( 4, 8, 15, 10, 13);

    return 0;
}

