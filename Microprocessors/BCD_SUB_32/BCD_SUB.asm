; Perform BCD SUBTRACTION on two 2 16-bit 
.MODEL TINY
.486
.CODE
.STARTUP
; Subtract the value in EDX by EBX (EDX - EBX) 
; The Result will be stored in ECX
MOV EDX, 12345678H
MOV EBX, 00000098H

; Subtracting the bits 32-24 of EDX and EBX
; Applying DAS (Decimal Adjust AL after SUB)
; Moving the Result to CL
SUB DL,BL
MOV AL,DL
DAS
MOV CL,AL

; Subtracting the bits 24-16 of EDX and EBX (with borrow)
; Applying DAS (Decimal Adjust AL after SUB)
; Moving the Result to CH
SBB DH,BH
MOV AL,DH
DAS
MOV CH,AL

; Applying BSWAP to ECX to save the current Result
; BCX = AAAA|BBBB|CCCC|DDDD -> BSWAP -> BCX = DDDD|CCCC|BBBB|AAAA
BSWAP ECX

; moving the contents of EBX and EDX by 16-bits to right
SHR EBX, 16
SHR EDX, 16

; Subtracting the bits 16-8 of EDX and EBX (with borrow)
; Applying DAS (Decimal Adjust AL after SUB)
; Moving the Result to CH
SBB DL,BL
MOV AL,DL
DAS
MOV CH,AL

; Subtracting the bits 8-1 of EDX and EBX (with borrow)
; Applying DAS (Decimal Adjust AL after SUB)
; Moving the Result to CL
SBB DH,BH
MOV CL,DH
DAA
MOV CH,AL

; Applying BSWAP to ECX 
BSWAP ECX
.EXIT
END

; The Result of the Addition stored in ECX

