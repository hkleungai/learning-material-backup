;Laboratory Exercise 
;You are to write a program in 8088 assembly language to turn on the PC speaker at 256 Hz for 5 seconds. 
;ญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญ; 
; Author : ChiญKeung Tang ; 
; Program : turning on the PC speaker ; 
; at some frequency ; 
; for specific duration ; 
;ญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญ; 
Port		= 61h ; I/O ports 
Timer2		= 42h ; Timer2 
TimerMode	= 43h 
on		= 00000011b ; bit 0 and 1 turn on speaker 
Period		= 4660 ; Period 
OneSec		= 32768		; change accroding to CPU speed
Term		= 4c00h 
DosInt		= 21h 

SSeg	segment stack 
	db 256 dup (?) 
SSeg	ends 
DSeg	segment 
sec	dw ? 
nsec	dw 25000 ; By experiment, 500* (50 * 32768) iterations 
				; make a 5ญsecond delay 
DSeg	ends 
CSeg	segment 
assume cs:CSeg, ds:DSeg, ss:SSeg 

start:	mov		ax, DSeg 
	mov		ds, ax 
	mov		al, 10110110b
	out		TimerMode,	al
	mov		ax,	Period		; set freq of timer 2
	out		Timer2,	al		; send byte
	mov		al,	ah
	out		Timer2,	al

	in		al, Port		; get port value
	or		al, on		; turn speaker off
	out		Port , al		; put it back to port


delay1:	mov		sec, OneSec		; delay loop
delay2:	sub		sec, 1
	jnz		delay2
	sub		nsec, 1
	jnz		delay1

	in		al, Port		; get port value
	and		al, NOT on		; turn speaker off
	out		Port , al		; put it back to port

; 
; (1) set timer mode 
; (2) set frequency 
; (3) turn on speaker 
; (4) delay loop 
; (5) turn off speaker 
; 
	mov		ax, Term ; return to DOS 
	int		DosInt 
CSeg ends 
end start 
;The I/O instruction groups, in, out, can be found in Table 4.19 in the 25ญpage manual, page 98. 
;
