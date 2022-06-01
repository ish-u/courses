.MODEL SMALL
.DATA
MSG DB 'ENTER (AT MAX) 4 HEXADECIMAL DIGITS \n $'
NUM_1 DB 10,13,'ENTER 1ST NUMBER : $'
NUM_2 DB 10,13,'ENTER 2ND NUMBER : $'
RESULT DB 10,13, 'RESULT : $'
NEWLINE DB 10,13,'$'
.CODE
.STARTUP
MOV DX, OFFSET NEWLINE
MOV AH,09
INT 21H

MOV SI,0000H

MOV DX, OFFSET MSG
MOV AH,09
INT 21H

MOV DX, OFFSET NEWLINE
MOV AH,09
INT 21H

MOV DX, OFFSET NUM_1
MOV AH,09
INT 21H


TAKE_INPUT:
    
    MOV CX,4
    MOV BX,0
    INPUT_DIGIT:
        MOV AH,1
        INT 21H 
        
        CMP AL,0DH
        JE BREAK       
        
        SHL BX,4
    
        MOV DL,AL
        SUB DL,30H
        CMP DL,9H
        JA ADD_LETTER
    
        ADD_NUM:
            SUB AL,30H
            ADD BL,AL
            JMP END_LOOP
    
        ADD_LETTER:
            MOV DL,46H
            SUB DL,AL
            MOV AL,DL
            MOV DL,0FH
            SUB DL,AL
            ADD BL,DL
            JMP END_LOOP
        
        END_LOOP:
    
    LOOP INPUT_DIGIT 
    
    BREAK:


CMP SI,0000H
JA SECOND_NUMBER

FIRST_NUMBER:
    MOV SI,BX

    MOV DX, OFFSET NUM_2
    MOV AH,09
    INT 21H

    JMP TAKE_INPUT


SECOND_NUMBER:
    MOV DI,BX 

MOV AX,SI
MUL DI
MOV DI,AX

SHOW_OUTPUT:
    MOV DX, OFFSET NEWLINE
    MOV AH,09
    INT 21H
    
    MOV DX, OFFSET RESULT
    MOV AH,09
    INT 21H

    MOV CX,4
    PRINT_DIGIT:
        MOV BX,DI
        AND BX,0F000H
        SHL DI,4
        
        ROR BH,4
        MOV BL,BH
        CMP BL,09H
        JA PRINT_LETTER
        
        PRINT_NUM:
            ADD BL,30H
            MOV DL,BL
            MOV AH,02
            INT 21H
            JMP TO_END
            
        PRINT_LETTER:
            MOV DL,0FH
            SUB DL,BL
            MOV BL,DL
            MOV DL,46H
            SUB DL,BL
            MOV AH,02
            INT 21H
        
        TO_END: 
            
    LOOP PRINT_DIGIT
        

.EXIT
END