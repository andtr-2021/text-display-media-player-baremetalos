#include "../uart/uart1.h"
#include "mbox.h"
#include "framebf.h"
#include"../gcclib/stdbool.h"
#include "mbox.h"
#include "image.h"
#include "font.h"
#include "colors.h"

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

// strlen function for array
int my_strlen_array(char *str[])
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
    
    for (int i = 0; i < my_strlen(image_name) - 1 ; i++)
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

void freeMemory(unsigned long *str[]) {
    for (int i = 0; i < 14; i++)
    {
        str[i] = 0;
    }
}

void displayTeamInfo() {

    // GROUP 18
    unsigned long *groupEighteen[9]  = {epd_bitmap_g, epd_bitmap_r, epd_bitmap_o, epd_bitmap_u, epd_bitmap_p, epd_bitmap_space , epd_bitmap_num1, epd_bitmap_num8, epd_bitmap_colon};
    drawStrScaledDown(10, 10, groupEighteen, 100, 100, COLOR_PINK, COLOR_WHITE, 2);

    freeMemory(groupEighteen);

    // Le Pham Ngoc Hieu : S3877375
    unsigned long *studentOneName[30]  = {epd_bitmap_l, epd_bitmap_e, epd_bitmap_space , epd_bitmap_p, epd_bitmap_h, epd_bitmap_a, epd_bitmap_m, epd_bitmap_space , epd_bitmap_n, epd_bitmap_g, epd_bitmap_o, epd_bitmap_c, epd_bitmap_space , epd_bitmap_h, epd_bitmap_i, epd_bitmap_e, epd_bitmap_u, epd_bitmap_colon, epd_bitmap_s, epd_bitmap_num3, epd_bitmap_num8, epd_bitmap_num7, epd_bitmap_num7, epd_bitmap_num3, epd_bitmap_num7, epd_bitmap_num5};
    drawStrScaledDown(10, 100, studentOneName, 100, 100, COLOR_ORANGE, COLOR_WHITE, 4);

    freeMemory(studentOneName);

    // Mai Chieu Thuy : s3877746
    unsigned long *studentTwoName[30]  = {epd_bitmap_m, epd_bitmap_a, epd_bitmap_i, epd_bitmap_space , epd_bitmap_c, epd_bitmap_h, epd_bitmap_i, epd_bitmap_e, epd_bitmap_u, epd_bitmap_space , epd_bitmap_t, epd_bitmap_h, epd_bitmap_u, epd_bitmap_y, epd_bitmap_colon, epd_bitmap_s, epd_bitmap_num3, epd_bitmap_num8, epd_bitmap_num7, epd_bitmap_num7, epd_bitmap_num4, epd_bitmap_num6};
    drawStrScaledDown(10, 150, studentTwoName, 100, 100, COLOR_BLUE, COLOR_WHITE, 4);
    
    freeMemory(studentTwoName);

    // Park Anh Kiet : s3681475
    unsigned long *studentThreeName[25]  = {epd_bitmap_p, epd_bitmap_a, epd_bitmap_r, epd_bitmap_k, epd_bitmap_space , epd_bitmap_a, epd_bitmap_n, epd_bitmap_h, epd_bitmap_space , epd_bitmap_k, epd_bitmap_i, epd_bitmap_e, epd_bitmap_t, epd_bitmap_colon, epd_bitmap_s, epd_bitmap_num3, epd_bitmap_num6, epd_bitmap_num8, epd_bitmap_num1, epd_bitmap_num4, epd_bitmap_num7, epd_bitmap_num5};
    drawStrScaledDown(10, 200, studentThreeName, 100, 100, COLOR_RED, COLOR_WHITE, 4);

    freeMemory(studentThreeName);

    // DO TRUONG AN : s3878698
    unsigned long *studentFourName[25]  = {epd_bitmap_d, epd_bitmap_o, epd_bitmap_space , epd_bitmap_t, epd_bitmap_r, epd_bitmap_u, epd_bitmap_o, epd_bitmap_n, epd_bitmap_g, epd_bitmap_space ,epd_bitmap_a, epd_bitmap_n, epd_bitmap_colon, epd_bitmap_s, epd_bitmap_num3, epd_bitmap_num8, epd_bitmap_num7, epd_bitmap_num8, epd_bitmap_num6, epd_bitmap_num9, epd_bitmap_num8};
    drawStrScaledDown(10, 250, studentFourName, 100, 100, COLOR_BLACK, COLOR_WHITE, 4);

    freeMemory(studentFourName);

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


    displayTeamInfo();

    uart_puts("hellow4");

}