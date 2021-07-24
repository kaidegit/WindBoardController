//
// Created by yekai on 2021/7/23.
//

#include "CorelessMotor.h"
#include "gpio.h"
#include "tim.h"

const uint16_t SPEED_MAX = 2100;
const uint16_t SPEED_MIN = 600;

void LMotor_SetSpeed(int16_t speed) {
    if (speed > SPEED_MAX){
        speed = SPEED_MAX;
    }
    if (speed < SPEED_MIN){
        speed = SPEED_MIN;
    }

    if (speed > 0) {
        HAL_GPIO_WritePin(L_MOTOR_IN1_GPIO_Port, L_MOTOR_IN1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(L_MOTOR_IN2_GPIO_Port, L_MOTOR_IN2_Pin, GPIO_PIN_RESET);
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, speed);
    } else {
        HAL_GPIO_WritePin(L_MOTOR_IN1_GPIO_Port, L_MOTOR_IN1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(L_MOTOR_IN2_GPIO_Port, L_MOTOR_IN2_Pin, GPIO_PIN_SET);
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, -speed);
    }
}

void RMotor_SetSpeed(int16_t speed) {
    if (speed > SPEED_MAX){
        speed = SPEED_MAX;
    }
    if (speed < SPEED_MIN){
        speed = SPEED_MIN;
    }
    if (speed > 0) {
        HAL_GPIO_WritePin(R_MOTOR_IN1_GPIO_Port, R_MOTOR_IN1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(R_MOTOR_IN2_GPIO_Port, R_MOTOR_IN2_Pin, GPIO_PIN_RESET);
        __HAL_TIM_SET_COMPARE(&htim10, TIM_CHANNEL_1, speed);
    } else {
        HAL_GPIO_WritePin(R_MOTOR_IN1_GPIO_Port, R_MOTOR_IN1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(R_MOTOR_IN2_GPIO_Port, R_MOTOR_IN2_Pin, GPIO_PIN_SET);
        __HAL_TIM_SET_COMPARE(&htim10, TIM_CHANNEL_1, -speed);
    }
}

void Motor_SetSpeed(int16_t speed) {
    if (speed < 0) {
        RMotor_SetSpeed(600-speed);
        LMotor_SetSpeed(600);
    } else if (speed == 0) {
        RMotor_SetSpeed(600);
        LMotor_SetSpeed(600);
    } else {
        LMotor_SetSpeed(600+speed);
        RMotor_SetSpeed(600);
    }
}
