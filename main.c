#include <stdio.h>

struct node {
    struct node * parent;
    struct node * child;
    struct node * sibling;
};

struct node * add_node(char * data, struct node * parentnode)
{
    // stub
    return NULL;
}

int main(int argc, char *argv[])
{

    char ch;
    FILE * fp = fopen(argv[1], "r");

    for(struct node * cur = NULL; (ch = getc(fp)) != EOF;)
    {
        printf("%c", ch);
        // if char is '<'
            // create new child node and enter
    }
    printf("\n");

    return 0;
}
