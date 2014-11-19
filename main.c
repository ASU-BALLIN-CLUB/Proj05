//
//  main.c
//
//	Proj05
//  Lab Partners: Sean Slamka, Aydin Balci
//  Email: sslamka@asu.edu, abalci@asu.edu
//  CSE325 Embedded Microprocessor Systems
//  Fall 2014
//

#include"gpio.h"
#include"global.h"
#include"int.h"
#include"uc_dipsw.h"
#include"gpt.h"
#include"oct_rgb_led.h"
#include"pit.h"
#include"pwm.h"
#include"uc_pushb.h"
#include"uc_led.h"

typedef enum {
	idle_mode = 0,
	play_mode = 1,
	xfer_mode = 2
} mode_t;

static void hw_init();
static void pushb_1_callback();
static void pushb_2_callback();
static void run();
static mode_t mode = idle_mode;

static void hw_init()
{
	int_inhibit_all();
	uc_led_init();
	uc_pushb_init(uc_pushb_1, pushb_1_callback);
	uc_pushb_init(uc_pushb_2, pushb_2_callback);

	int_uninhibit_all();
}

static void pushb_1_callback()
{
	if (mode == idle_mode)
	{
		mode = play_mode;
		//uc_led_on((gpio_pin_t)uc_led_2);
		//led--;
	}
	else
	{
		mode = idle_mode;
		//uc_led_off((gpio_pin_t)uc_led_1);
		//led++;
	}
}

static void pushb_2_callback()
{
	if (led == idle_mode)
	{
		mode = xfer_mode;
		//uc_led_on((gpio_pin_t)uc_led_2);
		//led--;
	}
	else
	{
		mode = idle_mode;
		//uc_led_off((gpio_pin_t)uc_led_1);
		//led++;
	}
}

static void run()
{
	if(mode == idle_mode)
	{


	}
	else if(mode == play_mode)
	{

	}
	else
	{

	}
}
