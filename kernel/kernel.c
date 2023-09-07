#include "../uart/uart1.h"
#include "mbox.h"
#include "framebf.h"
#include"../gcclib/stdbool.h"
#include "mbox.h"

// Logic of strcmp from https://www.techiedelight.com/implement-strcmp-function-c/
bool my_strcmp(const char *str1, const char *str2)
{
    while (*str1 && *str2)
    {
        if (*str1 != *str2)
        {
            return false;
        }
        str1++;
        str2++;
    }
    return (*str1 == '\0' && *str2 == '\0');
}
// Logic for implementation of strstr() from string.h in C from https://sillycodes.com/strstr-function-implementation-in-c-language/
bool my_strcontain(const char *str, const char *substr)
{
    while (*str)
    {
        //
        if (*str == *substr)
        {
            // Save the current position in str
            const char *temp_str = str;
            const char *temp_substr = substr;

            // Check if the substring matches
            while (*temp_str && *temp_substr && *temp_str == *temp_substr)
            {
                temp_str++;
                temp_substr++;
            }

            // If the substring is fully matched, return true
            if (!*temp_substr)
            {
                return true;
            }
        }
        str++;
    }
    return false;
}





void main()
{
    // set up serial console
    uart_init();

    // Initialize frame buffer
    framebf_init();
    
}