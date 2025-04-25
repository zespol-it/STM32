#include "main.h"
#include "stm32f4xx_hal.h"
#include <string.h>

// Private variables
UART_HandleTypeDef huart2;
GPIO_InitTypeDef GPIO_InitStruct = {0};

// Private function prototypes
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
void Test_LED_Pattern(void);
void Test_UART_Communication(void);

int main(void)
{
    // Initialize HAL
    HAL_Init();
    
    // Configure system clock
    SystemClock_Config();
    
    // Initialize GPIO and UART
    MX_GPIO_Init();
    MX_USART2_UART_Init();
    
    // Send startup message
    const char* startup_msg = "STM32 Test Application Started\r\n";
    HAL_UART_Transmit(&huart2, (uint8_t*)startup_msg, strlen(startup_msg), 100);
    
    // Main loop
    while (1)
    {
        // Run LED test pattern
        Test_LED_Pattern();
        
        // Run UART communication test
        Test_UART_Communication();
        
        // Delay between test cycles
        HAL_Delay(2000);
    }
}

void Test_LED_Pattern(void)
{
    const char* test_msg = "Running LED Test Pattern...\r\n";
    HAL_UART_Transmit(&huart2, (uint8_t*)test_msg, strlen(test_msg), 100);
    
    // Blink LED 5 times
    for(int i = 0; i < 5; i++)
    {
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
        HAL_Delay(200);
    }
}

void Test_UART_Communication(void)
{
    const char* test_msg = "Testing UART Communication...\r\n";
    HAL_UART_Transmit(&huart2, (uint8_t*)test_msg, strlen(test_msg), 100);
    
    // Send test pattern
    const char* pattern = "UART Test Pattern: 1234567890\r\n";
    HAL_UART_Transmit(&huart2, (uint8_t*)pattern, strlen(pattern), 100);
}

void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    // Configure main internal regulator output voltage
    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    // Configure HSE as system clock source
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM = 8;
    RCC_OscInitStruct.PLL.PLLN = 336;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ = 7;
    HAL_RCC_OscConfig(&RCC_OscInitStruct);

    // Configure system clock
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | 
                                 RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
    HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);
}

static void MX_USART2_UART_Init(void)
{
    huart2.Instance = USART2;
    huart2.Init.BaudRate = 115200;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;
    HAL_UART_Init(&huart2);
}

static void MX_GPIO_Init(void)
{
    // Enable GPIO port clock
    __HAL_RCC_GPIOD_CLK_ENABLE();
    
    // Configure LED pin
    GPIO_InitStruct.Pin = GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line)
{
    while (1)
    {
    }
}
#endif 