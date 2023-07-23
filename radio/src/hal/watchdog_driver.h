/*
 * Copyright (C) EdgeTX
 *
 * Based on code named
 *   opentx - https://github.com/opentx/opentx
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#pragma once

#include <stdint.h>

#define WDG_DURATION  500 /*ms*/

enum PowerResetReason {
  PRR_Default = 0,
  PRR_Watchdog = 1,
  PRR_Software = 2,
};

// Initializes IWDG with a duration in milliseconds
void watchdogInit(unsigned int duration);

// Resets IWDG timer
void watchdogReset();

// Returns 0 or 1 depending on whether or not
// a watchdog reset has been detected
uint32_t watchdogIsWDGReset();

#if defined(USE_WATCHDOG)
  #define WDG_ENABLE(x) watchdogInit(x)
  #define WDG_RESET()   watchdogReset()
#else
  #define WDG_ENABLE(x)
  #define WDG_RESET()
#endif
