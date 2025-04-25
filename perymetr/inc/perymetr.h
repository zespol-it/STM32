#ifndef __PERYMETR_H
#define __PERYMETR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"
#include <stdbool.h>

// Definicje pinów
#define DISPLAY_SCL_PIN GPIO_PIN_10
#define DISPLAY_SDA_PIN GPIO_PIN_11
#define DISPLAY_PORT GPIOB
#define EYE_SENSOR_PIN GPIO_PIN_12
#define EYE_SENSOR_PORT GPIOC
#define BUTTON_PIN GPIO_PIN_13
#define BUTTON_PORT GPIOC

// Struktury danych
typedef struct {
    uint8_t x;
    uint8_t y;
    bool detected;
} EyePosition_t;

typedef struct {
    uint8_t pattern[8][8];
    uint8_t brightness;
    uint8_t speed;
} TestPattern_t;

// Funkcje
void Perymetr_Init(void);
void Perymetr_Display_Init(void);
void Perymetr_Sensor_Init(void);
void Perymetr_Button_Init(void);
void Perymetr_Run_Test(void);
void Perymetr_Process_Results(void);
void Perymetr_Save_Data(void);
void Perymetr_Display_Results(void);

// Funkcje pomocnicze
void Perymetr_Generate_Pattern(TestPattern_t* pattern);
void Perymetr_Detect_Eye(EyePosition_t* position);
void Perymetr_Handle_Button(void);
void Perymetr_Update_Display(void);

#ifdef __cplusplus
}
#endif

#endif /* __PERYMETR_H */ 