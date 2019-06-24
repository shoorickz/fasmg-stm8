;=======================================================================
element A?
element X?
element Y?
element SP?
element XL?
element XH?
element YL?
element YH?
element CC?
;-----------------------------------------------------------------------
macro dc.b? values&
  irp v,values
    db (v) 
  end irp
end macro
;-----------------------------------------------------------------------
macro dc.w? values&
  irp v,values
    db (v) bswap 2
  end irp
end macro
;-----------------------------------------------------------------------
macro dc.l? values&
  irp v,values
    db (v) bswap 4
  end irp
end macro
;-----------------------------------------------------------------------
macro dc.e? values&
  irp v,values
    db (v) bswap 3
  end irp
end macro 
;-----------------------------------------------------------------------
macro stm8_offset stm8e,stm8h,stm8l,data,bytes
    if data shr (bytes*8)
        err "Address is out of range"
    end if
    stm8e = data shr 16 
    stm8h = data shr 8 and $FF
    stm8l = data and $FF
end macro
;-----------------------------------------------------------------------
macro LD? args&
    match =A?=,param, args
        match #data,param
            db $A6,+data
        else match ( [ data =.w? ] =, =X?),param
            stm8_offset stm8e,stm8h,stm8l,data,2
            if stm8h
                db $72,$D6,stm8h,stm8l
            else
                db $92,$D6,stm8l
            end if
        else match ( [ data =.w? ] =, =Y?),param
            stm8_offset stm8e,stm8h,stm8l,data,1
            db $91,$D6,stm8l
        else match ( data =, =X?),param
            stm8_offset stm8e,stm8h,stm8l,data,2
            if stm8h
                db $D6,stm8h,stm8l
            else
                db $E6,stm8l
            end if
        else match ( data =, =Y?),param
            stm8_offset stm8e,stm8h,stm8l,data,2
            if stm8h
                db $90,$D6,stm8h,stm8l
            else
                db $90,$E6,stm8l
            end if
        else match ( data =, =SP?),param
            stm8_offset stm8e,stm8h,stm8l,data,1
            db $7B,stm8l
        else match [ data =.w? ],param
            stm8_offset stm8e,stm8h,stm8l,data,2
            if stm8h
                db $72,$C6,stm8h,stm8l
            else
                db $92,$C6,stm8l
            end if
        else match ( =X? ),param
            db $F6
        else match ( =Y? ),param
            db $90,$F6
        else match =XL?,param
            db $9F
        else match =XH?,param
            db $9E
        else match =YL?,param
            db $90,$9F
        else match =YH?,param
            db $90,$9E
        else 
            stm8_offset stm8e,stm8h,stm8l,param,2
            if stm8h
                db $C6,stm8h,stm8l
            else
                db $B6,stm8l
            end if
        end match
    else match param=,=A?, args    
        match ( [ data =.w? ] =, =X?),param
            stm8_offset stm8e,stm8h,stm8l,data,2
            if stm8h
                db $72,$D7,stm8h,stm8l
            else
                db $92,$D7,stm8l
            end if
        else match ( [ data =.w? ] =, =Y?),param
            stm8_offset stm8e,stm8h,stm8l,data,1
            db $91,$D7,stm8l
        else match ( data =, =X?),param
            stm8_offset stm8e,stm8h,stm8l,data,2
            if stm8h
                db $D7,stm8h,stm8l
            else
                db $E7,stm8l
            end if
        else match ( data =, =Y?),param
            stm8_offset stm8e,stm8h,stm8l,data,2
            if stm8h
                db $90,$D7,stm8h,stm8l
            else
                db $90,$E7,stm8l
            end if
        else match ( data =, =SP?),param
            stm8_offset stm8e,stm8h,stm8l,data,1
            db $6B,stm8l
        else match [ data =.w? ],param
            stm8_offset stm8e,stm8h,stm8l,data,2
            if stm8h
                db $72,$C7,stm8h,stm8l
            else
                db $92,$C7,stm8l
            end if
        else match ( =X? ),param
            db $F7
        else match ( =Y? ),param
            db $90,$F7
        else match =XL?,param
            db $97
        else match =XH?,param
            db $95
        else match =YL?,param
            db $90,$97
        else match =YH?,param
            db $90,$95
        else 
            stm8_offset stm8e,stm8h,stm8l,param,2
            if stm8h
                db $C7,stm8h,stm8l
            else
                db $B7,stm8l
            end if
        end match
    else 
        err "Syntax error"
    end match
