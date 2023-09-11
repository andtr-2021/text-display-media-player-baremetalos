#include "../uart/uart1.h"
#include "mbox.h"
#include "framebf.h"
#include"../gcclib/stdbool.h"
#include "mbox.h"
#include "image.h"
#include "font.h"

// array of name of the image
char *image_name[5] = {"epd_bitmap_0001", "epd_bitmap_0002", "epd_bitmap_0003", "epd_bitmap_0004", "epd_bitmap_0005"};

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

// strlen funciton
int my_strlen(const char *str)
{
    int len = 0;
    while (*str)
    {
        len++;
        str++;
    }
    return len;
}

void play_video() {
    
    for (int i = 0; i < my_strlen(image_name); i++)
    {
        uart_puts("\nPlaying video: ");
        unsigned long image = image_name[i];
        // Draw the image
        drawImage(0, 0, image, 640, 368);
        uart_puts(image_name[i]);
        // Wait for 33 miliseconds so that it is 30 fps
        waitMiliSeconds(1000);      
    
    }
}


void main()
{
    // set up serial console
    uart_init();

    // Initialize frame buffer
    framebf_init();

    // play_video();
    
    // drawChar(10, 10, epd_bitmap_a, 0x00FFFFFF, 0x00000000);

    // .drawChar(10, 10, epd_bitmap_a, 100, 100);

    // drawCharWithColors(10, 10, epd_bitmap_a, 100, 100,  0xFFFF0000, 0xFF0000FF);

    drawScaledDown(200, 210, epd_bitmap_a, 100, 100, 0xFFFF0000, 0xFF0000FF, 2);

    unsigned long *studentName1[2] = {epd_bitmap_a, epd_bitmap_n};
    drawStrScaledDown(10, 10, studentName1, 100, 100, 0xFFFF0000, 0xFF0000FF, 2);

    unsigned long *studentName2[2] = {epd_bitmap_n, epd_bitmap_a};
    drawStr(10, 110, studentName2, 100, 100, 0xFFFF0000, 0xFF0000FF);
    
    



}