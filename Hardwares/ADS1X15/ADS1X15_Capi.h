//
// Created by yekai on 2021/7/23.
//

#ifndef WINDBOARDCONTROLLER_ADS1X15_CAPI_H
#define WINDBOARDCONTROLLER_ADS1X15_CAPI_H

#ifdef __cplusplus
extern "C" {
#endif

void ADS1X15_Init();

int16_t ADS1X15_GetVoltage();

#ifdef __cplusplus
}
#endif

#endif //WINDBOARDCONTROLLER_ADS1X15_CAPI_H
