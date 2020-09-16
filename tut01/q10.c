#include <stdio.h>


void print_num(int index, int nums[]) {
    if (index >= 10) {
        return; // base case
    }
    
    printf("%d\n", nums[index]);
    index++; // state change


    // recursion
    return print_num(index, nums);

}


int main(void)
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


    print_num(0,nums);

    return 0;
}