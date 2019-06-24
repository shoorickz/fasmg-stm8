Listing? = 1

namespace Listing 
        base = $$ 
        offset = $ 
        macro disphex number*,digits:8 
                repeat digits 
                        digit = ((number) shr ((%%-%) shl 2)) and 0Fh 
                        if digit < 10 
                                display '0'+digit 
                        else 
                                display 'A'+digit-10 
                        end if 
                end repeat 
        end macro 
end namespace 

macro ? line& 
        match =no? =listing?, line
                Listing? =: 0
        else match =listing? =back?, line
                restore Listing?
        else
                line
                if Listing
                        namespace Listing
                                if ~ $$ eq base
                                        base = $$
                                        offset = $$
                                end if
                                bytes = $ - offset
                                if $ - bytes < $$
                                        bytes = $ - $$
                                end if
                                offset = $
                                disphex (offset scale 0)-bytes,8
                                display ': '
                                column = 0
                                while bytes > 0
                                        if column = 8
                                                column = 0
                                                display 13,10,'          '
                                        end if
                                        load data:byte from $ - bytes
                                        disphex data,2
                                        display ' '
                                        bytes = bytes - 1
                                        column = column + 1
                                end while
                                repeat 8-column
                                        display '   '
                                end repeat
                                display `line,13,10
                        end namespace
                end if
        end match
end macro