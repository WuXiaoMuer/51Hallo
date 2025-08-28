#include <STC89C5xRC.H>
#include "timer.h"
#include "buzzer.h"

static unsigned char s_on = 0;
static unsigned long s_next_toggle_ms = 0;

// software square wave on P25, default ~2kHz (toggle every 0.25ms -> too fast),
// choose moderate audible tone ~1kHz: toggle every 0.5ms. But with millis() granularity 1ms,
// we'll use 2ms toggle -> ~250Hz. Adjust as needed.
static unsigned int s_toggle_interval_ms = 2; // 2ms -> ~250Hz

void buzzer_set(unsigned char on)
{
	s_on = on ? 1 : 0;
	if(!s_on){ P25 = 0; }
	else { s_next_toggle_ms = millis(); }
}

void buzzer_toggle(void)
{
	buzzer_set(!s_on);
}

void buzzer_update(void)
{
	unsigned long now;
	if(!s_on) return;
	now = millis();
	if((long)(now - s_next_toggle_ms) >= 0){
		P25 = !P25;
		s_next_toggle_ms = now + s_toggle_interval_ms;
	}
}