end macro
;-----------------------------------------------------------------------
irp <mnem,magic>, \
ADC?,$9,ADD?,$B,AND?,$4,BCP?,$5,CP?,$1,OR?,$A,SBC?,$2,SUB?,$0,XOR?,$8
macro mnem args&
    match =A?=,param, args
        match #data,param
            db $A0+magic,+data
        else match ( [ data =.w? ] =, =X?),param
            stm8_offset stm8e,stm8h,stm8l,data,2
            if stm8h
                db $72,$D0+magic,stm8h,stm8l
            else
                db $92,$D0+magic,stm8l
            end if
        else match ( [ data =.w? ] =, =Y?),param
            stm8_offset stm8e,stm8h,stm8l,data,1
            db $91,$D0+magic,stm8l
        else match ( data =, =X?),param
            stm8_offset stm8e,stm8h,stm8l,data,2
            if stm8h
                db $D0+magic,stm8h,stm8l
            else
                db $E0+magic,stm8l
            end if
        else match ( data =, =Y?),param
            stm8_offset stm8e,stm8h,stm8l,data,2
            if stm8h
                db $90,$D0+magic,stm8h,stm8l
            else
                db $90,$E0+magic,stm8l
            end if
        else match ( data =, =SP?),param
            stm8_offset stm8e,stm8h,stm8l,data,1
            db $10+magic,stm8l
        else match [ data =.w? ],param
            stm8_offset stm8e,stm8h,stm8l,data,2
            if stm8h
                db $72,$C0+magic,stm8h,stm8l
            else
                db $92,$C0+magic,stm8l
            end if
        else match ( =X? ),param
            db $F0+magic
        else match ( =Y? ),param
            db $90,$F0+magic
        else 
            stm8_offset stm8e,stm8h,stm8l,param,2
            if stm8h
                db $C0+magic,stm8h,stm8l
            else
                db $B0+magic,stm8l
            end if
        end match
    else match =SP?=,#data,args 
        if ~magic
            db $52,+data
        else
            err "Syntax error"
        end if
    else 
        err "Syntax error"
    end match
end macro
end irp
;-----------------------------------------------------------------------
macro ADDW? dst,src&
    match =SP?,dst
        match #data,src
            db $5B,+data
        else
            err "Syntax error"
        end match
    else match =X?,dst
        match #data,src
            db $1C,data shr 8,data and $FF
        else match ( data =, =SP? ),src
            stm8_offset stm8e,stm8h,stm8l,data,1
            db $72,$FB,stm8l
        else
            stm8_offset stm8e,stm8h,stm8l,src,2
            db $72,$BB,stm8h,stm8l
        end match
    else match =Y?,dst
        match #data,src
            db $72,$A9,data shr 8,data and $FF
        else match ( data =, =SP? ),src
            stm8_offset stm8e,stm8h,stm8l,data,1
            db $72,$F9,stm8l
        else
            stm8_offset stm8e,stm8h,stm8l,src,2
            db $72,$B9,stm8h,stm8l
        end match
    else
        err "Syntax error"
    end match
end macro
;-----------------------------------------------------------------------
macro BCCM? dst,pos
    assert ~(dst shr 16 or pos shr 3)
    match #data,pos
        db $90,$11 or pos shl 1,dst shr 8,dst and $FF
    else
        err "Syntax error"
    end match
end macro
;-----------------------------------------------------------------------
macro BCPL? dst,pos
    assert ~(dst shr 16 or pos shr 3)
    match #data,pos
        db $90,$10 or pos shl 1,dst shr 8,dst and $FF
    else
        err "Syntax error"
    end match
