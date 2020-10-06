.text
main:
# t0 <- x
# t1 <- y

#     int x, y;
#     printf("Enter a number: ");
    li $v0, 4
    la $a0, prompt
    syscall

#     scanf("%d", &x);
    li $v0, 5
    syscall
    # v0 now stores read value
    move $t0, $v0 # x <- read value

# //method 1
#     if (x > 46340) goto if1;
    li $t2, 46340
    bgt $t0, $t2, if1 
#     goto else1;
    j else1
if1:
#     printf("square too big for 32 bits\n");
    li $v0, 4
    li $a0, error_message
    syscall 
#     goto endif1;
    j endif1
else1:    
#     y = x * x;
    mul $t1, $t0, $t0
#   printf("%d\n", y);
    # print y
    li $v0, 1
    move $a0, $t1
    syscall

    # print new line
    li $v0, 11
    li $a0, '\n'
    syscall    
endif1: 

# //method 2
#     if (x <= 46340) goto else2;
# if2:
#         printf("square too big for 32 bits\n");
#         goto endif2;
# else2:
#         y = x * x;
#         printf("%d\n", y);
# endif2:    

#     return 0;

.data
prompt:
    .asciiz "Enter a number: "
error_message:
    .asciiz "square too big for 32 bits\n"