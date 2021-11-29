/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int timer0_counter=0;
int timer0_flag=0;
int timer1_counter=0;
int timer1_flag=0;
int timer2_counter=0;
int timer2_flag=0;
int timer3_counter=0;
int timer3_flag=0;
int timer4_counter=0;
int timer4_flag=0;
int TIMER_CYCLE=10;
void setTimer0(int duration){
	timer0_counter=duration/TIMER_CYCLE;
	timer0_flag=0;
}
void setTimer1(int duration){
	timer1_counter=duration/TIMER_CYCLE;
	timer1_flag=0;
}
void setTimer2(int duration){
	timer2_counter=duration/TIMER_CYCLE;
	timer2_flag=0;
}
void setTimer3(int duration){
	timer3_counter=duration/TIMER_CYCLE;
	timer3_flag=0;
}
void setTimer4(int duration){
	timer4_counter=duration/TIMER_CYCLE;
	timer4_flag=0;
}
void timer_run(){
	if(timer0_counter>0){
		timer0_counter--;
		if(timer0_counter==0) timer0_flag=1;
	}
	if(timer1_counter>0){
		timer1_counter--;
		if(timer1_counter==0) timer1_flag=1;
	}
	if(timer2_counter>0){
		timer2_counter--;
		if(timer2_counter==0) timer2_flag=1;
	}
	if(timer3_counter>0){
		timer3_counter--;
		if(timer3_counter==0) timer3_flag=1;
	}
	if(timer4_counter>0){
		timer4_counter--;
		if(timer4_counter==0) timer4_flag=1;
	}
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
void display7led(int num){
	switch (num){
	case 0:
		HAL_GPIO_WritePin(GPIOB, led7_0_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_1_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_2_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_3_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_4_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_5_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_6_Pin ,GPIO_PIN_SET);
		break;

	case 1:
		HAL_GPIO_WritePin(GPIOB, led7_0_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, led7_1_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_2_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_3_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, led7_4_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, led7_5_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, led7_6_Pin ,GPIO_PIN_SET);
		break;

	case 2:
		HAL_GPIO_WritePin(GPIOB, led7_0_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_1_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_2_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, led7_3_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_4_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_5_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, led7_6_Pin ,GPIO_PIN_RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, led7_0_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_1_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_2_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_3_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_4_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, led7_5_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, led7_6_Pin ,GPIO_PIN_RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, led7_0_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, led7_1_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_2_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_3_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, led7_4_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, led7_5_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_6_Pin ,GPIO_PIN_RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, led7_0_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_1_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, led7_2_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_3_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_4_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, led7_5_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_6_Pin ,GPIO_PIN_RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, led7_0_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_1_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, led7_2_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_3_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_4_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_5_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_6_Pin ,GPIO_PIN_RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, led7_0_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_1_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_2_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_3_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, led7_4_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, led7_5_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, led7_6_Pin ,GPIO_PIN_SET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOB, led7_0_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_1_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_2_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_3_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_4_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_5_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_6_Pin ,GPIO_PIN_RESET);
			break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, led7_0_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_1_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_2_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_3_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_4_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, led7_5_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_6_Pin ,GPIO_PIN_RESET);
			break;
	default:
		HAL_GPIO_WritePin(GPIOB, led7_0_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_1_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_2_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_3_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_4_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, led7_5_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, led7_6_Pin ,GPIO_PIN_RESET);
	}
}
const int MAX_LED = 4;
int index_led = 0;
int led7_buffer[4] = {1, 2, 3, 4};

void update7led(int index){
	switch (index){
	case 0:
		HAL_GPIO_WritePin(GPIOA, LED_EN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_EN3_Pin, GPIO_PIN_SET);
		display7led(led7_buffer[index_led]);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOA, LED_EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_EN1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_EN3_Pin, GPIO_PIN_SET);
		display7led(led7_buffer[index_led]);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, LED_EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_EN2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_EN3_Pin, GPIO_PIN_SET);
		display7led(led7_buffer[index_led]);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOA, LED_EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_EN3_Pin, GPIO_PIN_RESET);
		display7led(led7_buffer[index_led]);
		break;
	}
}
int hour = 15, minute = 8, second = 50;

