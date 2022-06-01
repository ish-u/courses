; Subtract Two 32-bit number using 4 16-bit Registers 
; SUB A = 12345678H and B = 98765432H
.MODEL TINY
.CODE
.STARTUP
MOV AX, 5678H   ; moving the 16 LSB of A to AX
MOV BX, 5432H   ; moving the 16 LSB of B to BX
SUB AX, BX
MOV CX, 1234H   ; moving the 16 MSB of A to CX
MOV DX, 9876H   ; moving the 16 MSB of A to CX
SBB CX, DX      ; Subtraction with Borrow
.EXIT
END

; The Resulting 32 Number will be stored as [CX][AX]