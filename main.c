#include <stdint.h>

// Register addresses for RCC and GPIOA 
#define RCC_AHB1ENR (*((volatile uint32_t*) 0x40023830))
#define GPIOA_MODER (*((volatile  uint32_t*)0x40020000))
#define GPIOA_ODR   (*((volatile uint32_t*)0x40020014))


void delay(uint32_t count);
int main(void)
{
  //Enable clock for GPIOA 
  RCC_AHB1ENR |= (1 << 0) ; // GPIOAEN
  
  
  //configure GPIOA pin 5 as output
  GPIOA_MODER |= (1<<10) ; //set as output
  // //configure GPIOA pin 10 as output
    GPIOA_MODER |= (1<<20) ; //set as output 
    
    while(1)
    {
      //Toggle LED (GPIOA pin 5)
      GPIOA_ODR ^= (1<<5);
      GPIOA_ODR ^= (1<<10);
      delay(500000); //add a delay 
    }
}
void delay(uint32_t count) {
  while (count--);
}
