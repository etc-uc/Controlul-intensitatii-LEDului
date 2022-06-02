/*
 * light.c
 *
 * Created: 02.06.2022 04:47:57
 * Author : Rares
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>


int main(void)

{
	DDRD = 0;
	DDRB = 0xFF;
	
	TCCR0A |=(1<<WGM00)|(1<<WGM01)|(1<<COM0A0)|(1<<COM0A1)|(1<<CS00);
	
	OCR0A = 0;
	
	while(1)
	{
		if (bit_is_clear(PIND,0))
		{
			if (OCR0A<255)
			{
				OCR0A++;
			}
			_delay_ms(50);
		}

		if (bit_is_clear(PIND,1))
		{
			if (OCR0A>0)
			{
				OCR0A--;
			}
			_delay_ms(50);
		}
	}
}