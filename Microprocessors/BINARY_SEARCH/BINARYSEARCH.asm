.MODEL TINY
.DATA
ARRAY DB 50  DUP(?) ; initlaize an array of 50 element (size element - byte)
_HIGH DW 1 DUP(?)
_LOW DW  1 DUP(?)
_SIZE DW 1 DUP(?)
; MESSAGES
; ------------------
NUMBER_OF_ELEMENT DB 10,13, 'ENTER THE NUMBER OF ELEMENTS (0-9) : $'
ELEMENT_TO_FIND DB 10,13, 'ENTER THE ELEMENT TO BE FOUND : $'
ELEMENT_FOUND DB 10,13, 'ELEMENT FOUND AT $'
ELEMENT_NOT_FOUND DB 10,13, 'ELEMENT NOT FOUND $'
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

    ; if the size not b/w 0 - 9 end prog
    CMP AL, 9H
    JA END_PROG

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

; array is input in "DESCENDING ORDER"
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


; BINARY SEARCH
MOV _LOW, 1
MOV _HIGH, BX
MOV _SIZE, BX
MOV BL, 2

FIND_ELEMENT:
; goto NOT_FOUND label if _LOW > _HIGH 
MOV CX, _HIGH
CMP _LOW,CX
JA NOT_FOUND

; finding the mid = (_LOW+_HIGH)/2
MOV AX, _HIGH
ADD AX, _LOW
DIV BL          ; mid = AX  

MOV AH,0
MOV SI, AX 
MOV CL, ARRAY[SI]
CMP CX, DI
JB MOVE_ABOVE
JA MOVE_BELOW
JMP FOUND

MOVE_ABOVE:
DEC SI
MOV _HIGH, SI
JMP FIND_ELEMENT

MOVE_BELOW:
INC SI
MOV _LOW, SI
JMP FIND_ELEMENT

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

    MOV DX, _SIZE
    SUB SI, 1
    SUB DX, SI
    ADD DL, 30H
    MOV AH, 02
    INT 21H

    JMP END_PROG

; message if element not found
NOT_FOUND:
    MOV DX, OFFSET ELEMENT_NOT_FOUND
    MOV AH,09
    INT 21H


END_PROG:

.EXIT
END