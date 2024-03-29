;THE FUNCTIONALITY OF THIS CODE IS SAVING THE COLORS OF PIXELS BEFORE DRAWING THE CAR

;PUBLIC ORIG1
;PUBLIC ORIG2
;EXTRN PIXELS1:BYTE
;EXTRN PIXELS2:BYTE
;EXTRN HEIGHT1:WORD
;EXTRN WIDTH1:WORD
;EXTRN CENTER1:WORD
;EXTRN STATE1:BYTE
;EXTRN HEIGHT2:WORD
;EXTRN WIDTH2:WORD
;EXTRN CENTER2:WORD
;EXTRN STATE2:BYTE
;EXTRN IMG2:BYTE
;EXTRN TOP1:WORD
;EXTRN TOP2:WORD
;
;.MODEL SMALL
;.STACK 64
;.CODE

ORIG1 PROC FAR

CMP STATE1 , 0      
JNZ ORIG1_RIGHT
;PERFORM EQUATION CENTER-(WIDTH/2)-(320*HEIGHT/2) TO GET TOP LEFT POINT OF THE CAR (TOP LEFT IN THE SCREEN)
;CALCULATE (320*HEIGHT/2) TERM
MOV BX,320          
MOV AX,HEIGHT1
shr AX,1
MUL BX
PUSH AX

;CALCULATE WIDTH/2 TERM
MOV AX , WIDTH1
shr AX,1

;GET THE REQUIRED POINT
MOV BX , CENTER1
SUB BX ,AX
POP AX
SUB BX,AX
MOV TOP1,BX
PUSH BX

MOV AX,BX
MOV DX,HEIGHT1  
MOV DI , OFFSET PIXELS1

UPROW:
MOV SI,AX
MOV CX,WIDTH1


ORIG1_LOOP1:
MOV AL,ES:[SI]
MOV [DI],AL
INC DI
INC SI
LOOP ORIG1_LOOP1

POP AX
ADD AX,320      ; MOVE TO THE NEXT ROW
PUSH AX
DEC DX          
CMP DX , 0
JNZ UPROW
POP AX
JMP ORIG1_EXIT



ORIG1_RIGHT:
CMP STATE1 , 1
JNZ ORIG1_LEFT
;PERFORM EQUATION CENTER-(WIDTH*320/2)+(HEIGHT/2) TO GET TOP LEFT POINT OF THE CAR (TOP RIGHT IN THE SCREEN)
;CALCULATE (HEIGHT/2) TERM
MOV AX , HEIGHT1
shr AX,1
PUSH AX

;CALCULATE WIDTH*320/2 TERM
MOV BX,320
MOV AX,WIDTH1
shr AX,1
MUL BX

;GET THE REQUIRED POINT
MOV BX , CENTER1
SUB BX ,AX
POP AX
ADD BX,AX
MOV TOP1,BX

PUSH BX

MOV AX,BX

MOV DX,HEIGHT1
MOV DI , OFFSET PIXELS1


RIGHTCOLUMN:
MOV SI,AX
MOV CX,WIDTH1

ORIG1_LOOP2:
MOV AL,ES:[SI]
MOV [DI],AL
ADD SI,320
INC DI
LOOP ORIG1_LOOP2
POP AX
SUB AX,1
PUSH AX
DEC DX
CMP DX , 0
JNZ RIGHTCOLUMN
POP AX
JMP ORIG1_EXIT



ORIG1_LEFT:
CMP STATE1,2
JNZ ORIG1_DOWN

;PERFORM EQUATION CENTER+(WIDTH*320/2)-(HEIGHT/2) TO GET TOP LEFT POINT OF THE CAR (BOTTOM LEFT IN THE SCREEN)
;CALCULATE (HEIGHT/2) TERM
MOV AX , HEIGHT1
shr AX,1
PUSH AX

;CALCULATE WIDTH*320/2 TERM
MOV BX,320
MOV AX,WIDTH1
shr AX,1
MUL BX

;GET THE REQUIRED POINT
MOV BX , CENTER1
ADD BX ,AX
POP AX
SUB BX,AX
MOV TOP1,BX

PUSH BX


MOV AX,BX
MOV DX,HEIGHT1
MOV DI , OFFSET PIXELS1


LEFTCOLUMN:
MOV SI,AX
MOV CX,WIDTH1

ORIG1_LOOP3: 
MOV AL,ES:[SI]
MOV [DI],AL
SUB SI,320
INC DI
LOOP ORIG1_LOOP3
POP AX
ADD AX,1
PUSH AX
DEC DX
CMP DX , 0
JNZ LEFTCOLUMN
POP AX
JMP ORIG1_EXIT



ORIG1_DOWN:
;PERFORM EQUATION CENTER+(WIDTH/2)+(320*HEIGHT/2) TO GET TOP LEFT POINT OF THE CAR (TOP LEFT IN THE SCREEN)
;CALCULATE (320*HEIGHT/2) TERM
MOV BX,320
MOV AX,HEIGHT1
shr AX,1
MUL BX
PUSH AX

;CALCULATE WIDTH/2 TERM
MOV AX , WIDTH1
shr AX,1

;GET THE REQUIRED POINT
MOV BX , CENTER1
ADD BX ,AX
POP AX
ADD BX,AX
MOV TOP1,BX
PUSH BX

MOV AX,BX
MOV DX,HEIGHT1
MOV DI , OFFSET PIXELS1


DOWNROW:
MOV SI,AX
MOV CX,WIDTH1

