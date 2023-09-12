#include "../uart/uart1.h"
#include "mbox.h"
#include "framebf.h"
#include"../gcclib/stdbool.h"
#include "mbox.h"
#include "./video/image.h"
#include "./video/image1.h"
#include "./video/image2.h"
#include "./video/image3.h"
#include "./video/image4.h"
#include "./video/image5.h"
#include "./video/image6.h"
#include "./video/image7.h"
#include "font.h"
#include "colors.h"

const unsigned long *videoArr[48] = {epd_bitmap_0001, epd_bitmap_0002, epd_bitmap_0003, epd_bitmap_0004, epd_bitmap_0005, epd_bitmap_0006, 
epd_bitmap_0007, epd_bitmap_0008, epd_bitmap_0009, epd_bitmap_0010, epd_bitmap_0011, epd_bitmap_0012, epd_bitmap_0013,
epd_bitmap_0014, epd_bitmap_0015, epd_bitmap_0016, epd_bitmap_0017, epd_bitmap_0018, epd_bitmap_0019, epd_bitmap_0020,
epd_bitmap_0021, epd_bitmap_0022, epd_bitmap_0023, epd_bitmap_0024, epd_bitmap_0025, epd_bitmap_0026, epd_bitmap_0027,
epd_bitmap_0028, epd_bitmap_0029, epd_bitmap_0030, epd_bitmap_0031, epd_bitmap_0032, epd_bitmap_0033, epd_bitmap_0034,
epd_bitmap_0035, epd_bitmap_0036, epd_bitmap_0037, epd_bitmap_0038, epd_bitmap_0039, epd_bitmap_0040, epd_bitmap_0041,
epd_bitmap_0042, epd_bitmap_0043, epd_bitmap_0044, epd_bitmap_0045, epd_bitmap_0046, epd_bitmap_0047, epd_bitmap_0048};


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
    
    for (int i = 0; i < my_strlen_array(videoArr); i++)
    {
        
        
        drawImage(10, 10, videoArr[i], 640, 368);

        waitMiliSeconds(42);  

        clearFrameBufferWithHW(10, 10, 640, 368);

        // or clearFrameBuffer();
    
    
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

    play_video();
    
    // drawChar(10, 10, epd_bitmap_a, 0x00FFFFFF, 0x00000000);

    // .drawChar(10, 10, epd_bitmap_a, 100, 100);


    // displayTeamInfo();

    /*
    uart_puts("Hello World!\n");
    drawImage(10, 10, epd_bitmap_0001, 640, 368);
    waitMiliSeconds(1000);
    uart_puts("Hello World2!\n");
    drawImage(10, 10, epd_bitmap_0048, 640, 368);*/
    /*
    drawImage(10, 10, videoArr[0], 640, 368);
    uart_puts("image 1 is done");
    waitMiliSeconds(42);
    clearFrameBuffer();
    uart_puts(" clear and wait is done");
    drawImage(10, 10, videoArr[6], 640, 368);
    uart_puts("image 7 is done");*/

}