//
// Created by yekai on 2021/7/23.
//

#ifndef WINDBOARDCONTROLLER_PID_H
#define WINDBOARDCONTROLLER_PID_H

#include "main.h"

typedef struct {
    float kp;
    float ki;
    float kd;
    float set;
    float input;
    float err;
    float err_prev;
    float err_sum;
    float output;
} PID_TypeDef;

float ConvADCValueToAngle(uint16_t adcValue);

void PID_Init(PID_TypeDef *pid, float kp, float ki, float kd);

void PID_SetAngle(PID_TypeDef *pid, float angle);

void PID_Calculate(PID_TypeDef *pid, uint16_t inputADC);

extern PID_TypeDef l_motor_pid;
extern PID_TypeDef r_motor_pid;

#endif //WINDBOARDCONTROLLER_PID_H