ORIG1_LOOP4:
MOV AL,ES:[SI]
MOV [DI],AL
DEC SI
INC DI
LOOP ORIG1_LOOP4
POP AX
SUB AX,320
PUSH AX
DEC DX
CMP DX , 0
JNZ DOWNROW
POP AX
ORIG1_EXIT:
RET

ORIG1 ENDP

;----------------------------------------------------------------------
;------------------------------------------------------------------------
;-------------------------------------------------------------------------

















ORIG2 PROC FAR


CMP STATE2 , 0      
JNZ ORIG2_RIGHT2
;PERFORM EQUATION CENTER-(WIDTH/2)-(320*HEIGHT/2) TO GET TOP LEFT POINT OF THE CAR (TOP LEFT IN THE SCREEN)
;CALCULATE (320*HEIGHT/2) TERM
MOV BX,320          
MOV AX,HEIGHT2
shr AX,1
MUL BX
PUSH AX

;CALCULATE WIDTH/2 TERM
MOV AX , WIDTH2
shr AX,1

;GET THE REQUIRED POINT
MOV BX ,CENTER2 
SUB BX ,AX
POP AX
SUB BX,AX
MOV TOP2,BX
PUSH BX

MOV AX,BX
MOV DX,HEIGHT2 
MOV DI , OFFSET PIXELS2

UPROW2:
MOV SI,AX
MOV CX,WIDTH2


ORIG2_LOOP12:
MOV AL,ES:[SI]
MOV [DI],AL
INC DI
INC SI
LOOP ORIG2_LOOP12

POP AX
ADD AX,320      ; MOVE TO THE NEXT ROW
PUSH AX
DEC DX          
CMP DX , 0
JNZ UPROW2
POP AX
JMP ORIG2_EXIT2



ORIG2_RIGHT2:
CMP STATE2 , 1
JNZ ORIG2_LEFT2
;PERFORM EQUATION CENTER-(WIDTH*320/2)+(HEIGHT/2) TO GET TOP LEFT POINT OF THE CAR (TOP RIGHT IN THE SCREEN)
;CALCULATE (HEIGHT/2) TERM
MOV AX , HEIGHT2
shr AX,1
PUSH AX

;CALCULATE WIDTH*320/2 TERM
MOV BX,320
MOV AX,WIDTH2
shr AX,1
MUL BX

;GET THE REQUIRED POINT
MOV BX , CENTER2
SUB BX ,AX
POP AX
ADD BX,AX
MOV TOP2,BX
PUSH BX

MOV AX,BX

MOV DX,HEIGHT2
MOV DI , OFFSET PIXELS2


RIGHTCOLUMN2:
MOV SI,AX
MOV CX,WIDTH2

ORIG2_LOOP22:
MOV AL,ES:[SI]
MOV [DI],AL
ADD SI,320
INC DI
LOOP ORIG2_LOOP22
POP AX
SUB AX,1
PUSH AX
DEC DX
CMP DX , 0
JNZ RIGHTCOLUMN2
POP AX
JMP ORIG2_EXIT2



ORIG2_LEFT2:
CMP STATE2,2
JNZ ORIG2_DOWN2

;PERFORM EQUATION CENTER+(WIDTH*320/2)-(HEIGHT/2) TO GET TOP LEFT POINT OF THE CAR (BOTTOM LEFT IN THE SCREEN)
;CALCULATE (HEIGHT/2) TERM
MOV AX , HEIGHT2
shr AX,1
PUSH AX

;CALCULATE WIDTH*320/2 TERM
MOV BX,320
MOV AX,WIDTH2
shr AX,1
MUL BX

;GET THE REQUIRED POINT
MOV BX , CENTER2
ADD BX ,AX
POP AX
SUB BX,AX
MOV TOP2,BX
PUSH BX


MOV AX,BX
MOV DX,HEIGHT2
MOV DI , OFFSET PIXELS2


LEFTCOLUMN2:
MOV SI,AX
MOV CX,WIDTH2

ORIG2_LOOP32: 
MOV AL,ES:[SI]
MOV [DI],AL
SUB SI,320
INC DI
LOOP ORIG2_LOOP32
POP AX
ADD AX,1
PUSH AX
DEC DX
CMP DX , 0
JNZ LEFTCOLUMN2
POP AX
JMP ORIG2_EXIT2



ORIG2_DOWN2:
;PERFORM EQUATION CENTER+(WIDTH/2)+(320*HEIGHT/2) TO GET TOP LEFT POINT OF THE CAR (TOP LEFT IN THE SCREEN)
;CALCULATE (320*HEIGHT/2) TERM
MOV BX,320
MOV AX,HEIGHT2
shr AX,1
MUL BX
PUSH AX

;CALCULATE WIDTH/2 TERM
MOV AX , WIDTH2
shr AX,1

;GET THE REQUIRED POINT
MOV BX , CENTER2
ADD BX ,AX
POP AX
ADD BX,AX
MOV TOP2,BX
PUSH BX

MOV AX,BX
MOV DX,HEIGHT2
MOV DI , OFFSET PIXELS2


DOWNROW2:
MOV SI,AX
MOV CX,WIDTH2

ORIG2_LOOP42:
MOV AL,ES:[SI]
MOV [DI],AL
DEC SI
INC DI
LOOP ORIG2_LOOP42
POP AX
SUB AX,320
PUSH AX
DEC DX
CMP DX , 0
JNZ DOWNROW2
POP AX
ORIG2_EXIT2:

RET

ORIG2 ENDP
;END
