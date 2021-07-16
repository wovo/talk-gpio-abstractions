#include <cstdint>

// pointer to the Data Direction Register for port B
auto const DDRB  = reinterpret_cast< volatile uint8_t * >( 0x24 );

// pointer to the Data Register for port B
auto const PORTB = reinterpret_cast< volatile uint8_t * >( 0x25 );

int main( void ){	
    
   // make PORTB pin 5 an output 
   *DDRB = *DDRB | ( 0b01 << 5 );
   
   for(;;){
       
      // make PORTB pin 5 high
      *PORTB = *PORTB | ( 0b01 << 5 );
      
      // wait a while
      for( uint32_t i = 0; i < 500'000; ++i ){ asm( "nop" ); }
      
      // make PORTB pin 5 low
      *PORTB = *PORTB & ~ ( 0b01 << 5 );
      
      // wait a while
      for( uint32_t i = 0; i < 500'000; ++i ){ asm( "nop" ); }
   }          
  
}   
