
int main(void) {
    int a = 10;
    int b = 0;
    int i;

    for (i = 0; i < a; i += 1) {
        if( i % 2 == 0) {
            b += 1;
        }
    }

    a += 2;

    return a;
}