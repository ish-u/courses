; Perform BCD Addition on two 2 16-bit 
.MODEL TINY
.486
.CODE
.STARTUP
; Add the value in EBX and EDX. 
; The Result will be stored in ECX
MOV EBX, 12345678H  
MOV EDX, 12345678H

; Adding the bits 32-24 of EDX and EBX
; Applying DAA (Decimal Adjust AL)
; Moving the Result to CL
ADD DL,BL
MOV AL,DL
DAA
MOV CL,AL

; Adding the bits 24-16 of EDX and EBX (with carry)
; Applying DAA (Decimal Adjust AL)
; Moving the Result to CH
ADC DH,BH
MOV AL,DH
DAA
MOV CH,AL

; Applying BSWAP to ECX to save the current Result
; BCX = AAAA|BBBB|CCCC|DDDD -> BSWAP -> BCX = DDDD|CCCC|BBBB|AAAA
BSWAP ECX

; moving the contents of EBX and EDX by 16-bits to right
SHR EBX, 16
SHR EDX, 16

; Adding the bits 16-8 of EDX and EBX (with carry)
; Applying DAA (Decimal Adjust AL)
; Moving the Result to CH
ADC DL,BL
MOV AL,DL
DAA
MOV CH,AL

; Adding the bits 16-8 of EDX and EBX (with carry)
; Applying DAA (Decimal Adjust AL)
; Moving the Result to CL
ADC DH,BH
MOV CL,DH
DAA
MOV CH,AL


; Applying BSWAP to ECX 
BSWAP ECX
.EXIT
END

; The Result of the Addition stored in ECX
