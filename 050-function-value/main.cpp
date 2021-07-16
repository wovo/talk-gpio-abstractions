#include <cstdint>
#include "avr/io.h"

enum class pin {
    b0, b1, b2, b3, b4, b5, b6, b7,
    c0, c1, c2, c3, c4, c5, c6, c7
};

struct single_pin_info {
    volatile uint8_t & direction;
    volatile uint8_t & data;
    uint8_t mask;
};

const single_pin_info pin_info [] = {
    { DDRB, PORTB, ( 0b01 << 0 ) },
    { DDRB, PORTB, ( 0b01 << 1 ) },
    { DDRB, PORTB, ( 0b01 << 2 ) },
    { DDRB, PORTB, ( 0b01 << 3 ) },
    { DDRB, PORTB, ( 0b01 << 4 ) },
    { DDRB, PORTB, ( 0b01 << 5 ) },
    { DDRB, PORTB, ( 0b01 << 6 ) },
    { DDRB, PORTB, ( 0b01 << 7 ) },

    { DDRC, PORTC, ( 0b01 << 0 ) },
    { DDRC, PORTC, ( 0b01 << 1 ) },
    { DDRC, PORTC, ( 0b01 << 2 ) },
    { DDRC, PORTC, ( 0b01 << 3 ) },
    { DDRC, PORTC, ( 0b01 << 4 ) },
    { DDRC, PORTC, ( 0b01 << 5 ) },
    { DDRC, PORTC, ( 0b01 << 6 ) },
    { DDRC, PORTC, ( 0b01 << 7 ) }
};

void pin_mode_output( pin p ){
    auto info = pin_info[ static_cast< int >( p ) ];
    info.direction = info.direction | info.mask;
}

void pin_write( pin p, bool value ){
    auto info = pin_info[ static_cast< int >( p ) ];
    if( value ){
        info.data = info.data | info.mask;
    } else {
        info.data = info.data & ~ info.mask;
    }
}

void blink( pin p ){    
   pin_mode_output( p );
   for(;;){
      pin_write( p, 1 );
      for( uint32_t i = 0; i < 500'000; ++i ){ asm( "nop" ); }
      pin_write( p, 0 );
      for( uint32_t i = 0; i < 500'000; ++i ){ asm( "nop" ); }
   }    
}

int main( void ){	
   blink( pin::b5 );
}   

