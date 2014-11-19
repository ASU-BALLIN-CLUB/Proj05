//
//  oct_spkr.c
//
//	Proj05
//  Lab Partners: Sean Slamka, Aydin Balci
//  Email: sslamka@asu.edu, abalci@asu.edu
//  CSE325 Embedded Microprocessor Systems
//  Fall 2014
//

#include "oct_spkr.h"

oct_pwm_init(pwm_channel_t const channel, clk_src_t const clk_source, pwm_aligned_t const alignment, pwm_polarity_t const pol)
{
	pwm_chan_init(channel, clk_source, alignment, pol);
}//void pwm_chan_init(pwm_channel_t const n, clk_src_t const clk_src, pwm_aligned_t const align, pwm_polarity_t const polarity)

void oct_sound_start(pwm_channel_t const channel, uint8 const per, uint8 const duty)
{
	pwm_chan_start(channel, per, duty);
	//pwm_channel_t const n, uint8 const period, uint8 const duty
}

void oct_sound_stop(pwm_channel_t const n)
{
	pwm_chan_stop(n);
}

