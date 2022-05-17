;--------------------------------------------;
; Author     : Chi-Keung Tang                ;
; Internet   : arion@cs.ust.hk               ;
; Program    : simple day-to-month converter ;
;--------------------------------------------;
;OK but the output buffer has some problem
;
;March.a number (1..365) : 71
;12
;


LF              = 0ah                           ; Line feed
CR              = 0dh                           ; Carriage return
Zero            = 48                            ; ASCII for zero
NumJanDate      = 31				; number of days in a month
NumFebDate      = 28
NumMarDate      = 31
NumAprDate      = 30
NumMayDate      = 31
NumJunDate      = 30
NumJulDate      = 31
NumAugDate      = 31
NumSepDate      = 30
NumOctDate      = 31
NumNovDate      = 30
NumDecDate      = 31
Terminate       = 4c00h                         ; Terminate service
DosInt          = 21h
Dseg            segment
	prompt1         db      LF, CR, 'Input a number (1..365) : ','$'
	prompt2         db      LF, CR, 'Day ','$'
	prompt3         db      ' of the year belongs to ','$'
	January         db      LF, CR, 'January.', LF, CR, '$'
	February        db      LF, CR, 'February.', LF, CR, '$'
	March           db      LF, CR, 'March.', LF, CR, '$'
	April           db      LF, CR, 'April.', LF, CR, '$'
	May             db      LF, CR, 'May.', LF, CR, '$'
	June            db      LF, CR, 'June.', LF, CR, '$'
	July            db      LF, CR, 'July.', LF, CR, '$'
	August          db      LF, CR, 'August.', LF, CR, '$'
	September       db      LF, CR, 'September.', LF, CR, '$'
	October         db      LF, CR, 'October.', LF, CR, '$'
	November        db      LF, CR, 'November.', LF, CR, '$'
	December        db      LF, CR, 'December.', LF, CR, '$'
	Ten				db		10
	char			db		' ','$'
	day             dw      0
	day_d           db      0
	string          db      4	; It control the maximum length to be inputted
	buffln          db      ?
	strbuf          db      4 dup(' '), '$'	; allocate 4 character space, '$' should be end of character
	blank           db      ' '
	newline		db	LF, CR,' ', '$'
Dseg            ends
Cseg            segment
	assume  cs:Cseg, ds:Dseg
start:  mov     ax, Dseg                        ; load ds
	mov     ds, ax
	lea     dx, prompt1                     ; load address message
	mov     ah, 9                           ; setup to output character
	int     DosInt

	lea     dx, string                      ; load input buffer start address
	mov     ah, 10                          ; read input string
	int     DosInt          

;   *** Remove the semi colon at the beginning for the below 3 lines and
;   *** and observe what's happened
;	lea     dx, string                      ; load input buffer start address
;	mov     ah, 10                          ; read input string
;	int     DosInt          

	mov     bh, 0                           ; clear upper bx
	mov     bl, buffln                      ; load input character length
	mov     si, bx                          ; store length in si

	lea     bx, strbuf                      ; load address of characters in buffer
	mov     ah, blank                       ; load blank charactor in ah
	mov     byte ptr [bx+si], ah            ; replace c.r. with blank

;	Here, if input is 123 then the content of the string buffer becomes
;   strbuf(base) | +1 | +2 | +3
;       49       | 50 | 51 | 0
;   while si stores 4, the length of input string	

;
;   (1) string-to-numeric conversion
	mov		ax,0
	mov		cx,0
conv:	mov	si,cx
	mov		al,strbuf[si]
	sub		al,Zero
	mov		day_d,al
	mov		ax,day
	mov		bx,10
	mul		bx
	mov		bh, 0
	mov		bl,day_d
	add		ax,bx
	mov		day,ax
	inc		cx
	cmp		cl,buffln
	jne		conv

;   (2) compute which month the input day falls in
;   method: 1) Cumulative subtraction by the number of day in each month
;              if the result is negative, it means the input day falls in
;              that month
;           2) If so, we need to add back the day of that month to find 
;	           out the day information

	mov		ax, 	day
	sub		ax, 	NumJanDate
	ja		feb
	add		ax, 	NumJanDate
	lea		dx,	January
	jmp		quit
feb:	
	sub		ax,	NumFebDate
	ja		mar
	add		ax,	NumFebDate
	lea		dx,	February
	jmp		quit
mar:	
	sub		ax,	NumMarDate
	ja		apr
	add		ax,	NumMarDate
	lea		dx,	March
	jmp		quit
apr:	
	sub		ax,	NumAprDate
	ja		ma
	add		ax,	NumAprDate
	lea		dx,	April
	jmp		quit
ma:	
	sub		ax,	NumMayDate
	ja		jun
	add		ax,	NumMayDate
	lea		dx,	May
	jmp		quit
jun:	
	sub		ax,	NumJunDate
	ja		jul
	add		ax,	NumJunDate
	lea		dx,	June
	jmp		quit
jul:	
	sub		ax,	NumJulDate
	ja		aug
	add		ax,	NumJulDate
	lea		dx,	July
	jmp		quit
aug:	
	sub		ax,	NumAugDate
	ja		sep
	add		ax,	NumAugDate
	lea		dx,	August
	jmp		quit
sep:	
	sub		ax,	NumSepDate
	ja		oct
	add		ax,	NumSepDate
	lea		dx,	September
	jmp		quit
oct:	
	sub		ax,	NumOctDate
	ja		nov
	add		ax,	NumOctDate
	lea		dx,	October
	jmp		quit
nov:	
	sub		ax,	NumNovDate
	ja		dece
	add		ax,	NumNovDate
	lea		dx,	November
	jmp		quit
dece:	
	lea		dx,	December

;   (3) output 

quit:	push		ax		; use interrupt to print month first
	mov		ah,9		; recall: dx has the starting address 
					; of the string representing month
	int		DosInt
	pop		ax

; (4) number to string convention and print out the character one by one

	mov		si,0
a2d:	div		Ten
	add		ah,Zero
	mov		strbuf[si],ah
	mov		ah,0
	inc		si
	cmp		al,0
	jg		a2d
	sub		si,1

;   Here we print each digit of the day one by one, the information is already
;   store in the array 'strbuf'

pr:	mov		al,strbuf[si]
	mov		char,al
	lea		dx,char
	mov		ah,9
	int		DosInt
	sub		si,1
	cmp		si,0
	jge		pr
	
	mov     ax, Terminate                   ; terminate process
	int     DosInt
Cseg    ends
	end     start

