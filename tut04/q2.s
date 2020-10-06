.text

# int main(void) {
main:
#     int x, y;
#     x -> $t0
#     y -> $t1
#     printf("Enter a number: ");
    li $v0, 4       # $v0 <- 4
    la $a0, prompt  # $a0 <- address of string
    syscall

#     scanf("%d", &x);
    li $v0, 5       # $v0 <- 5
    syscall
    # now $v0 should have our result from scanf

    move $t0, $v0   # $t0 <- $v0
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

#     return 0;
    li $v0, 0
    jr $ra
# }

.data
prompt:
    .asciiz "Enter a number: "