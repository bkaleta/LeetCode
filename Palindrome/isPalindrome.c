#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* strrev(char* str) {
    if (!str || !*str) {
        return str;
    }
    
    char *start = str;
    char *end = str + strlen(str) - 1;
    char temp;

    while (end > start) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    return str;
}


void itoa(int value, char* str, int base) {
    char* ptr = str;
    char* ptr1 = str;
    char tmp_char;
    int tmp_value;

    if (value < 0 && base == 10) {
        *ptr++ = '-';
        value = -value;
    }
    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "0123456789abcdef"[tmp_value - (value * base)];
    } while (value);
    *ptr-- = '\0';
    while (ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr-- = *ptr1;
        *ptr1++ = tmp_char;
    }
}

bool isPalindrome(int x) 
{
    int counter = 0, fake_x = 0, i = 0;
    char *str, *rev_str;
    bool result;

    if (x < 0)
        return false;
    fake_x = x;
    while (fake_x)
    {
        fake_x /= 10;
        counter++;
    }
    str = malloc(sizeof(char) * counter + 1);
    if (!str)
        return false;
    rev_str = malloc(sizeof(char) * counter + 1);
    if (!rev_str)
        return false;
    itoa(x, str, 10);
    strcpy(rev_str, str);
    strrev(rev_str);

    result = strcmp(str, rev_str) == 0;
    free(str);
    free(rev_str);

    return result;
}