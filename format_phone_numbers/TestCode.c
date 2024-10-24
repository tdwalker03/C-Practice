#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Refer to README.md for the problem instructions

char **formatNums(const char **nums)
/**
 * @brief Formats an array of strings containing numbers into phone number format.
 * @param nums An array of strings containing raw phone numbers with 10 digits each.
 * @return char** A dynamically allocated array of formatted strings, or NULL on error.
 */
{
    // Check if array is NULL
    if (nums == NULL)
    {
        return NULL;
    }

    // Allocate memory for 10 formatted numbers
    char **formatted_nums = malloc(10 * sizeof(char *));
    if (!formatted_nums)
        return NULL;

    // Loop through each input number
    for (int i = 0; i < 10; i++)
    {
        // Check if any spot in array is NULL, clean up and return NULL
        if (nums[i] == NULL)
        {
            // Free any previously allocated strings
            for (int j = 0; j < i; j++)
            {
                free(formatted_nums[j]);
            }
            free(formatted_nums); // Free the array itself
            return NULL;
        }

        // Count the number of didgits in the number string
        int digit_count = 0;
        const char *current_num = nums[i];
        for (int j = 0; current_num[j] != '\0'; j++)
        {
            if (isdigit(current_num[j]))
            {
                digit_count++;
            }
        }

        // Make sure the number count is exactly 10
        if (digit_count != 10)
        {
            for (int j = 0; j < i; j++)
            {
                free(formatted_nums[j]);
            }
            free(formatted_nums);
            return NULL;
        }

        // Allocate memory for the formatted phone number (14 chars and null terminator)
        formatted_nums[i] = malloc(15);
        if (!formatted_nums[i]) // Memory allocation failed
        {
            for (int j = 0; j < i; j++)
            {
                free(formatted_nums[j]);
            }
            free(formatted_nums);
            return NULL;
        }

        // Format the digits into the standard phone number format (XXX) XXX-XXXX
        int digit_index = 0;
        for (int j = 0; current_num[j] != '\0'; j++)
        {
            if (isdigit(current_num[j]))
            {
                // Add opening parentheses for the area code
                if (digit_index == 0)
                {
                    formatted_nums[i][0] = '(';
                }
                // Add closing parentheses and space after area code
                else if (digit_index == 3)
                {
                    formatted_nums[i][4] = ')';
                    formatted_nums[i][5] = ' ';
                }
                // Add hyphen after the next 3 digits
                else if (digit_index == 6)
                {
                    formatted_nums[i][9] = '-';
                }
                // Insert digits in the correct positions
                if (digit_index < 3)
                {
                    formatted_nums[i][digit_index + 1] = current_num[j];
                }
                else if (digit_index < 6)
                {
                    formatted_nums[i][digit_index + 3] = current_num[j];
                }
                else
                {
                    formatted_nums[i][digit_index + 4] = current_num[j];
                }

                digit_index++;
            }
        }

        // Add null terminator at the end of string
        formatted_nums[i][14] = '\0';
    }

    return formatted_nums;
}
