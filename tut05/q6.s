    .text

main:
# int main(void) {
#     int i; <- $t0
#     int numbers[10] = {0};

#     i = 0;
    li $t0, 0
#     while (i < 10) {
while1:
#     if (i >= 10) skip while loop content
    bge $t0, 10, endwhile1
#         printf("%d", &numbers[i]); 
                # *((address of numbers) + i * size of elements)
    # la $t1, numbers
    # mul $t3, $t0, 4 #  important! dont forget like me
    # add $t2, $t1, $t3
    # lw $a0, ($t2)

    # instead:
    mul $t3, $t0, 4
    lw $a0, numbers($t0)

    #printf("%d", numbers[i]);
    li $v0, 1
    # a0 already storing value above.
    syscall

#         i++;
    addi $t0, $t0, 1
#     }
endwhile1:
# }

    .data
numbers:
    .word 0 1 2 3 4 5 6 7 8 9 