; Perform BCD Addition on two 2 16-bit 
.MODEL TINY
.CODE
.STARTUP
MOV BX, 1234H
MOV DX, 3099H

ADD DL,BL
MOV AL,DL
DAA
MOV CL,AL

ADC DH,BH
MOV AL,DH
DAA
MOV CH,AL

.EXIT
END

; The Result is stored in CX = |CH|CL|
; DAA Instruction 6 = 0110B to the 4-bits segements of CH and CL whenever they are greater than 9
; DL => 99H + BL => 34H = CDH => 1100 1101B
; We Add 0110B to 1101 and 1100 to make them into a valid BCD
; 1101B + 0110B = 0011B and C(Carry) = 1
; 1100B + 0110B + Carry => 1 = 0011B and C(Carry) = 1;
; Thus, after DAA, AL = 0011 0011B or 33H
; Similiarly we carry DAA intruction after perfomring ADC on DH and BH
; CX = 4C43H at the end