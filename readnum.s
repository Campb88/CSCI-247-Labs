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
		mov 	$0, %rdi 		# file handle 1 is stdin
		mov 	$buff, %rsi 	# add to buff
		syscall 				# invoke operating system to do the write

		
		// write
		mov 	$1, %rax 		# system call for write
		mov 	$1, %rdi 		# file handle 1 is stdout
		mov 	$num, %rsi 		# address of string to output
		mov 	$25, %rdx 		# number of bytes
		syscall 				# invoke operating system to do the write

		// exit
		mov 	$60, %rax 		# system call for exit
		mov 	$0, %rdi 		# exit code 0
		syscall


	.data

message:
        .asciz  "Please enter a number: "

num:	
		.asciz	"You have entered: "

buff:   .zero 100


