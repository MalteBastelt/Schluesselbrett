/*
 * Schlüsselbrett.c
 * Author : Malte Ollenschläger
 * Dieses Werk ist lizenziert unter einer Creative Commons Namensnennung - Nicht-kommerziell - Weitergabe unter gleichen Bedingungen 4.0 International Lizenz.
 */ 

#include <avr/io.h>
#include <avr/sleep.h>
#include <stdlib.h>

void initIO();
void initInterrupts();
void goodNight();

int main(void)
{
	int ledNumber = 0;
    while (1) 
    {
		//eine LED nach Zufallsmodus leuchten lassen
		ledNumber = rand(3);
		PORTX = (1<<ledNumber);//Eine LED einschalten
		_delay_ms(3000);//einige Sekunden eingeschaltet lassen
		PORTX = 0; //Alle LEDs aus
		goodNight();//Energie sparen
    }
}


initIO(){
	//Aus- und Eingänge setzen
}

initInterrupts(){
	//vier Interrupts erlauben, steigend und fallend
}

ISR(){
	//main anstoßen
}

void goodNight(){
	DDRC = 0;
	PORTC = 0;
	while(1)
	{
		SMCR |= (1<<SE);
		SMCR |= ((1<<SM1)|(1<<SM0));
		OCR2A = 1;//Sichergehen, dass genug Zeit seit letztem Schlafen vergangen ist
		while((ASSR & (1<<OCR2AUB)));//Warten bis Schreiben fertig, erst dann darf man schlafen
		sleep_cpu();
	}
}

