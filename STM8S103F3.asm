include 'hex.inc' ; generating the Intel hex output instead of binary
include 'STM8.inc'
include "STM8S103F.inc"
include 'listing.inc'

    org $100 ; intended to run in RAM by stvp programmer
    
    bset PB_DDR,#5
    bres PB_ODR,#5
    
deadloop:
    ldw  X,#-1
    ldw  Y,#10
delay:
    decw X
    jrne delay
    decw Y
    jrne delay
        
    bcpl PB_ODR,#5
    
    jra  deadloop    
    
    push CC
    
