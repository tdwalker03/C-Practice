#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "TestCode.h"

// Refer to README.md for the problem instructions

int writeNames(const char **fnames, const char **lnames, int sz, const char *fileName)
{
    /**
     * @brief Outputs names in format (Last name, First name) to a txt file from two seperate chracter arrays
     * @param fnames An array of first names.
     * @param lnames An array of last names.
     * @param sz An integer representing how many names are in each array.
     * @param fileName A character array containing the file name to write to.
     * @return int 1 for success, 0 for failure
     */

    // Validate inputs
    if (fnames == NULL || lnames == NULL || fileName == NULL || sz <= 0)
    {
        return 0;
    }

    // Validate that no first name or last name is empty
    for (int i = 0; i < sz; i++)
    {
        if (strlen(fnames[i]) == 0 || strlen(lnames[i]) == 0)
        {
            return 0;
        }
    }

    FILE *file = fopen(fileName, "w");
    if (file == NULL)
    {
        return 0;
    }

    // Write each name to the file
    for (int i = 0; i < sz; i++)
    {
        // Write last name with capital first letter, add comma at the end
        fprintf(file, "%c%s, ", toupper(lnames[i][0]), lnames[i] + 1);

        // Write first name with capital first letter
        fprintf(file, "%c%s", toupper(fnames[i][0]), fnames[i] + 1);

        // Add a newline after every name except the last one
        if (i < sz - 1)
        {
            fprintf(file, "\n");
        }
    }

    // Close the file
    fclose(file);

    return 1;
}