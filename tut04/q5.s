.text
main:
    li $t0, 24      # int x = 42
    
while1: 
# if ( x >= 42) goto endwhile1; 
    bge $t0, 42, endwhile1
#     printf("%d\n",x);
    # print x
    li $v0, 1
    move $a0, $t0
    syscall

    # print new line
    li $v0, 11
    li $a0, '\n'
    syscall

#     x += 3; => x = x + 3
    addi $t0, $t0, 3
#     goto while1;
    j while1
endwhile1:    

.data