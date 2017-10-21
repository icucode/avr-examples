#include <avr/io.h>
#include <util/delay.h>

int main()
{
   DDRB |= 1 << PB5;  /* Set LED pin on pro mini to output. */

   while( 1 )
   {
      PORTB &= 0 << PB5;
      _delay_ms( 100 );

      PORTB |= 1 << PB5;
      _delay_ms( 100 );
   }

   return 0;
}