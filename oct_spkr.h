//
//  oct_spkr.h
//
//	Proj05
//  Lab Partners: Sean Slamka, Aydin Balci
//  Email: sslamka@asu.edu, abalci@asu.edu
//  CSE325 Embedded Microprocessor Systems
//  Fall 2014
//

#ifndef ____oct_spkr__
#define ____oct_spkr__

#include"support_common.h"
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


void oct_pwm_init(pwm_channel_t const channel, clk_src_t const clk_source, pwm_aligned_t const alignment, pwm_polarity_t const pol);
void oct_sound_start(pwm_channel_t const channel, uint8 const per, uint8 const duty);
void oct_sound_stop(pwm_channel_t const n);



#endif
