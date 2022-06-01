.MODEL SMALL
.386
.DATA
MSG DB 'ENTER (AT MAX) 8 HEXADECIMAL DIGITS $'
NUM_1 DB 10,13,'ENTER 1ST NUMBER : $'
NUM_2 DB 10,13,'ENTER 2ND NUMBER : $'
RESULT DB 10,13, 'RESULT : $'
NEWLINE DB 10,13,'$'
.CODE
.STARTUP
; printing new line
MOV DX, OFFSET NEWLINE
MOV AH,09
INT 21H

; setting ESI to 0 
MOV ESI,00000H

; printing instruction
MOV DX, OFFSET MSG
MOV AH,09
INT 21H

; printing new line
MOV DX, OFFSET NEWLINE
MOV AH,09
INT 21H

; print message for first number
MOV DX, OFFSET NUM_1
MOV AH,09
INT 21H


TAKE_INPUT:
    
    MOV ECX,8   ; setting counter to 8
    MOV EBX,0   ; setting EBX = 00000000H
    INPUT_DIGIT:
        ; getting a character input
        MOV AH,1
        INT 21H 
        
        ; if user presses ENTER KEY (carriage return = 0DH in ASCII)
        ; accept the entered number till now i.e. break the input loop
        CMP AL,0DH
        JE BREAK       
        
        ; shift EBX content by 4 bits to store the entered character 
        SHL EBX,4
    
        ; if character entered by user is a NUMBER goto ADD_NUM label
        ; otherwise goto ADD_LETTER label
        ; END_LOOP label goes to the end of INPUT_DIGIT label
        MOV DL,AL
        SUB DL,30H
        CMP DL,9H
        JA ADD_LETTER
    
        ; convert the entered character by user from ASCII to Actual Value 
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
    
    ; when the user presses ENTER KEY loop breaks and program executes from this label 
    BREAK:

; if ESI != 00000000H goto SECOND_NUMBER label
CMP ESI,00000000H
JA SECOND_NUMBER

; move the value stored in EBX (by user input) to ESI
FIRST_NUMBER:
    MOV ESI,EBX

    ; print message for first number
    MOV DX, OFFSET NUM_2
    MOV AH,09
    INT 21H

    ; goto TAKE_INPUT label to get the SECOND_NUMBER
    JMP TAKE_INPUT

; move the  value stored in EBX (by user input) to EDI
SECOND_NUMBER:
    MOV EDI,EBX 

; perform  multiplication of ESI and EDI using MUL instruction
; move the result to EDI register
MOV EAX,ESI
MUL EDI
MOV EDI,EAX

; print the output of the MUL of ESI and EDI
SHOW_OUTPUT:
    ; printing new line
    MOV DX, OFFSET NEWLINE
    MOV AH,09
    INT 21H
    
    ; printing message for result
    MOV DX, OFFSET RESULT
    MOV AH,09
    INT 21H

    MOV CX,8    ; set counter to 8
    PRINT_DIGIT:
        MOV EBX,EDI         ; mov result content to EBX
        AND EBX,0F0000000H  ; get the first four bits of the RESULT (stored in EDI and moved to EBX) 
        SHR EBX,16          ; move the contents of EBX by 16 bits to the right. due to this BX now has the leftmost 16 bits
        SHL EDI,4           ; move EDI by 4 bits to get the next value 4 bits 
        
        ROR BH,4            ; rotate BH (that has the value that needs to printed by in reverse ).
        MOV BL,BH           ;  To Print = 5, value in BH = 50H; after ROR BH = 05H
        CMP BL,09H          ; convert the value present in BH to ASCII accordingly (if b/w > 09H goto PRINT_LETTER)
        JA PRINT_LETTER     
        
        ; converting to ASCII and printing value
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