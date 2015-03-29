/*simple led blinking program
 * user:Raghav Sonavane
 */
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
void Delay(__IO uint32_t nCount)           //IO=>volatile variable
{
  while(nCount--)
  {
  }
}
GPIO_InitTypeDef  GPIO_InitStruct; //structure defined in header file
                                   //should be included before configuring pins
int main(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);         //   Enable the GPIO AHB clock using the following
	                                                              //RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOx, ENABLE);
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_15;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	 GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	 GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	 GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	 GPIO_Init( GPIOD,&GPIO_InitStruct );
      while(1)
                {
    	  GPIO_SetBits(GPIOD,GPIO_Pin_15);
    	      Delay(0xFFFFF);
    	      GPIO_ResetBits(GPIOD,GPIO_Pin_15);
                }
}
