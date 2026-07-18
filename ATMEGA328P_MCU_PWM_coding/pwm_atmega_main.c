/*
 * firstATmega-328P_coding.c
 *
 * Created: 6.07.2026 11:45:13
 * Author : zkdem
 */ 
#include <avr/io.h>
#include <util/delay.h>   // _delay_ms() 

int main(void)
{
    // PD3 (OC2B) pin output
    DDRD |= (1 << PD3);
	
	// PB0 output for BatteryLED light
	DDRB |= (1 << PB0);
	
	// PC0 (ADC0) pin input
	DDRC &= ~(1 << PC0);

	// Multiplexer selection for ADC (REFS0: choosing the AVREF for MCU supply such as 3.3V - 5V)
	ADMUX |= (1 << REFS0);						// If MCU 3.3V, ADC 0 = 0 ______ ADC 1023 = 3.3V
									            // Formula for analog value: adcValue* (VIN/VREF)
												
	// Enable ADC (ADEN), division factor is 128 that best option (ADPS2, ADPS1, ADPS0 those should be set.)
	ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);	

    // Timer2 Fast PWM mode
    TCCR2A = (1 << COM2B1) | (1 << WGM21) | (1 << WGM20);

    // prescaler = 64
    TCCR2B = (1 << CS22);

    // Duty Cycle = %50 because 8-bit resolution 0-256. 128 : %50_____64 : %25_____192 : %75
    OCR2B = 128;
	
    while (1) 
    {
		// Starting to convertion mode
		ADCSRA |= (1 << ADSC);
		
		// Waiting for to finish the convertion
		while(ADCSRA & (1 << ADSC));
		
		// Read ADC value
		uint16_t adcValue = ADC;		
	
		// Conversion to Analog Value for 12V battery
		double Value = adcValue * (12 / 1023);			// e.g. if adcValue is 852, Value is approximately 10. 
		
		// Let's if battery is under the 10V, it opens the light.
		if (Value < 10) 
		{
			// Open LED on PB0
			PORTB |= (1 << PB0);
			_delay_ms(1000);
			
			// Close LED on PB0
			PORTB &= ~(1 << PB0); 
			_delay_ms(1000);
		}
    }
}



