#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

// this is another comment

int global=40;

void f1 (int p1, int p2) {
    global = 50;
    if (global > 50) {
        printf ("someting went wrong\n");
    } else {
        printf ("all good\n");
    }
    // = assigns
    // == equality?
    // >=, <=
    if (global == 1) {

    } else if (global == 2) {

    }
    switch (global) {
        case 1:
        break;
        case 2:
        break;
        case 50:
        printf ("all good since 50\n");
        break;
        case 51:
        printf ("bad since 51\n");
        break;
        default:
        break;
    }

    printf ("f1 %d\n", p1 + p2);
}

int f2 (int p1, int p2) {
    return p1 + p2 + global;
}

// p1,p2 are "passed by value"
// p1,p2 are "passed by reference"
void f3 (int p1, int p2, int p3, int *p4) {
    p3 = p1 + p2 + global;
    *p4 = p1 + p2;
}

unsigned char *read_file() {
    unsigned char *p;
    int fd = open ("tmp.txt", O_RDONLY);
    if (fd < 0) {
        printf ("Error from open!\n");
        return NULL;
    }
    struct stat fstat_info;
    int rc = fstat(fd, &fstat_info);
    if (rc < 0) {
        printf ("Error from fstat!\n");
        return NULL;
    }
    size_t size = fstat_info.st_size;
    printf ("file size = %zu\n", size);
    p = malloc (size);
    if (p != NULL) {
        read (fd, p, size);
    } else {
        printf ("failed malloc\n");
        return NULL;
    }
    printf ("Read %s from file\n", p);
    return p;
}

int main (int argc, char **argv) {
    char i;
    char *j;

    i = 200;
    printf ("i as signed = %hhd\n",i);
    printf ("i as unsigned = %hhu\n",i);

    read_file();
    return 0;
    i = 1;
    j = &i;

    f1(7,4);
    int r = f2(3,7);
    int r1=0,r2=0;
    printf ("f2 = %d\n", r);
    f3 (3,7,(int)&r1,&r2);
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

