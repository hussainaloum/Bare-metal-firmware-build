/**
  ******************************************************************************
  * @file    main.c
  * @author  Hussain Aloum
  * @version V1.0
  * @brief   main file, which shows how to an example of Semihosting on
  *           ARM cortex-M MCUs
  ******************************************************************************
*/

#include<stdio.h>
#include<stdint.h>

//semihosting init function 
extern void initialise_monitor_handles(void);

int main(void)
{
	initialise_monitor_handles();   //Has to be called before calling printf()
	printf("Hello World\n");

	for(;;);		                    //infinite loop
}