void updateClockBuffer(){
	if(hour<10){
		led7_buffer[0]=0;
		led7_buffer[1]=hour;
	}
	else{
		led7_buffer[0]=(int)(hour/10);
		led7_buffer[1]=hour-led7_buffer[0]*10;
	}
	if(minute<10){
		led7_buffer[2]=0;
		led7_buffer[3]=minute;
	}
	else{
		led7_buffer[2]=(int)(minute/10);
		led7_buffer[3]=minute-led7_buffer[2]*10;
	}
}
const int MAX_LED_MATRIX = 8;
int index_led7_matrix = 0;
uint8_t matrix_buffer[8] = {0xFF, 0x80, 0x80, 0x67, 0x67, 0x80, 0x80, 0xFF};

void LedMatrix(int index){
	HAL_GPIO_WritePin(GPIOB, ROW0_Pin, (matrix_buffer[index]>>7)&1);
	HAL_GPIO_WritePin(GPIOB, ROW1_Pin, (matrix_buffer[index]>>6)&1);
	HAL_GPIO_WritePin(GPIOB, ROW2_Pin, (matrix_buffer[index]>>5)&1);
	HAL_GPIO_WritePin(GPIOB, ROW3_Pin, (matrix_buffer[index]>>4)&1);
	HAL_GPIO_WritePin(GPIOB, ROW4_Pin, (matrix_buffer[index]>>3)&1);
	HAL_GPIO_WritePin(GPIOB, ROW5_Pin, (matrix_buffer[index]>>2)&1);
	HAL_GPIO_WritePin(GPIOB, ROW6_Pin, (matrix_buffer[index]>>1)&1);
	HAL_GPIO_WritePin(GPIOB, ROW7_Pin, (matrix_buffer[index]>>0)&1);
}