end macro
;-----------------------------------------------------------------------
irp <mnem,op>,\
_BREAK?,$8B,CCF?,$8C,HALT?,$8E,IRET?,$80,RCF?,$98,RET?,$81,RETF?,$87,\
RIM?,$9A,RVF?,$9C,SCF?,$99,SIM?,$9B,TRAP?,$83,WFI?,$8F,NOP?,$9D
macro mnem
    db op
end macro
end irp
;-----------------------------------------------------------------------
macro BRES? dst,pos
    assert ~(dst shr 16 or pos shr 3)
    match #data,pos
        db $72,$11 or pos shl 1,dst shr 8,dst and $FF
    else
        err "Syntax error"
    end match
end macro
;-----------------------------------------------------------------------
macro BSET? dst,pos
    assert ~(dst shr 16 or pos shr 3)
    match #data,pos
        db $72,$10 or pos shl 1,dst shr 8,dst and $FF
    else
        err "Syntax error"
    end match
end macro
;-----------------------------------------------------------------------
macro BTJF? dst,pos,rel
    assert ~(dst shr 16 or pos shr 3)
    match #data,pos
        db $72,$1 or pos shl 1,dst shr 8,dst and $FF,rel - $ - 1
    else
        err "Syntax error"
    end match
end macro
;-----------------------------------------------------------------------
macro BTJT? dst,pos,rel
    assert ~(dst shr 16 or pos shr 3)
    match #data,pos
        db $72,pos shl 1,dst shr 8,dst and $FF,rel - $ - 1
    else
        err "Syntax error"
    end match
end macro
;-----------------------------------------------------------------------
irp <mnem,magic>,CALL?,$D,JP?,$C
macro mnem dst&
    match ( [ data =.w? ] =, =X? ),dst
        stm8_offset stm8e,stm8h,stm8l,data,2
        if stm8h
            db $72,$D0 or magic,stm8h,stm8l
        else
            db $92,$D0 or magic,stm8l
        end if
    else match ( [ data =.w? ] =, =Y? ),dst
        stm8_offset stm8e,stm8h,stm8l,data,1
        db $91,$D0 or magic,stm8l
    else match ( data =, =X? ),dst
        stm8_offset stm8e,stm8h,stm8l,data,2
        if stm8h
            db $D0 or magic,stm8h,stm8l
        else
            db $E0 or magic,stm8l
        end if
    else match ( data =, =Y? ),dst
        stm8_offset stm8e,stm8h,stm8l,data,2
        if stm8h
            db $90,$D0 or magic,stm8h,stm8l
        else
            db $90,$E0 or magic,stm8l
        end if
    else match ( =X? ),dst
        db $F0 or magic
    else match ( =Y? ),dst
        db $90,$F0 or magic
    else match [ data =.w? ],dst
        stm8_offset stm8e,stm8h,stm8l,data,2
        if stm8h
            db $72,$C0 or magic,stm8h,stm8l
        else
            db $92,$C0 or magic,stm8l
        end if
    else
        stm8_offset stm8e,stm8h,stm8l,dst,2
        db $C0 or magic,stm8h,stm8l
    end match
end macro
end irp
;-----------------------------------------------------------------------
macro CALLF? dst
    match [ addr =.e? ],dst
        stm8_offset stm8e,stm8h,stm8l,addr,2
        db $92,$8D,stm8h,stm8l
    else
        stm8_offset stm8e,stm8h,stm8l,dst,3
        db $8D,stm8e,stm8h,stm8l
    end match
