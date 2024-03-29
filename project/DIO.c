#include "DIO.h"

void DIO_Init (void){ 
     // Initialize GPIO Port A
     SYSCTL_RCGCGPIO_R |=0x01;
  while ((SYSCTL_PRGPIO_R & 0x01) ==0){};
  GPIO_PORTA_LOCK_R = 0x4C4F434B;
  GPIO_PORTA_CR_R |= 0xFF;  //1111 1111   r=>0x2 b=>0x4 g=>0x8
  GPIO_PORTA_DIR_R |= 0xCC; //1100 1100
  GPIO_PORTA_PUR_R = 0x33;  //0011 0011
  GPIO_PORTA_DEN_R |= 0xFF;
    // Initialize GPIO Port B
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_6 | GPIO_PIN_7);
     SYSCTL_RCGCGPIO_R |=0x2;
  while ((SYSCTL_PRGPIO_R & 0x2) ==0){};
  GPIO_PORTB_LOCK_R = 0x4C4F434B;
  GPIO_PORTB_CR_R |= 0xC0;  //1100 0000   r=>0x2 b=>0x4 g=>0x8
  GPIO_PORTB_DIR_R |= 0x00; //0000 0000
  GPIO_PORTB_PUR_R = 0xC0;  //1100 0000
  GPIO_PORTB_DEN_R |= 0xC0;
    // Initialize GPIO Port C
     SYSCTL_RCGCGPIO_R |=0x4;
  while ((SYSCTL_PRGPIO_R & 0x4) ==0){};
 GPIO_PORTC_CR_R |= 0x30; 
  GPIO_PORTC_DIR_R = 0x0;
  GPIO_PORTC_PUR_R=0x30;
  GPIO_PORTC_DEN_R |= 0x30;    
	  // Initialize GPIO Port E
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    GPIOPinTypeGPIOInput(GPIO_PORTE_BASE, GPIO_PIN_1 | GPIO_PIN_2 );
     SYSCTL_RCGCGPIO_R |=0x10;
  while ((SYSCTL_PRGPIO_R & 0x10) ==0){};
  GPIO_PORTE_LOCK_R = 0x4C4F434B;
  GPIO_PORTE_CR_R |= 0x06;  //0000 0110   r=>0x2 b=>0x4 g=>0x8
  GPIO_PORTE_DIR_R |= 0x00; //0000 0000
  GPIO_PORTE_PUR_R = 0x06;  //0000 0110
  GPIO_PORTE_DEN_R |= 0x06;
    // Initialize GPIO Port F
     SYSCTL_RCGCGPIO_R |=0x20;
  while ((SYSCTL_PRGPIO_R & 0x20) ==0){};
  GPIO_PORTF_LOCK_R = 0x4C4F434B;
  GPIO_PORTF_CR_R |= 0x1F;  //0001 1111   r=>0x2 b=>0x4 g=>0x8
  GPIO_PORTF_DIR_R |= 0x0E; //0000 1110
  GPIO_PORTF_PUR_R = 0x11;  //0001 0001
  GPIO_PORTF_DEN_R |= 0x1F;

}

