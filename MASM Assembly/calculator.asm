TITLE Simple Calculator(calculator.asm)

; Author: Ryan Cosby
; Course / Project ID : Program1                 Date : 06 / 27 / 2015
; Description: A basic MASM program to perform the following tasks, displaying name
; and program title on the output screen, displaying instructions for the user,
; prompting the user to enter two numbers, calculate the sum, difference, product, and
; quotient / remainder of the numbers, and then display an ending message.

INCLUDE Irvine32.inc


.data
introStatement1	BYTE	"Simple Calculator: by Ryan Cosby", 0
instrStatement1	BYTE	"Please enter two integer values, then the sum, difference, product,", 0
instrStatement2	BYTE	"and quotient with its remainder will be displayed", 0
prompt1	BYTE	"Enter First Number: ", 0
prompt2	BYTE	"Enter Second Number: ", 0
opNum1	DWORD ?
opNum2	DWORD ?
sum		DWORD ?
differ	DWORD ?
product	DWORD ?
quotient	DWORD ?
remainder	DWORD ?
viewSum	BYTE	"Sum: ", 0
viewDiff	BYTE	"Difference: ", 0
viewProd	BYTE	"Product: ", 0
viewDiv	BYTE	"Quotient: ", 0
viewRem	BYTE	" Remainder: ", 0
byeStatement	BYTE	"Thanks for using the simple calculator! You are awesome! Goodbye.", 0


.code
main PROC

; Introduction and Instructions
	mov	edx, OFFSET introStatement1
	call WriteString				; Print the introduction statement
	call CrLf
	mov	edx, OFFSET instrStatement1	; Print the Instructions
	call WriteString
	call CrLf
	mov	edx, OFFSET instrStatement2	; Print the second line of Instructions
	call WriteString
	call CrLf
	call CrLf

; User Input
	mov		edx, OFFSET prompt1
	call	WriteString
	call	ReadInt					; Prompt the user for the first integer
	mov		opNum1, eax			; Store user reponse in variable
	mov		edx, OFFSET prompt2
	call	WriteString
	call	ReadInt					; Prompt the user for the second integer
	mov		opNum2, eax			; Store the user response in a variable

; Calculate Variables(Add, Subtract, Multiply, Divide)

	mov	eax, opNum1	; Move the first operand of the sum calculation to memory
	add	eax, opNum2	; Adding the second operand of the sum calculation to memory
	mov	sum, eax		; Storing the results of the sum operation

	mov	eax, opNum1	; Move the first operand of the difference calculation to memory
	sub	eax, opNum2	; Substracting the second operand of difference calculation to memory
	mov	differ, eax	; Storing the results of the subtraction calculation

	mov	eax, opNum1	; Move the first operand of the multiplication calculation to memory
	mov	ebx,	opNum2	; Move the second operand of the multiplication calculation to second memory
	mul	ebx			; Multiply the two operands
	mov	product, eax	; Storing the results of the multiply operation

	mov	eax, opNum1	; Move the dividend of the division calculation to memory
	mov	ebx, opNum2	; Move the divisor of the division calculation to memory
	div	ebx			; Divide the dividend with the divisor
	mov	quotient, eax	; Store the results of the divide operation
	mov	remainder, edx	; Store the remainder from the divide operation which is always in the EDX register after the operation is executed

; Display Calculation Results

	call CrLf
	mov		edx, OFFSET viewSum
	call	WriteString		; Display the "Sum: " header
	mov		eax, sum		; Bring the stored sum variable into the register
	call	WriteDec			; Print the stored sum variable after the header	
	call	CrLf

	mov		edx, OFFSET viewDiff
	call	WriteString		; Display the "Difference: " header
	mov		eax, differ	; Bring the stored difference variable into the register
	call	WriteDec			; Print the stored difference variable after the header
	call	CrLf

	mov		edx, OFFSET viewProd
	call	WriteString		; Display the "Product: " header
	mov		eax, product	; Bring the stored product variable into the register
	call	WriteDec			; Print the stored product variable after the header
	call	CrLf

	mov		edx, OFFSET viewDiv
	call	WriteString		; Display the "Quotient: " header
	mov		eax, quotient	; Bring the stored quotient variable into the register
	call	WriteDec			; Print the stored quotient variable after the header
	mov		edx, OFFSET viewRem
	call	WriteString		; Display the "Remainder: " header
	mov		eax, remainder	; Bring the stored remainder variable into the register
	call	WriteDec			; Print the stored remainder variable after the header
	call	CrLf

; Say Goodbye
	call CrLf
	mov	edx, OFFSET byeStatement
	call WriteString		;Say Goodbye to the User!
	call CrLf

	exit	; exit to operating system
main ENDP

END main