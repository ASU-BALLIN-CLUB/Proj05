//
//  pwm.c
//
//	Proj05
//  Lab Partners: Sean Slamka, Aydin Balci
//  Email: sslamka@asu.edu, abalci@asu.edu
//  CSE325 Embedded Microprocessor Systems
//  Fall 2014
//

#include "pwm.h"

static uint32 const MCF_PWM_BASE = 0x401B0000;
/*
#define MCF_PWM_PWME    	*((volatile uint8 *) (MCF_PWM_BASE + 0x00)
#define MCF_PWM_PWMPOL  	*((volatile uint8 *) (MCF_PWM_BASE + 0x01)
#define MCF_PWM_PWMCLK  	*((volatile uint8 *) (MCF_PWM_BASE + 0x02)
#define MCF_PWM_PWMPRCLK	*((volatile uint8 *) (MCF_PWM_BASE + 0x03)
#define MCF_PWM_PWMCAE  	*((volatile uint8 *) (MCF_PWM_BASE + 0x04)
#define MCF_PWM_PWMCTL  	*((volatile uint8 *) (MCF_PWM_BASE + 0x05)
#define MCF_PWM_PWMSCLA 	*((volatile uint8 *) (MCF_PWM_BASE + 0x08)
#define MCF_PWM_PWMSCLB 	*((volatile uint8 *) (MCF_PWM_BASE + 0x09)
#define MCF_PWM_PWMCNT(n)	*((volatile uint8 *) (MCF_PWM_BASE + 0x0C)
#define MCF_PWM_PWMPER(n)   *((volatile uint8 *) (MCF_PWM_BASE + 0x14 + (n))
#define MCF_PWM_PWMDTY(n)   *((volatile uint8 *) (MCF_PWM_BASE + 0x1C + (n))
#define MCF_PWM_PWMSDN  	*((volatile uint8 *) (MCF_PWM_BASE + 0x24 + (n))
#define MCF_PWM_PCME    	*((volatile uint8 *) (MCF_PWM_BASE + 0x26)
*/


void pwm_clk_config(clk_src_t const clk_src, uint8 const p_prescale, uint8 const p_scale)
{
	/*switch(clk_src)
	{
		case clk_src_a:
			MCF_PWM_PWMCLK &= ~(1 << n);
			break;
		case clk_src_b:
			MCF_PWM_PWMCLK &= ~(1 << n);
			break;
		default:
			MCF_PWM_PWMCLK |= (1 << n);
			break;
	}*/
	if(p_prescale <= 7)
	{
		if(clk_src == clk_src_a || clk_src == clk_src_sa)
		{
			MCF_PWM_PWMPRCLK = p_prescale;
			if(clk_src == clk_src_sa)
			{
				MCF_PWM_PWMSCLA = p_scale;
				//MCF_PWM_PWMPER(0) |= 200;
			}
		}
		else
		{
			MCF_PWM_PWMPRCLK = (p_prescale << 4);
			if(clk_src == clk_src_sb)
			{
				MCF_PWM_PWMSCLB = p_scale;
				//MCF_PWM_PWMPER(0) |= 200;
			}
		}
	}
}

void pwm_chan_init(pwm_channel_t const n, clk_src_t const clk_src, pwm_aligned_t const align, pwm_polarity_t const polarity)
{
	pwm_chan_stop(n);
	//gpio_port_init(p_port_tc, p_pin_0, gpio_funct_tertiary, p_data_dir_x, p_state_x);
	//gpio_port_init(p_port_ta, p_pin_0, gpio_funct_tertiary, p_data_dir_x, p_state_x);
	//gpio_port_init(p_port_tc, p_pin_1, gpio_funct_tertiary, p_data_dir_x, p_state_x);
	//gpio_port_init(p_port_ta, p_pin_1, gpio_funct_tertiary, p_data_dir_x, p_state_x);
	//gpio_port_init(gpio_port_tc, gpio_pin_2, gpio_funct_tertiary, gpio_data_dir_x, gpio_pin_state_x);
	//gpio_port_init(gpio_port_ta, gpio_pin_2, gpio_funct_tertiary, gpio_data_dir_x, gpio_pin_state_x);
	//gpio_port_init(gpio_port_tc, gpio_pin_3, gpio_funct_tertiary, gpio_data_dir_x, gpio_pin_state_x);
	switch(n)
	{
		case pwm_channel_2:
			gpio_port_init(gpio_port_t1, gpio_pin_0, gpio_funct_tertiary, gpio_data_dir_x, gpio_pin_state_x);
			//uc_led_on((gpio_pin_t)uc_led_1);
		break;
		case pwm_channel_4:
			gpio_port_init(gpio_port_tc, gpio_pin_2, gpio_funct_tertiary, gpio_data_dir_x, gpio_pin_state_x);
			//uc_led_on((gpio_pin_t)uc_led_1);
			break;

		case pwm_channel_5:
			gpio_port_init(gpio_port_ta, gpio_pin_2, gpio_funct_tertiary, gpio_data_dir_x, gpio_pin_state_x);
			//uc_led_on((gpio_pin_t)uc_led_1);
			break;
		case pwm_channel_6:
			gpio_port_init(gpio_port_tc, gpio_pin_3, gpio_funct_tertiary, gpio_data_dir_x, gpio_pin_state_x);
			break;
	}

	//gpio_port_init(p_port_ta, p_pin_3, gpio_funct_tertiary, p_data_dir_x, p_state_x);
	switch(clk_src)
	{
		case clk_src_a:
			MCF_PWM_PWMCLK &= ~(1 << n);
			break;
		case clk_src_b:
			MCF_PWM_PWMCLK &= ~(1 << n);
			break;
		default:
			MCF_PWM_PWMCLK |= (1 << n);
			break;
	}
	if (align == left_aligned)
	{
		MCF_PWM_PWMCAE &= ~(align << n);
	}
	else
	{
		MCF_PWM_PWMCAE |= (align << n);
	}
	MCF_PWM_PWMPOL |= (polarity << n);
	MCF_PWM_PWME |= (1 << n);
}

void pwm_chan_start(pwm_channel_t const n, uint8 const period, uint8 const duty)
{
	pwm_chan_stop(n);
	//MCF_PWM_PWMPOL |= ((uint8)polarity << n);
	MCF_PWM_PWMPER(n) = period;
	MCF_PWM_PWMDTY(n) = duty;
	MCF_PWM_PWMCNT(n) = 0;
	MCF_PWM_PWME |= (1 << n);
}

void pwm_chan_stop(pwm_channel_t const n)
{
	MCF_PWM_PWME &= ~(1 << n);

}

