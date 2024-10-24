#include <stdio.h>
#include "TestCode.h"

// Refer to README.md for the problem instructions

// copy s2 to s1 using array notation
void copy1(char *const dest, const char *src)
{
    /**
     * @brief Copies string from one pointer to another using array notation.
     * @param dest The destination pointer.
     * @param src The source pointer, where the string is originally.
     * @return Nothing.
     */

    if (src == NULL || dest == NULL)
    {
        return;
    }

    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// copy s2 to s1 using pointer notation
void copy2(char *dest, const char *src)
{
    /**
     * @brief Copies string from one pointer to another using pointer notation.
     * @param dest The destination pointer.
     * @param src The source pointer, where the string is originally.
     * @return Nothing.
     */
    if (src == NULL || dest == NULL)
    {
        return;
    }

    while (*src != '\0')
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
}
