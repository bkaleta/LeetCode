#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0)
        return false;
    long org = x, rev = 0, dig = 0;

    while (org > 0)
    {
        dig = org % 10;
        rev = rev * 10 + dig;
        org /= 10;
    }
    return x == rev;
}