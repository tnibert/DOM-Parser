#include <stdio.h>
#include <stdlib.h>

/*
compile with gcc main.c
run with ./a.out htmlfile.html
*/

struct node {
    struct node * parent;
    struct node * child;
    struct node * nextsibling;  // we only need to hold a reference to next sibling,
                                // and we only need to reference first child
    char * tag;
    char * data;
    // we will later include options, e.g. href=, id=, etc
};

struct node * add_node(char * data, struct node * parentnode)
{
    struct node * newnode = malloc(sizeof(struct node));
    return newnode;
}

int main(int argc, char *argv[])
{

    if(argc < 2)
    {
        printf("Must specify html/xml file as command line argument.\n");
        return -1;
    }

    char ch;
    FILE * fp = fopen(argv[1], "r");

    for(struct node * cur = NULL; (ch = getc(fp)) != EOF;)
    {
        printf("%c", ch);
        // if char is '<'
            // create new child node and enter
    }
    printf("\n");

    // test
    struct node * testnode = add_node("test data", NULL);

    return 0;
}