end macro
;-----------------------------------------------------------------------
irp <mnem,magic>,\
CLR?,$F,CPL?,$3,DEC?,$A,INC?,$C,NEG?, $0,RLC?,$9,\
RRC?,$6,SLL?,$8,SRA?,$7,SRL?,$4,SWAP?,$E,TNZ?,$D
macro mnem dst&
    match =A?,dst
        db $40+magic
    else match ( [ data =.w? ] =, =X? ),dst
        stm8_offset stm8e,stm8h,stm8l,data,2                
        if stm8h
            db $72,$60+magic,stm8h,stm8l
        else
            db $92,$60+magic,stm8l
        end if
    else match ( [ data =.w? ] =, =Y? ),dst
        stm8_offset stm8e,stm8h,stm8l,data,1                
        db $91,$60+magic,stm8l
    else match ( data  =, =X? ),dst
        stm8_offset stm8e,stm8h,stm8l,data,2                
        if stm8h
            db $72,$40+magic,stm8h,stm8l
        else
            db $60+magic,stm8l
        end if
    else match ( data  =, =Y? ),dst
        stm8_offset stm8e,stm8h,stm8l,data,2                
        if stm8h
            db $90,$40+magic,stm8h,stm8l
        else
            db $90,$60+magic,stm8l
        end if
    else match ( data  =, =SP? ),dst
        stm8_offset stm8e,stm8h,stm8l,data,1                
        db $00+magic,stm8l
    else match ( =X? ),dst
        db $70+magic
    else match ( =Y? ),dst
        db $90,$70+magic
    else match [ data =.w? ],dst
        stm8_offset stm8e,stm8h,stm8l,data,2                
        if stm8h
            db $72,$30+magic,stm8h,stm8l
        else
            db $92,$30+magic,stm8l
        end if
    else
        stm8_offset stm8e,stm8h,stm8l,dst,2 
        if stm8h
            db $72,$50+magic,stm8h,stm8l
        else
            db $30+magic,stm8l
        end if
    end match
end macro
end irp
;-----------------------------------------------------------------------
irp <mnem,op>,\
CLRW?,$5F,CPLW?,$53,DECW?,$5A,INCW?,$5C,NEGW?,$50,POPW?,$85,PUSHW?,$89,\
RLCW?,$59,RRCW?,$56,SLLW?,$58,SRAW?,$57,SRLW?,$54,SWAPW?,$5E,TNZW?,$5D
macro mnem dst
    match =X?,dst
        db op
    else match =Y?,dst
        db $90,op
    else 
        err "Syntax error"
    end match  
end macro
end irp
;-----------------------------------------------------------------------
macro CPW? dst,src&
    match =X?,dst
        match #data,src
            db $A3,src shr 8,src and $FF
        else match ( =Y? ),src
            db $90,$F3
        else match ( [ data =.w? ] =, =Y? ),src
            stm8_offset stm8e,stm8h,stm8l,data,1
            db $91,$D3,stm8l
        else match ( data =, =Y? ),src
            stm8_offset stm8e,stm8h,stm8l,data,2
            if stm8h
                db $90,$D3,stm8h,stm8l
            else
                db $90,$E3,stm8l
            end if
        else match ( data =, =SP? ),src
            stm8_offset stm8e,stm8h,stm8l,data,1
            db $13,stm8l
        else match [ data =.w? ],src
            stm8_offset stm8e,stm8h,stm8l,data,2
            if stm8h
                db $72,$C3,stm8h,stm8l
            else
                db $92,$C3,stm8l
            end if
        else 
            stm8_offset stm8e,stm8h,stm8l,src,2
            if stm8h
                db $C3,stm8h,stm8l
            else
                db $B3,stm8l
            end if
        end match
    else match =Y?,dst
        match #data,src
            db $90,$A3,src shr 8,src and $FF
        else match ( =X? ),src
            db $F3
        else match ( [ data =.w? ] =, =X? ),src
            stm8_offset stm8e,stm8h,stm8l,data,2
            if stm8h
                db $72,$D3,stm8h,stm8l
            else
                db $92,$D3,stm8l
            end if
        else match ( data =, =X? ),src
            stm8_offset stm8e,stm8h,stm8l,data,2
            if stm8h
                db $D3,stm8h,stm8l
            else
                db $E3,stm8l
            end if
        else match ( data =, =SP? ),src
            stm8_offset stm8e,stm8h,stm8l,data,1
            db $13,stm8l
        else match [ data =.w? ],src
            stm8_offset stm8e,stm8h,stm8l,data,1
            db $91,$C3,stm8l
        else 
            stm8_offset stm8e,stm8h,stm8l,src,2
            if stm8h
                db $90,$C3,stm8h,stm8l
            else
                db $90,$B3,stm8l
            end if
        end match
    else
        err "Syntax error"
    end match
