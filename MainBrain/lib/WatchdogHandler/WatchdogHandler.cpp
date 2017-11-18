/**  A one line description of the class.
 *
 * WatchdogHandler.cpp
 * Created 11-06-17 By: Smitty
 *
 * A longer description.
 */

#include "WatchdogHandler.hpp"

static void one_bus_cycle(void) __attribute__((always_inline));
static void watchdog_config(int cfg, int val);

// Enable the watchdog timer to reset the machine after a period of time
// without any calls to reset().  The passed in period (in milliseconds) is
// just a suggestion and a lower value might be picked if the hardware does
// not support the exact desired value.
//
// The actual period (in milliseconds) before a watchdog timer reset is
// returned.
int WatchdogHandler::enable(int maxPeriodMS)
{
	if (maxPeriodMS < 4) {
		maxPeriodMS = 8000; // default is 8 seconds
	}
	if (setting != maxPeriodMS) {
		watchdog_config(WDOG_STCTRLH_WDOGEN, maxPeriodMS);
		setting = maxPeriodMS;
	}
	return maxPeriodMS;
}

// Reset or 'kick' the watchdog timer to prevent a reset of the device.
void WatchdogHandler::reset()
{
	__disable_irq();
	WDOG_REFRESH = 0xA602;
	WDOG_REFRESH = 0xB480;
	__enable_irq();
}

// Completely disable the watchdog timer.
void WatchdogHandler::disable()
{
	if (setting > 0) {
		watchdog_config(0, 4);
		setting = 0;
	}
}

static void watchdog_config(int cfg, int val)
{
	__disable_irq();
	WDOG_UNLOCK = WDOG_UNLOCK_SEQ1;
	WDOG_UNLOCK = WDOG_UNLOCK_SEQ2;
	one_bus_cycle();
	WDOG_STCTRLH = cfg | WDOG_STCTRLH_ALLOWUPDATE;
	WDOG_TOVALH = val >> 16;
	WDOG_TOVALL = val;
	WDOG_PRESC = 0;
	__enable_irq();
	for (int i=0; i < 256; i++) {
		one_bus_cycle();
	}
}

static void one_bus_cycle(void)
{
	__asm__ volatile ("nop");
	#if (F_CPU / F_BUS) > 1
	__asm__ volatile ("nop");
	#endif
	#if (F_CPU / F_BUS) > 2
	__asm__ volatile ("nop");
	#endif
	#if (F_CPU / F_BUS) > 3
	__asm__ volatile ("nop");
	#endif
	#if (F_CPU / F_BUS) > 4
	__asm__ volatile ("nop");
	#endif
	#if (F_CPU / F_BUS) > 5
	__asm__ volatile ("nop");
	#endif
	#if (F_CPU / F_BUS) > 6
	__asm__ volatile ("nop");
	#endif
	#if (F_CPU / F_BUS) > 7
	__asm__ volatile ("nop");
	#endif
}
