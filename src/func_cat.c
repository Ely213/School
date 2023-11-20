#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "s21_cat.h"

void numerating_all() {
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

void numerating() {

}

void end_of_str() {

}

void compress() {

}

void chg_tag() {

}

void end_of_str() {

}

void chg_tag() {

}

void offset() {

}