//
// Created by yekai on 2021/7/23.
//

#include "pid.h"
#include "stdio.h"

PID_TypeDef l_motor_pid;
PID_TypeDef r_motor_pid;

float ConvADCValueToAngle(uint16_t adcValue) {
    return 0.103 * adcValue - 27.37;
}

void PID_Init(PID_TypeDef *pid, float kp, float ki, float kd) {
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;
    pid->err = 0;
    pid->err_prev = 0;
    pid->err_sum = 0;
    pid->output = 0;
    pid->set = 0;
    pid->input = 0;
}

const uint16_t err_sum_max = 1000;
const uint16_t err_min = 5;

void PID_Calculate(PID_TypeDef *pid, uint16_t inputADC) {
    pid->input = ConvADCValueToAngle(inputADC);
    printf("angle:%d\n", (int) (pid->input));
    pid->err = pid->input - pid->set;
//    printf("err:%d\n", (int) (pid->err));
    if ((pid->err < err_min) && (pid->err > err_min)) {
        pid->err = 0;
    }
    pid->err_sum = pid->err_sum + pid->err;
    if (pid->err_sum > err_sum_max) {
        pid->err_sum = err_sum_max;
    }
    if (pid->err_sum < -err_sum_max) {
        pid->err_sum = -err_sum_max;
    }
    pid->output = pid->kp * pid->err +
                  pid->ki * pid->err_sum +
                  pid->kd * (pid->err - pid->err_prev);
    pid->err_prev = pid->err;
}

void PID_SetAngle(PID_TypeDef *pid, float angle) {
    pid->set = angle;
}


