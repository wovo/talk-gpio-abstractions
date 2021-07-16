#include <cstdint>
#include "avr/io.h"

int main( void ){	
    
   DDRB = DDRB | ( 0b01 << 5 );
   
   for(;;){

      PORTB = PORTB | ( 0b01 << 5 );
      
      for( uint32_t i = 0; i < 500'000; ++i ){ asm( "nop" ); }
      
      PORTB = PORTB & ~( 0b01 << 5 );
      
      for( uint32_t i = 0; i < 500'000; ++i ){ asm( "nop" ); }
   }          
  
}   
