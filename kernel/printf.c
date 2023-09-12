#include "printf.h"
#include "../uart/uart1.h"

#define MAX_PRINT_SIZE 256
int precision = 6;

// This function is called by printf to print out a string
void printf(char *string,...) {
    
	va_list ap;
	va_start(ap, string);

	//Create a buffer to store the formated string
	char buffer[MAX_PRINT_SIZE];

	for (int i = 0; i < MAX_PRINT_SIZE; i++) {
		buffer[i] = 0;
	}

	int buffer_index = 0;

	//Create a temp buffer to store the integer value
	char temp_buffer[MAX_PRINT_SIZE];

	//Parse the string
	while(1) {
		// Check if we reach the end of the string
		if (*string == 0)
			break;

		// Check if we have a format specifier
		if (*string == '%') {
			string++;

			if (*string == 'd') {
				string++;
				int x = va_arg(ap, int);
				int temp_index = MAX_PRINT_SIZE - 1;

				do {
					temp_buffer[temp_index] = (x % 10) + '0';
					temp_index--;
					x /= 10;
				} while(x != 0);

				for(int i = temp_index + 1; i < MAX_PRINT_SIZE; i++) {
					buffer[buffer_index] = temp_buffer[i];
					buffer_index++;
				}

			} 
           
		}
        
        else {
			buffer[buffer_index] = *string;
			buffer_index++;
			string++;
        }
        
		if (buffer_index == MAX_PRINT_SIZE - 1)
			break;
	}

	va_end(ap);


	//Print out formated string
	uart_puts(buffer);
}