end macro
;-----------------------------------------------------------------------
macro DIV? param&
    match =X? =, =A?,param
        db $62
    else match =Y? =, =A?,param
        db $90,$62
    else
        err "Syntax error"
    end match    
end macro
;-----------------------------------------------------------------------
macro DIVW? param&
    match =X? =, =Y?,param
        db $65
    else
        err "Syntax error"
    end match    
end macro
;-----------------------------------------------------------------------
macro EXG? param&
    match =A? =, =XL?,param
        db $41
    else match =A? =, =YL?,param
        db $61
    else match =A? =, data,param
        stm8_offset stm8e,stm8h,stm8l,data,2
        db $31,stm8h,stm8l
    else
        err "Syntax error"
    end match        
end macro
;-----------------------------------------------------------------------
macro EXGW? param&
    match =X? =, =Y?,param
        db $51
    else 
        err "Syntax error"
    end match
end macro
;-----------------------------------------------------------------------
macro INT? dst
    stm8_offset stm8e,stm8h,stm8l,dst,3
    db $82,stm8e,stm8h,stm8l
end macro
;-----------------------------------------------------------------------
macro JPF? dst
    match [ addr =.e ],dst
        stm8_offset stm8e,stm8h,stm8l,addr,2
        db $92,$AC,stm8h,stm8l
    else
        stm8_offset stm8e,stm8h,stm8l,dst,3
        db $AC,stm8e,stm8h,stm8l
    end match
end macro
;-----------------------------------------------------------------------
irp <mnem,op>,CALLR?,$AD,\
JRA?,$20,JRC?,$25,JREQ?,$27,JRF?,$21,JRMI?,$2B,JRNC?,$24,JRNE?,$26,\
JRNV?,$28,JRPL?,$2A,JRSGE?,$2E,JRSGT?,$2C,JRSLE?,$2D,JRSLT?,$2F,\
JRT?,$20,JRUGE?,$24,JRUGT?,$22,JRULE?,$23,JRULT?,$25,JRV?,$29
macro mnem dst
    db op,dst - $ - 1
end macro
end irp
;-----------------------------------------------------------------------
irp <mnem,op>,\
JRH?,$29,JRIH?,$2F,JRIL?,$2E,JRM?,$2D,JRNH?,$28,JRNM?,$2C
macro mnem dst
    db $90,op,dst - $ - 1
end macro
end irp
;-----------------------------------------------------------------------
macro LDF? param&
    match =A? =, [ data =.e? ],param
        stm8_offset stm8e,stm8h,stm8l,data,2
        db $92,$BC,stm8h,stm8l
    else match =A? =, ( [ data =.e? ] =, =X? ),param
        stm8_offset stm8e,stm8h,stm8l,data,2
        db $92,$AF,stm8h,stm8l
    else match =A? =, ( [ data =.e? ] =, =Y? ),param
        stm8_offset stm8e,stm8h,stm8l,data,2
        db $91,$AF,stm8h,stm8l
    else match =A? =, ( data =, =X? ),param
        stm8_offset stm8e,stm8h,stm8l,data,3
        db $AF,stm8e,stm8h,stm8l
    else match =A? =, ( data =, =Y? ),param
        stm8_offset stm8e,stm8h,stm8l,data,3
        db $90,$AF,stm8e,stm8h,stm8l
    else match =A? =, data,param
        stm8_offset stm8e,stm8h,stm8l,data,3
        db $BC,stm8e,stm8h,stm8l
    else match [ data =.e? ] =, =A?,param
        stm8_offset stm8e,stm8h,stm8l,data,2
        db $92,$BD,stm8h,stm8l
    else match ( [ data =.e? ] =, =X? ) =, =A?,param
        stm8_offset stm8e,stm8h,stm8l,data,2
        db $92,$A7,stm8h,stm8l
    else match ( [ data =.e? ] =, =Y? ) =, =A?,param
        stm8_offset stm8e,stm8h,stm8l,data,2
        db $91,$A7,stm8h,stm8l
    else match ( data =, =X? ) =, =A?,param
        stm8_offset stm8e,stm8h,stm8l,data,3
        db $A7,stm8e,stm8h,stm8l
    else match ( data =, =Y? ) =, =A?,param
        stm8_offset stm8e,stm8h,stm8l,data,3
        db $90,$A7,stm8e,stm8h,stm8l
    else match data =, =A?,param
        stm8_offset stm8e,stm8h,stm8l,data,3
        db $BD,stm8e,stm8h,stm8l
    else
        err "Syntax error"
    end match
