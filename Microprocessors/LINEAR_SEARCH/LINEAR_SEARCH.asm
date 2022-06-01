.MODEL TINY
.DATA
ARRAY DB 50  DUP(?) ; initlaize an array of 50 element (size element - byte)
; MESSAGES
; ------------------
NUMBER_OF_ELEMENT DB 10,13, 'ENTER THE NUMBER OF ELEMENTS (0-9) : $'
ELEMENT_TO_FIND DB 10,13, 'ENTER THE ELEMENT TO BE FOUND : $'
ELEMENT_FOUND DB 10,13, 'ELEMENT FOUND$'
ELEMENT_NOT_FOUND DB 10,13, 'ELEMENT NOT FOUND$'
NEWLINE DB 10,13,'$'
; ------------------
.CODE
.STARTUP

GET_SIZE_OF_ARRAY:
    ; message 
    MOV DX, OFFSET NUMBER_OF_ELEMENT
    MOV AH,09
    INT 21H

    MOV BX,0

   ; getting the user input
    MOV AH,1
    INT 21H 
           
    SUB AL, 30H
    MOV BL, AL

    ; newline
    MOV DX, OFFSET NEWLINE
    MOV AH,09
    INT 21H
    
; getting the number of elements in the CL register
MOV CX,0
MOV CL,BL
; newline
MOV DX, OFFSET NEWLINE
MOV AH,09
INT 21H
GET_ARRAY_INPUT:
    MOV AH,1
    INT 21H     

    MOV SI,CX
    
    ; saving the input element to the ARRAY 
    MOV ARRAY[SI], AL
    
    ; space
    MOV DX, ' '
    MOV AH, 02
    INT 21H
    
    
LOOP GET_ARRAY_INPUT 

; getting the element to search
GET_ELEMENT_INPUT:
    MOV DX, OFFSET NEWLINE
    MOV AH,09
    INT 21H
    
    MOV DX, OFFSET ELEMENT_TO_FIND
    MOV AH, 09
    INT 21H

    MOV AH,01
    INT 21H     

    MOV DI, 0
    MOV DI, AX

    AND DI,00FFH


; looping through the ARRAY array to find if the element exists
MOV CX, 0
MOV DX, 0
MOV CL, BL
FIND_ELEMENT:
    MOV SI, CX
    MOV DL, ARRAY[SI]
             
    CMP DI,DX
    JE FOUND
    
LOOP FIND_ELEMENT

; newline
MOV DX, OFFSET NEWLINE
MOV AH,09
INT 21H

JMP NOT_FOUND 

; mwssage if element found
FOUND:
    MOV DX, OFFSET ELEMENT_FOUND
    MOV AH,09
    INT 21H

    JMP END_PROG

; message if element not found
NOT_FOUND:
    MOV DX, OFFSET ELEMENT_NOT_FOUND
    MOV AH,09
    INT 21H

END_PROG:
    ; newline
    MOV DX, OFFSET NEWLINE
    MOV AH,09
    INT 21H

.EXIT
END