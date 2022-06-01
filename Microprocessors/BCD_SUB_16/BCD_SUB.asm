; Perform BCD Addition on two 2 16-bit 
.MODEL TINY
.CODE
.STARTUP
MOV BX, 1234H
MOV DX, 3099H

SUB DL,BL
MOV AL,DL
DAS
MOV CL,AL

SBB DH,BH
MOV AL,DH
DAS
MOV CH,AL

.EXIT
END

; The Result is stored in CX = |CH|CL|
; DAS Instruction adds (-6) = 1010B to the 4-bits segements of CH and CL whenever they are greater than 9
; DL => 99H - BL => 34H = 18H => 1100 1101B
; DH => 30H - BL => 12 = 1EH => 0001 1110B
; We add (-6) = 1010B to 1110B => 1010B + 1110B = 1 1000B => Carry = 1 and DH = 18H
; Similiarly we carry DAA intruction after perfomring ADC on DH and BH
; CX = 1865H at the end