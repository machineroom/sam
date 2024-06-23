#include <stdio.h>
// this is another comment

int global=40;

void f1 (int p1, int p2) {
    global = 50;
    printf ("f1 %d\n", p1 + p2);
}

int f2 (int p1, int p2) {
    return p1 + p2 + global;
}

void f3 (int p1, int p2, int *p3, int *p4) {
    *p3 = p1 + p2 + global;
    *p4 = p1 + p2;
}

int main (int argc, char **argv) {
    char i;
    char *j;

    i = 1;
    j = &i;

    f1(7,4);
    int r = f2(3,7);
    int r1,r2;
    printf ("f2 = %d\n", r);
    f3 (3,7,&r1,&r2);
    printf ("f3 = %d %d\n", r1,r2);

    char ***stupid = &argv;

    
    char *astring;  // a pointer
    
    astring = "some string";

    printf ("args %d %s %s %s\n", argc, argv[0], argv[1], argv[2]);
    printf ("args %d %s %s %s\n", argc, *argv, *(argv+1), *(argv+2));
    printf ("args %d %c\n", argc, ***stupid);

    printf ("%d\n", i);
    printf ("%d\n", *j);
    printf ("%d\n", &i);
    printf ("%d\n", j);
    printf ("%d\n", &j);

    printf ("Hello sam %s \n", astring);

    astring = "that string";

    printf ("Hello sam %c%c%c%c\n", astring[0], astring[1], astring[2], astring[3]);

    printf ("Hello sam %c%c%c%c\n", *astring, *(astring+1), *(astring+2), *(astring+3));

    return 0;
}

