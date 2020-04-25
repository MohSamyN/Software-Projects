org 100H

.data
inmsg db "The string: $"
input db "$"
outmsgenc db "The encrypted string is: $"
outmsgdec db "The decrypted string is: $"
table1 db 97 dup (' '), 'qwertyuiopasdfghjklzxcvbnm'
table2 db 97 dup (' '), 'kxvmcnophqrszyijadlegwbuft'

.code
LEA DX,inmsg
MOV AH,09
INT 21H
LEA DX,input
MOV AH,09H
INT 21H 

LEA BX,table1
LEA SI,input
CALL encdec
CALL newline

LEA DX,outmsgenc
MOV AH,09
INT 21H
LEA DX,input
MOV AH,09
INT 21H 

LEA BX,table2
LEA SI,input
CALL encdec
CALL newline

LEA DX,outmsgdec
MOV AH,09
INT 21H
LEA DX,input
MOV AH,09
INT 21H

CALL newline 
MOV AH,07H
INT 21H
    
RET

encdec PROC near
    next:
    CMP [SI],'$'
    JE end
    MOV AL,[SI]
    CMP AL,'a'
    JB no
    CMP AL,'z'
    JA no
    XLAT
    MOV [SI],AL
    no:
    INC SI
    JMP next
    end:
    RET 
encdec ENDP

newline PROC
    MOV DL,0DH
    MOV AH,2     
    INT 21H
    MOV DL,0AH     
    INT 21H   
    RET
newline ENDP    