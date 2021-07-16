#include <cstdint>
#include "avr/io.h"

#define LED_DDR     DDRB
#define LED_PORT    PORTB
#define LED_MASK    ( 0b01 << 5 )

void blink(){
    
   LED_DDR = LED_DDR| ( 0b01 << 5 );
   
   for(;;){

      LED_PORT = LED_PORT | LED_MASK;
      
      for( uint32_t i = 0; i < 500'000; ++i ){ asm( "nop" ); }
      
      LED_PORT = LED_PORT & ~ LED_MASK;
      
      for( uint32_t i = 0; i < 500'000; ++i ){ asm( "nop" ); }
   }    
}

int main( void ){	
   blink();
}   