end macro
;-----------------------------------------------------------------------
macro LDW? param&
    match =Y? =, =X?,param
        db $90,$93
    else match =X? =, =Y?,param
        db $93
    else match =X? =, =SP?,param
        db $96
    else match =SP? =, =X?,param
        db $94
    else match =Y? =, =SP?,param
        db $90,$96
    else match =SP? =, =Y?,param
        db $90,$94
    else match =X? =, src,param
        match #data,src
            db $AE,data shr 8,data and $FF
        else match (=X?),src
            db $FE
        else match ( [ data =.w? ] =, X? ),src
            stm8_offset stm8e,stm8h,stm8l,data,2
            if stm8h
                db $72,$DE,stm8h,stm8l
            else
                db $92,$DE,stm8l
            end if
        else match ( data =, =X? ),src
            stm8_offset stm8e,stm8h,stm8l,data,2
            if stm8h
                db $DE,stm8h,stm8l
            else
                db $EE,stm8l
            end if
        else match ( data =, =SP? ),src
            stm8_offset stm8e,stm8h,stm8l,data,1
            db $1E,stm8l
        else match [ data =.w? ],src
            stm8_offset stm8e,stm8h,stm8l,data,2
            if stm8h
                db $72,$CE,stm8h,stm8l
            else
                db $92,$CE,stm8l
            end if
        else
            stm8_offset stm8e,stm8h,stm8l,src,2
            if stm8h
                db $CE,stm8h,stm8l
            else
                db $BE,stm8l
            end if
        end match
    else match dst =, =X?,param
        match (=Y?),dst
            db $90,$FF
        else match ( [ data =.w? ] =, Y? ),dst
            stm8_offset stm8e,stm8h,stm8l,data,1
            db $91,$DF,stm8l
        else match ( data =, =Y? ),dst
            stm8_offset stm8e,stm8h,stm8l,data,2
            if stm8h
                db $90,$DF,stm8h,stm8l
            else
                db $90,$EF,stm8l
            end if
        else match ( data =, =SP? ),dst
            stm8_offset stm8e,stm8h,stm8l,data,1
            db $1F,stm8l
        else match [ data =.w? ],dst
            stm8_offset stm8e,stm8h,stm8l,data,2
            if stm8h
                db $72,$CF,stm8h,stm8l
            else
                db $92,$CF,stm8l
            end if
        else
            stm8_offset stm8e,stm8h,stm8l,dst,2
            if stm8h
                db $CF,stm8h,stm8l
            else
                db $BF,stm8l
            end if
        end match
    else match =Y? =, src,param
        match #data,src
            db $90,$AE,data shr 8,data and $FF
        else match (=Y?),src
            db $90,$FE
        else match ( [ data =.w? ] =, Y? ),src
            stm8_offset stm8e,stm8h,stm8l,data,1
            db $91,$DE,stm8l
        else match ( data =, =Y? ),src
            stm8_offset stm8e,stm8h,stm8l,data,2
            if stm8h
                db $90,$DE,stm8h,stm8l
            else
                db $90,$EE,stm8l
            end if
        else match ( data =, =SP? ),src
            stm8_offset stm8e,stm8h,stm8l,data,1
            db $16,stm8l
        else match [ data =.w? ],src
            stm8_offset stm8e,stm8h,stm8l,data,1
            db $91,$CE,stm8l
        else
            stm8_offset stm8e,stm8h,stm8l,src,2
            if stm8h
                db $90,$CE,stm8h,stm8l
            else
                db $90,$BE,stm8l
            end if
        end match
    else match dst =, =Y?,param
        match (=X?),dst
            db $FF
        else match ( [ data =.w? ] =, X? ),dst
            stm8_offset stm8e,stm8h,stm8l,data,2
            if stm8h
                db $72,$DF,stm8h,stm8l
            else
                db $92,$DF,stm8l
            end if
        else match ( data =, =X? ),dst
            stm8_offset stm8e,stm8h,stm8l,data,2
            if stm8h
                db $DF,stm8h,stm8l
            else
                db $EF,stm8l
            end if
        else match ( data =, =SP? ),dst
            stm8_offset stm8e,stm8h,stm8l,data,1
            db $17,stm8l
        else match [ data =.w? ],dst
            stm8_offset stm8e,stm8h,stm8l,data,1
            db $91,$CF,stm8l
        else
            stm8_offset stm8e,stm8h,stm8l,dst,2
            if stm8h
                db $90,$CF,stm8h,stm8l
            else
                db $90,$BF,stm8l
            end if
        end match
    else
        err "Syntax error"
    end match
