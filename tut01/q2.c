int  a;
char b[100];

int fun1() {
    int c, d;
    // ...
}

double e;

int fun2() {
    int f = 0;
    static int ff = 22;
    // ...
    fun1();
    // ...
}

int g;

int main(void) {
    char h[10];
    int i;
    // ...
    fun2();
    // ...
}