/*WAP which print itself on the output screen*/
#include <stdio.h>
int main() {
    FILE *fp;
    char a;
    fp = fopen("print_itself.c","r");
    do {
         a = getc(fp);
         putchar(a);
    }
    while(a != EOF);
    fclose(fp);
    return 0;
}