end macro
;-----------------------------------------------------------------------
macro MOV? dst,src 
    stm8_offset stm8e,stm8h,stm8l,dst,2
    match #data,src
        db $35,data,stm8h,stm8l
    else ; not sure about direction
        stm8_offset stm8e,stm8h2,stm8l2,src,2
        if stm8h | stm8h2
            db $55,stm8h2,stm8l2,stm8h,stm8l
        else
            db $45,stm8l2,stm8l
        end if
    end match
end macro
;-----------------------------------------------------------------------
macro MUL? param&
    match =X? =, =A?,param
        db $42
    else match =Y? =, =A?,param
        db $90,$42
    else
        err "Syntax error"
    end match      
end macro
;-----------------------------------------------------------------------
macro POP? dst
    match =A,dst
        db $84
    else match =CC?,dst
        db $86
    else 
        stm8_offset stm8e,stm8h,stm8l,dst,2
        db $32,stm8h,stm8l
    end match
end macro
;-----------------------------------------------------------------------
macro PUSH? src
    match =A,src
        db $88
    else match =CC?,src
        db $8A
    else match #data,src
        db $4B,data
    else 
        stm8_offset stm8e,stm8h,stm8l,src,2
        db $3B,stm8h,stm8l
    end match
end macro
;-----------------------------------------------------------------------
macro RLWA? param&
    match =X? =, =A?,param
        db $02
    else match =Y? =, =A?,param
        db $90,$02
    else
        err "Syntax error"
    end match      
end macro
;-----------------------------------------------------------------------
macro RRWA? param&
    match =X? =, =A?,param
        db $01
    else match =Y? =, =A?,param
        db $90,$01
    else
        err "Syntax error"
    end match      
end macro
;-----------------------------------------------------------------------
macro SLA? param&
    SLL param
end macro
;-----------------------------------------------------------------------
macro SLAW? dst
    SLLW dst
end macro
;-----------------------------------------------------------------------
macro SUBW? param&
    match =X? =, #data,param
        db $1D,data shr 8,data and $FF
    else match =X? =, ( data =, =SP? ),param
        db $72,$F0,data
    else match =X? =, data, param
        stm8_offset stm8e,stm8h,stm8l,data,2
        db $72,$B0,stm8h,stm8l
    else match =Y? =, #data,param
        db $72,$A2,data shr 8,data and $FF
    else match =Y? =, ( data =, =SP? ),param
        db $72,$F2,data
    else match =Y? =, data, param
        stm8_offset stm8e,stm8h,stm8l,data,2
        db $72,$B2,stm8h,stm8l
    else
        err "Syntax error"
    end match
end macro
;-----------------------------------------------------------------------
macro WFE?
    db $72,$8F
end macro
;-----------------------------------------------------------------------
