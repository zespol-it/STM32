#ifndef __TONOMETR_H
#define __TONOMETR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"
#include <stdbool.h>

// Definicje pinów
#define DISPLAY_SCL_PIN GPIO_PIN_10
#define DISPLAY_SDA_PIN GPIO_PIN_11
#define DISPLAY_PORT GPIOB
#define PRESSURE_SENSOR_PIN GPIO_PIN_12
#define PRESSURE_SENSOR_PORT GPIOC
#define BUTTON_PIN GPIO_PIN_13
#define BUTTON_PORT GPIOC

// Struktury danych
typedef struct {
    float pressure;
    uint32_t timestamp;
    bool valid;
} PressureMeasurement_t;

typedef struct {
    uint8_t calibration_value;
    float offset;
    float scale;
} CalibrationData_t;

// Funkcje
void Tonometr_Init(void);
void Tonometr_Display_Init(void);
void Tonometr_Sensor_Init(void);
void Tonometr_Button_Init(void);
void Tonometr_Run_Measurement(void);
void Tonometr_Process_Results(void);
void Tonometr_Save_Data(void);
void Tonometr_Display_Results(void);

// Funkcje pomocnicze
void Tonometr_Calibrate(void);
void Tonometr_Read_Pressure(PressureMeasurement_t* measurement);
void Tonometr_Handle_Button(void);
void Tonometr_Update_Display(void);

#ifdef __cplusplus
}
#endif

#endif /* __TONOMETR_H */ 