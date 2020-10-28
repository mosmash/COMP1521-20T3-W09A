#NOTE THIS WONT RUN ITS MISSING A MAIN FUNCTION
    .text

max:
# int max(int a[], int length) {
# a[] -> $a0
# length -> $a1

# variables
# s0 <- first_element
# t0 <- max_so_far
max_prologue:
    # Save $s0
    addi    $sp, $sp, -4
    sw      $s0, ($sp)
    # Save $ra
    addi    $sp, $sp, -4
    sw      $ra, ($sp)



#     int first_element = a[0];
    move    $s0, $a0
# old    if (length == 1) {
max_if1:
#   if (length != 1) then skip over if statement to else statement
    bne $a1, 1, max_elseif1
#         return first_element;
    move $v0, $s0
    j   max_epilogue


#     } else {
max_elseif1:
#         // find max value in rest of array
#         int max_so_far = max(&a[1], length - 1);
    addi $a0, $a0, 4    # add on the size of int (element of a) to get to next pos.
    addi $a1, $a1, -1
    jal max # function call
    move $t0, $v0 # max_so_far = ...


#   old      if (first_element > max_so_far) {
#   if (first_element <= max_so_far) then jump to end of if statement
max_if2:
#             max_so_far = first_element;
    move $t0, $s0
#         }
max_endif2:

#         return max_so_far;
    move $v0, $t0
    j max_epilogue
#     }
max_endif1:

# }
max_epilogue:
    lw      $ra, ($sp)
    addi    $sp, $sp, 4
    lw      $s0, ($sp)
    addi    $sp, $sp, 4

max_end:
    jr      $ra

    .data
random_array:
    .word   -1, 4, 23, 2 