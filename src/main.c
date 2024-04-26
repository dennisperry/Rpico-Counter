/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <hardware/timer.h>

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(main, 3);

#define SLEEP_TIME_MS   1000

void pause_timer(int pause)
{
	timer_hw->pause = pause;
}

void zero_timer(void)
{
	timer_hw->timehw = 0;
	timer_hw->timelw = 0;
}

int main(void)
{
	LOG_INF("main: starting...");
	uint64_t mytime;

	pause_timer(true);
	zero_timer();
	pause_timer(false);

	while (1) {
		mytime = time_us_64();
		LOG_INF("value of mytime = %lld", mytime);
		k_msleep(1000);
	}
	return 0;
}
