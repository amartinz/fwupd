/*
 * Copyright (C) 2021 Ricardo Cañuelo <ricardo.canuelo@collabora.com>
 *
 * SPDX-License-Identifier: LGPL-2.1+
 */

#include "config.h"

#include <fwupdplugin.h>

#include "fu-genesys-scaler-firmware.h"
#include "fu-genesys-usbhub-device.h"
#include "fu-genesys-usbhub-firmware.h"

static void
fu_plugin_genesys_init(FuPlugin *plugin)
{
	FuContext *ctx = fu_plugin_get_context(plugin);
	fu_context_add_quirk_key(ctx, "GenesysScalerGpioOutputRegister");
	fu_context_add_quirk_key(ctx, "GenesysScalerGpioEnableRegister");
	fu_context_add_quirk_key(ctx, "GenesysScalerGpioValue");
	fu_plugin_add_device_gtype(plugin, FU_TYPE_GENESYS_USBHUB_DEVICE);
	fu_plugin_add_firmware_gtype(plugin, NULL, FU_TYPE_GENESYS_USBHUB_FIRMWARE);
	fu_plugin_add_firmware_gtype(plugin, NULL, FU_TYPE_GENESYS_SCALER_FIRMWARE);
}

void
fu_plugin_init_vfuncs(FuPluginVfuncs *vfuncs)
{
	vfuncs->build_hash = FU_BUILD_HASH;
	vfuncs->init = fu_plugin_genesys_init;
}