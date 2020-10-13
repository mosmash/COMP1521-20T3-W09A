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
#         scanf("%d", &numbers[i]); 
                # *((address of numbers) + i * size of elements)
    #scanf("%d");
    li $v0, 5
    syscall
    # after syscall, $v0 is storing our scanned value.
    # la $t1, numbers
    # mul $t3, $t0, 4 #  important! dont forget like me
    # add $t2, $t1, $t3
    # sw $v0, ($t2)

    # instead:
    mul $t3, $t0, 4
    sw $v0, numbers($t0)

#         i++;
    addi $t0, $t0, 1
#     }
endwhile1:
# }

    .data
numbers:
    .word 0 0 0 0 0 0 0 0 0 0 