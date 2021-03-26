/*
 * Copyright (c) 2020 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <zephyr.h>
#include <logging/log.h>

#if defined(CONFIG_SOC_NRF52840)
#include <usb/usb_device.h>
#endif

#if CONFIG_BT
#include "ble.h"
#endif

LOG_MODULE_REGISTER(cli_sample, CONFIG_OT_COMMAND_LINE_INTERFACE_LOG_LEVEL);

#define WELLCOME_TEXT \
	"\n\r"\
	"\n\r"\
	"OpenThread Command Line Interface is now running.\n\r" \
	"Use the 'ot' keyword to invoke OpenThread commands e.g. " \
	"'ot thread start.'\n\r" \
	"For the full commands list refer to the OpenThread CLI " \
	"documentation at:\n\r" \
	"https://github.com/openthread/openthread/blob/master/src/cli/README.md\n\r"

void main(void)
{
#if defined(CONFIG_SOC_NRF52840)
	while (usb_enable(NULL)) {
      // retry if failed
      k_sleep(K_SECONDS(1));
	}
#endif

	LOG_INF(WELLCOME_TEXT);

#if CONFIG_BT
	ble_enable();
#endif
}