void updateLEDMatrix(int index){
    switch (index){
        case 0:
        	HAL_GPIO_WritePin(GPIOA, ENM0_Pin, GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(GPIOA, ENM1_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM2_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM3_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM4_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM5_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM6_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM7_Pin, GPIO_PIN_SET);
        	LedMatrix(index);
            break;
        case 1:
        	HAL_GPIO_WritePin(GPIOA, ENM0_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM1_Pin, GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(GPIOA, ENM2_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM3_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM4_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM5_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM6_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM7_Pin, GPIO_PIN_SET);
        	LedMatrix(index);
            break;
        case 2:
        	HAL_GPIO_WritePin(GPIOA, ENM0_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM1_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM2_Pin, GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(GPIOA, ENM3_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM4_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM5_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM6_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM7_Pin, GPIO_PIN_SET);
        	LedMatrix(index);
            break;
        case 3:
        	HAL_GPIO_WritePin(GPIOA, ENM0_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM1_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM2_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM3_Pin, GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(GPIOA, ENM4_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM5_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM6_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM7_Pin, GPIO_PIN_SET);
        	LedMatrix(index);
            break;
        case 4:
        	HAL_GPIO_WritePin(GPIOA, ENM0_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM1_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM2_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM3_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM4_Pin, GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(GPIOA, ENM5_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM6_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM7_Pin, GPIO_PIN_SET);
        	LedMatrix(index);
            break;
        case 5:
        	HAL_GPIO_WritePin(GPIOA, ENM0_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM1_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM2_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM3_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM4_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM5_Pin, GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(GPIOA, ENM6_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM7_Pin, GPIO_PIN_SET);
        	LedMatrix(index);
            break;
        case 6:
        	HAL_GPIO_WritePin(GPIOA, ENM0_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM1_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM2_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM3_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM4_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM5_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM6_Pin, GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(GPIOA, ENM7_Pin, GPIO_PIN_SET);
        	LedMatrix(index);
            break;
        case 7:
        	HAL_GPIO_WritePin(GPIOA, ENM0_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM1_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM2_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM3_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM4_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM5_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM6_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(GPIOA, ENM7_Pin, GPIO_PIN_RESET);
        	LedMatrix(index);
            break;
        default:
            break;
    }
}
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
setTimer0(1000);
int status_time=0;
int counter_time=1000;
int DOT=0;
int counter_DOT=1000;
int status_7led=0;
int counter_7led=250;
int status_matrix=0;
int counter_matrix=10;
while (1){
    /* USER CODE END WHILE */
	if(timer0_flag==1){
		HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
		setTimer0(2000);
	}

	switch(DOT){
	case 0:
		setTimer2(counter_DOT);
		DOT=1;
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOA, DOT_Pin, GPIO_PIN_RESET);
		if(timer2_flag==1){
			setTimer2(counter_DOT);
			DOT=2;
		}
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, DOT_Pin, GPIO_PIN_SET);
		if(timer2_flag==1){
			setTimer2(counter_DOT);
			DOT=1;
		}
		break;
	}

	switch (status_7led){
	case 0:
		setTimer3(counter_7led);
		status_7led=1;
		break;
	case 1:
		update7led(index_led);
		if(timer3_flag==1){
			status_7led=2;
			index_led++;
			setTimer3(counter_7led);
		}
		break;
	case 2:
		update7led(index_led);
		if(timer3_flag==1){
			status_7led=3;
			index_led++;
			setTimer3(counter_7led);
		}
		break;
	case 3:
		update7led(index_led);
		if(timer3_flag==1){
			status_7led=4;
			index_led++;
			setTimer3(counter_7led);
		}
		break;
	case 4:
		update7led(index_led);
		if(timer3_flag==1){
			status_7led=1;
			index_led++;
			setTimer3(counter_7led);
		}
		break;
	}
	if(index_led>=MAX_LED) index_led=0;

	switch (status_time){
	case 0:
		second++;
		setTimer1(counter_time);
		status_time=1;
		break;
	case 1:
		if(timer1_flag==1){
			if(second>=10){second=0;minute=minute+1;}
			if(minute>=10){minute=0;hour++;}
			if(hour>=24) hour=0;
		status_time=0;
	   }
	}
	updateClockBuffer();

	/*switch(status_matrix){
		case 0:
			setTimer4(counter_matrix);
			status_matrix=1;
			break;
		case 1:
			updateLEDMatrix(index_led7_matrix++);
			if(timer4_flag==1){
				status_matrix=0;
			}
			break;
		}
		if(index_led7_matrix>=MAX_LED_MATRIX) index_led7_matrix=0;*/



    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|DOT_Pin|LED_RED_Pin
                          |LED_EN0_Pin|LED_EN1_Pin|LED_EN2_Pin|LED_EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, led7_0_Pin|led7_1_Pin|led7_2_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|led7_3_Pin|led7_4_Pin|led7_5_Pin
                          |led7_6_Pin|ROW0_Pin|ROW1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : ENM0_Pin ENM1_Pin DOT_Pin LED_Pin
                           LED_EN0_Pin LED_EN1_Pin LED_EN2_Pin LED_EN3_Pin
                           ENM2_Pin ENM3_Pin ENM4_Pin ENM5_Pin
                           ENM6_Pin ENM7_Pin */
  GPIO_InitStruct.Pin = ENM0_Pin|ENM1_Pin|DOT_Pin|LED_RED_Pin
                          |LED_EN0_Pin|LED_EN1_Pin|LED_EN2_Pin|LED_EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : led7_0_Pin led7_1_Pin led7_2_Pin ROW2_Pin
                           ROW3_Pin ROW4_Pin ROW5_Pin ROW6_Pin
                           ROW7_Pin led7_3_Pin led7_4_Pin led7_5_Pin
                           led7_6_Pin ROW0_Pin ROW1_Pin */
  GPIO_InitStruct.Pin = led7_0_Pin|led7_1_Pin|led7_2_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|led7_3_Pin|led7_4_Pin|led7_5_Pin
                          |led7_6_Pin|ROW0_Pin|ROW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
//int counter=100;
//int counter_7led=100;
//int counter_DOT=100;
//int status_7led=0;
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim ){
//	counter--;
//	counter_7led--;
//	counter_DOT--;
//	if(counter<=0){
//		counter=100;
//		HAL_GPIO_TogglePin(GPIOA, LED_Pin);
//	}
//	if(counter_DOT<=0){
//		counter_DOT=100;
//		HAL_GPIO_TogglePin(GPIOA, DOT_Pin);
//	}
	timer_run();
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
