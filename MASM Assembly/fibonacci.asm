TITLE Fibonacci Sequence Printer(fibonacci.asm)

; Author: Ryan Cosby
; Course / Project ID                 Date : 07 / 01 / 2015
; Description: An iterative fibonacci sequence program that will print
; each of the fibonacci terms up to the number of terms specified by the
; user.The user is only allow to enter a term in the range 1 to 46

INCLUDE Irvine32.inc

LOWERLIMIT = 1
UPPERLIMIT = 46

.data

intro1	BYTE	"Fibonacci Sequence Printer: by Ryan Cosby", 0
intro2	BYTE	"Nice to meet you, what's your name? ", 0
userName	BYTE	33 DUP(0); The name of the user
intro3	BYTE	"Welcome! ", 0
instr1	BYTE	"Please enter a the number of Fibonacci Terms to print (1 - 46): ", 0
error1	BYTE "ERROR: This program can only print the Fibonacci Terms in the range of 1 - 46", 0
termSeparator	BYTE	"     ", 0
fibTerm	DWORD ?
fibSum	DWORD ?
fib1stTerm	DWORD ?
fibCount	DWORD ?
byeStatement	BYTE	"Thanks for using the Fibonacci Printer! You are awesome! Goodbye, ", 0

.code
main PROC
; Introduction
	mov	edx, OFFSET intro1			;
	call WriteString				; Print the introductory statement
	call	CrLf						; Print a new line

; Gather User Name
	mov	edx, OFFSET intro2			; 
	call WriteString				; Print the second second of introduction
	mov		edx, OFFSET userName	; 
	mov		ecx, 32				; 
	call	ReadString				; Gather user user inputted name

	mov	edx, OFFSET intro3			; 
	call WriteString				; 
	mov	edx, OFFSET userName		;
	call WriteString				; Say hello to user by inputted name
	call CrLf						; Print new line
	
; User Instructions and Fibonacci Term Input
	input :
	mov	edx, OFFSET instr1			; Prompt user to input number of Fibonacci terms
	call WriteString				; 
	call	ReadInt					; Read the user input
	mov	fibTerm, eax				; Store user input in variable

; Validate User Input
	mov	eax, fibTerm				; Move user input to register
	cmp	eax, LOWERLIMIT			; compare user input to the LOWERLIMIT constant of 1
	jl	falseBlock				; if the user input is less than 1 execute the false block
	cmp	eax, UPPERLIMIT			; otherwise compare the user input to the UPPERLIMIT constant of 46
	jg	falseBlock				; if the user input is greater than 46 then execute the false block
	jmp	endBlock					; if the user passes both validations then jump to the end
	falseBlock :
	call CrLf						; Add extra line before error message
	mov	edx, OFFSET error1			; print the error that range must be within 1 to 46
	call WriteString				;
	call	CrLf						;
	jmp input						; jump back to the input block to ask for new number
	endBlock :


; Display Fibonacci Numbers
	
	mov	eax, 0					; Initialize First Term
	mov	fibCount, eax				; Initialize the fibonacci term count for printer	
	mov	ebx, 1					; Initialize Second Term
	mov	ecx, fibTerm				; Add previous user input to control the loop count
	top :
	add	eax, ebx					; Sum the previous two terms of the Fibonacci Sequence	
	mov	fibSum, eax				; Store the sum in a variable
	mov	eax, ebx					; Shift the position of the terms after the sum has been completed
	mov	ebx, fibSum				; Move the Sum into the second terms position to prepare it for the next sum
	mov	fib1stTerm, eax			; Save the value of the first term
	mov	eax, fibCount				; Move the fibCount variable into the register
	inc	fibCount					; Increment the fibCount variable
	mov	ebx, 5					; Move 5 into the divisor position of the register
	mov	edx, 0					; Clear the EDX register
	div	ebx						; Divide the Count by 5 to determine if an extra line should be printed
	cmp	edx, 0					; Check to see if there is a value in the remainder
	jne	printBlock				; when there is no value in the remainder print an extra line
	call CrLf						; Print extra line
	printBlock :
	mov	eax, fib1stTerm			; Restore the first term
	mov	ebx, fibSum				; Restore the second term
	call WriteDec					; Print the EAX register
	mov	edx, 0					; Clear the EDX register	
	mov	edx, OFFSET termSeparator	; Add extra spaces in between Fibonacci terms
	call WriteString				; Print the extra spaces
	loop	top						; For loop counter

	

; Goodbye to the user
	call CrLf						;
	call CrLf						;
	mov	edx, OFFSET byeStatement		; Print the goodbye statement
	call Writestring				;
	mov	edx, OFFSET userName		; 
	call WriteString				; Print the user name in the goodbye statement
	call CrLf						;
	exit							; exit to operating system
main ENDP

END main