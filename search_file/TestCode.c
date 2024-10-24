#include "TestCode.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Refer to README.md for the problem instructions

int searchFile(const char *fname, const char *str)
/**
 * @brief Counts the number of times a substring appears in a file and returns the determined count.
 * @param fname A char pointer representing a file name of a file to read.
 * @param str A char pointer representing a string to search for in the file.
 * @return int The count if all goes well, -1 if the file size is <= 150, -2 if the file in `fname` does not exist, -3 if the string in `str` is NULL or empty.
 */
{
    if (fname == NULL || strlen(fname) == 0)
    {
        return -2; // File doesn't exist, is NULL, or empty
    }

    if (str == NULL || strlen(str) == 0)
    {
        return -3; // Empty or NULL search string
    }

    FILE *fp = fopen(fname, "r");
    if (fp == NULL)
    {
        return -2;
    }

    // Get file size
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    rewind(fp); // Reset file pointer to beginning

    // Check if file size is too small
    if (fileSize <= 150)
    {
        fclose(fp);
        return -1;
    }

    int count = 0;
    char buffer[1024]; // Buffer to read file content

    // Loop through file content
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        char *ptr = strstr(buffer, str); // Search for substring in buffer
        while (ptr != NULL)
        {
            count++;
            ptr = strstr(ptr + strlen(str), str); // Search for next occurrence
        }
    }

    fclose(fp);

    return count;
}