#include "stm32f4xx.h"                  // Device header

void timer2_config(void);
void timer2_delay_ms(int time_delay);

void led_config(void);
void led_output(int pin_val);

int main(){
	int ledState=0;
	led_config();
	timer2_config();
	
	while(1){
		led_output(ledState);
		timer2_delay_ms(500);
		ledState=(ledState==0)?1:0;
	}
}

void timer2_config(void){
	RCC->APB1ENR|=(0x1);//Enable TIM2
	
}



void timer2_delay_ms(int delay_time){
	int i;
	for(i=0;i<(delay_time*0xFFF);i++){
	}
}

void led_config(void){
	RCC->AHB1ENR|=(0x1);//Enable GPIOA
	GPIOA->MODER|=(0x1<<10);// Pin_A5 as general purpose output
}

void led_output(int pin_val){
	if(pin_val==0){
		GPIOA->BSRRH=(0x1<<5);// reset Pin_A5
	}else{
		GPIOA->BSRRL=(0x1<<5);// set Pin_A5
	}
}


