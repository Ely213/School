#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_file() ;

int main() {
    read_file();
    return 0;
}

void read_file() {
    FILE *f;
    f = fopen("Test.txt", "r");
    char str[256];
    char chr;
    int count = 0;
    while(fread(&chr, sizeof(char), 1, f) && chr != '\n') {
        printf("%c", chr);
        str[count] = chr;
        count++;
    }
    fclose(f);
    scan_flag(str, count);
}

void scan_flag(char *str, int count) {
    //Функция memmem() ищет первое совпадение с подстрокой needle длиной 
    //needlelen в области памяти haystack длиной haystacklen.  
    int len = strlen(str);
    char b[16] = "-number-nonblank";
    char n[7] = "-number";
    char s[14] = "-squeeze-blank";
    int a = strchr(str, "-");
    for(int i = 0; i < count; i++) {
        if(str[a+1] == 'n' ) {
            numerating_all();
        } else if(str[a+1] == 'b') {
            numerating();
        } else if(str[a+1] == 'e') {
            end_of_str();
            offset();
        } else if(str[a+1] == 's') {
            compress();
        } else if(str[a+1] == 't') {
            chg_tag();
            offset();
        } else if(str[a+1] == 'E') {
            end_of_str();
        } else if(str[a+1] == 'T') {
            chg_tag();
        } else if(memmem(b, 16, str, len) != NULL) {
            numerating();
        } else if(memmem(n, 7, str, len) != NULL) {
            numerating_all();
        } else if(memmem(s, 14, str, len) != NULL) {
            compress();
        }
    }
}