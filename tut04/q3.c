
int main(void) {
    int x, y;
    printf("Enter a number: ");
    scanf("%d", &x);

    if (x > 46340) {
        printf("square too big for 32 bits\n");
    } else {
        y = x * x;
        printf("%d\n", y);
    }

    return 0;
}

// modified
int main(void) {

    int x, y;
    printf("Enter a number: ");
    scanf("%d", &x);

//method 1
    if (x > 46340) goto if1;
    goto else1;
if1:
    printf("square too big for 32 bits\n");
    goto endif1;
else1:    
    y = x * x;
    printf("%d\n", y);
endif1: 

//method 2
    if (x <= 46340) goto else2;
if2:
        printf("square too big for 32 bits\n");
        goto endif2;
else2:
        y = x * x;
        printf("%d\n", y);
endif2:    

    return 0;
}