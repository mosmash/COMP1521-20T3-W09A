    .text
main:
    #old  for (int row = 0; row < 6; row++) {
    # int row = 0;
    li  $t0, 0
    # while (row < 6) {
    # inverted: if (row >= 6) goto end of loop 1
loop1:
    bge $t0, 6, endloop1


    #old     for (int col = 0; col < 12; col++) {
    # int col = 0;
    li  $t1, 0
    # while (col < 12) {
    # inverted: if (col >= 12) goto end of loop 2
loop2:
    bge $t1, 12, endloop2 
    #         printf ("%c", flag[row][col]);

    # get flag[row][col]
    la $t2, flag

    #row size
    li $t3, 12 # length of row
    mul $t3, t3, 1 # * size of each element

    # get nth row
    mul $t3, $t3, $t0

    # get to column
    # col * element size
    mul $t4, $t1, 1

    add $t4, $t4, $t3 # actual array pos [row][col]

    add $t4, $t4, $t2 # actual memory address

    # load straight into $a0 since we're only using it to print
    li $v0, 1
    lb $a0, ($t4)
    syscall

    # col++
    addi $t1, $t1, 1
    b loop2
    #     }
endloop2:

    #     printf ("\n");
    li $a0, '\n'
    li $v0, 11
    syscall

    # row++
    addi $t0, $t0, 1
    b loop1
    # }
endloop1:

    .data
flag:   .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#' '#' '#'        
        .byte '.', '#', '#', '#', '#', '.', '.', '#', '#', '#' '#' '#'    
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#' '#' '#'    
        .byte '.', '#', '#', '#', '#', '.', '.', '#', '#', '#' '#' '#'    
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#' '#' '#'    
        .byte '.', '#', '#', '#', '#', '.', '.', '#', '#', '#' '#' '#'    
