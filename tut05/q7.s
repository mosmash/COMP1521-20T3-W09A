# int main(void) {
    .text
main:
#     int i;
#     int numbers[10] = {0,1,2,-3,4,-5,6,-7,8,9};

#     i = 0;
    li $t0, 0
#     while (i < 10) {
while2:
#     if (i >= 10) skip while loop content
    bge $t0, 10, endwhile2
#         if (numbers[i] < 0) {
#         if (numbers[i] >= 0) {
if1:
    mul $t3, $t0, 4 
    lw $t4, numbers($t0)
    # bge $t4, 0, endif1
    bgez $t4, endif1

#             numbers[i] += 42; => numbers[i] = numbers[i] + 42
    addi $t5, $t4, 42
    sw $t5, numbers($t0)
#         }
endif1:
#         i++;
    addi $t0, $t0, 1
#     }
endwhile2:
# }

    .data
numbers:
#     int numbers[10] = {0,1,2,-3,4,-5,6,-7,8,9};
    .word 0 1 2 -3 4 -5 6 -7 8 9