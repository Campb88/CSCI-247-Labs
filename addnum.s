		.global main

	.text

main:
		// write
		mov 	$1, %rax 		# system call for write
		mov 	$1, %rdi 		# file handle 1 is stdout
		mov 	$message, %rsi 	# address of string to output
		mov 	$23, %rdx 		# number of bytes
		syscall 				# invoke operating system to do the write


		// read
		mov 	$0, %rax 		# system call for read
		mov 	$0, %rdi 		# file handle 0 is stdin
		mov 	$buff, %rsi 	# add to buff
		syscall 				# invoke operating system to do the write

        
        // atoi
        push    %r8
        mov     $buff, %rdi
        call    atoi
        mov     %rax, %r8



		// write
		mov 	$1, %rax 		# system call for write
		mov 	$1, %rdi 		# file handle 1 is stdout
		mov 	$message, %rsi 	# address of string to output
		mov 	$23, %rdx 		# number of bytes
		syscall 				# invoke operating system to do the write


        // read
		mov 	$0, %rax 		# system call for read
		mov 	$0, %rdi 		# file handle 0 is stdin
		mov 	$buff2, %rsi 	# add to buff
		syscall 				# invoke operating system to do the write 

        // atoi
        mov     $buff2, %rdi
        call    atoi
        mov     %rax, %r9
        push    %r9

        add     %r9, %r8

        
        // write
		mov 	$1, %rax 		# system call for write
		mov 	$1, %rdi 		# file handle 1 is stdout
		mov 	$sum, %rsi 		# address of string to output
		mov 	$15, %rdx 		# number of bytes
		syscall 				# invoke operating system to do the write

		// exit
		mov 	$60, %rax 		# system call for exit
		mov 	$0, %rdi 		# exit code 0
		syscall


	.data

message:
        .asciz  "Please enter a number: "

sum:	
		.asciz	"The sum is: "

buff:   .zero 100

buff2:   .zero 100

