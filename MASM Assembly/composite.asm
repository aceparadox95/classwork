TITLE Composite Number Printer(fibonacci.asm)

; Author: Ryan Cosby
; CS 271 / Project 3                 Date : 07 / 23 / 2015
; Description: A nested loop program that will print
; each of the composite numbers up to the number of terms specified by the
; user.The user is only allow to enter a term in the range 1 to 400

INCLUDE Irvine32.inc

LOWERLIMIT = 1
UPPERLIMIT = 400

.data
intro1	BYTE	"Composite Number Printer: by Ryan Cosby", 0
instr1	BYTE	"Please enter the number of composite numbers to print (1 - 400): ", 0
error1	BYTE "ERROR: This program can only print in the range of 1 to 400 composite numbers", 0
termSeparator	BYTE	"   ", 0
compTerm	DWORD ?
composite DWORD 4
compBool	DWORD ?
totComps  DWORD 0
tempDivisor	DWORD	?
byeStatement	BYTE	"Thanks for using the Composite Number Printer! You are awesome! Goodbye, ", 0
.code
main PROC
	call intro
	call	gatherInput
	call printComps
	call goodbye

	exit													; exit to operating system
main ENDP

; Procedure to introduce the composite number program
; receives: none
; returns: none
; preconditions:  none
; registers changed : edx
intro	PROC

; Introduction
	mov	edx, OFFSET intro1;
	call WriteString										; Print the introductory statement
	call	CrLf												; Print a new line
	ret
intro	ENDP

; Procedure to get number of composite terms to print from the user
; receives: none
; returns: user input value for number of terms to print
; preconditions:  none
; registers changed : eax, edx

gatherInput	PROC

; User Instructions and User Input
	mov	edx, OFFSET instr1									; Prompt user to input number of composite numbers to print
	call WriteString;
	call	ReadInt											; Read the user input
	mov	compTerm, eax; Store user input in variable
	call validate
	ret
gatherInput	ENDP

; Sub Procedure to validate the user input value
; receives: user inputted value
; returns: none
; preconditions:  value has been inputted
; registers changed : eax, edx

validate	PROC

; Validate User Input
	mov	eax, compTerm										; Move user input to register
	cmp	eax, LOWERLIMIT									; compare user input to the LOWERLIMIT constant of 1
	jl	falseBlock										; if the user input is less than 1 execute the false block
	cmp	eax, UPPERLIMIT									; otherwise compare the user input to the UPPERLIMIT constant of 400
	jg	falseBlock										; if the user input is greater than 400 then execute the false block
	jmp	endBlock											; if the user passes both validations then jump to the end
	falseBlock :
	call CrLf												; Add extra line before error message
	mov	edx, OFFSET error1									; print the error that range must be within 1 to 400
	call WriteString										
	call	CrLf
	call gatherInput										; jump back to the input procedure to ask for new number
endBlock :
	ret
validate	ENDP

; Procedure to print composite numbers
; receives: valid input value
; returns: none
; preconditions:  value has passed validation process
; registers changed : eax, ebx, ecx, edx

printComps	PROC
	call CrLf												; Add space after intro statement
	mov ecx, compTerm										; Initialize the loop counter at the suer inputted value
	printLoop:
		mov	compBool, 0									; Initialize the composite boolean to false
		call isComp										; Check to see if the value is composite
		cmp compBool, 1									; If it is then
		je printComp										; Print the composite number
		inc composite										; Otherwise increment the composite number to test next value
	printComp:
		inc	totComps										; Keep track of number of composite numbers printed so far
		mov eax, 0										; Clear the EAX Register
		mov eax, composite									; Set the EAX regsiter equal to the composite number	
		call	WriteDec										; Print the composite number
		mov	edx, 00000000h									; Clear the EDX register		
		mov	edx, OFFSET termSeparator						; Add extra spaces in between Composite Numbers
		call WriteString									; Print the extra spaces
		inc	composite										; Increment the composite number
		mov	tempDivisor, ebx								; Temporarily Store the Divisor from the EBX register (set during the isComp procedure)
		mov	edx, 00000000h									; Clear the EDX register
		mov	eax, totComps									; Move total composite count number to EAX register for division
		mov  ebx, 10										; Use 10 as the divisor
		div	ebx											; Divide the Total Composite Number Count by 10 to check for new line
		mov	ebx, tempDivisor								; Restore the divsor from the IsComp procedure
		cmp	edx, 0										; If remainder is 0 then
		jne	noNewLine										; Dont print a new line
		call CrLf											; Otherwise print a new line
	noNewLine:
		loop printLoop										; Decrement the loop counter
		call CrLf											; Print a new line after all composite numbers have been printed
		ret
printComps	ENDP

; Sub Procedure to check if number is composite
; receives: integer starting at 4
; returns: set the compBool to true or false
; preconditions:  none
; registers changed : eax, ebx, edx

isComp	PROC
	mov	edx, 00000000h										; Clear the EDX register
	mov	eax, composite										; Move the composite number to the EAX register
	mov	ebx, 2											; Start the divisor at 2								
	div	ebx												; Divide the values
	cmp	edx, 0											; If remainder is 0 then its a composite number
	je	setComp											; Jump to set the composite boolean to true
	inc	ebx												; Otherwise increment the divisor by 1 to 3	
	divLoop:
		mov	edx, 00000000h									; Clear the EDX Register
		mov	eax, 00000000h									; Clear the EAX Register
		cmp	ebx, composite									; Compare the divisor to the term	
		je setNotComp										; If they are the same that means its a prime number
		mov	eax, composite									; Otherwise divide and test the remainder to see if its zero
		div	ebx											;
		cmp  edx, 0										;
		je setComp										; If its zero then set the composite boolean to zero
		add	ebx, 2										; Otherwise increase the divisor from 3 to 5, to 7, to 9 and so forth
		jmp	divLoop										; Repeat the loop if it reaches this point
	setComp:
		mov compBool, 1									; Sets the boolean to true
		jmp done											; jump to done if true
	setNotComp:
		mov compBool, 0									; Sets boolean to false
	done:
	ret
isComp	ENDP

; Procedure to say goodbye to user
; receives: none
; returns: none
; preconditions:  all other procedures need to have executed
; registers changed : edx

goodbye	PROC

; Goodbye to the user
	call CrLf;
	call CrLf;
	mov	edx, OFFSET byeStatement								; Print the goodbye statement
	call Writestring;
	call CrLf
	ret
goodbye	ENDP

END main