/*
   Copyright (c) 2016, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_apq8084.h"

void gsm_properties()
{
    property_set("telephony.lteOnGsmDevice", "1");
    property_set("ro.telephony.default_network", "9");
}

void cdma_properties()
{
    property_set("ro.cdma.home.operator.alpha", "中国电信");
    property_set("ro.cdma.home.operator.numeric", "46003");
    property_set("ro.telephony.default_cdma_sub", "0");
    property_set("ril.subscription.types", "NV,RUIM");
    property_set("ro.telephony.default_network", "10");
    property_set("telephony.lteOnCdmaDevice", "1");
}

void init_target_properties()
{
    std::string platform = property_get("ro.board.platform");
    if (platform != ANDROID_TARGET)
        return;

    std::string bootloader = property_get("ro.bootloader");

    if (bootloader.find("N9100ZC") == 0) {
        property_override("ro.build.fingerprint", "samsung/trlteduoszc/trltechn:6.0.1/MMB29M/N9100ZCS1DQH1:user/release-keys");
        property_override("ro.build.description", "trlteduoszc-user 6.0.1 MMB29M N9100ZCS1DQH1 release-keys");
        property_override("ro.product.model", "SM-N9100");
        property_override("ro.product.device", "trltechn");
        property_override("ro.product.name", "trlteduoszc");
        gsm_properties();
    } else if (bootloader.find("N9100ZH") == 0) {
        property_override("ro.build.fingerprint", "samsung/trlteduoszh/trltechnzh:6.0.1/MMB29M/N9100ZHU1DQG1:user/release-keys");
        property_override("ro.build.description", "trlteduoszh-user 6.0.1 MMB29M N9100ZHU1DQG1 release-keys");
        property_override("ro.product.model", "SM-N9100");
        property_override("ro.product.device", "trltechnzh");
        property_override("ro.product.name", "trlteduoszh");
        gsm_properties();
    } else if (bootloader.find("N9106W") == 0) {
        property_override("ro.build.fingerprint", "samsung/trlteduoszn/trltechn:6.0.1/MMB29M/N9106WZNU1DQB1:user/release-keys");
        property_override("ro.build.description", "trlteduoszn-user 6.0.1 MMB29M N9106WZNU1DQB1 release-keys");
        property_override("ro.product.model", "SM-N9106W");
        property_override("ro.product.device", "trltechn");
        property_override("ro.product.name", "trlteduoszn");
        gsm_properties();
    } else if (bootloader.find("N9109W") == 0) {
        property_override("ro.build.fingerprint", "samsung/trlteduosctc/trltechn:6.0.1/MMB29M/N9109WKEU1DQD1:user/release-keys");
        property_override("ro.build.description", "trlteduosctc-user 6.0.1 MMB29M N9109WKEU1DQD1 release-keys");
        property_override("ro.product.model", "SM-N9109W");
        property_override("ro.product.device", "trltechn");
        property_override("ro.product.name", "trlteduosctc");
        property_override("rild.libpath", "/system/lib/libsec-ril-09w.so");
        cdma_properties();
    } else {
        ERROR("Setting product info FAILED\n");
    }

    std::string device = property_get("ro.product.device");
    INFO("Found bootloader id %s setting build properties for %s device\n", bootloader.c_str(), device.c_str());
}
