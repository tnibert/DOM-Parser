#include <stdio.h>
#include <stdlib.h>

/*
compile with gcc main.c
run with ./a.out htmlfile.html
*/

struct node {
    struct node * parent;
    struct node * firstchild;
    struct node * nextsibling;  // hmm...

    char * tag;
    char * data;
    // we will later include options, e.g. href=, id=, etc
};

struct node * add_node(char * tag, char * data, struct node * parentnode)
{
    struct node * newnode = malloc(sizeof(struct node));
    newnode->parent = parentnode;

    if(parentnode != NULL)
    {
        if(parentnode->firstchild == NULL)
        {
            parentnode->firstchild = newnode;
        }
        else
        {
            // iterate through until we have the last sibling
            struct node * lastsibling;
            for(lastsibling = parentnode->firstchild; lastsibling->nextsibling != NULL; lastsibling = lastsibling->nextsibling);
            lastsibling->nextsibling = newnode;
            // you know, we probably could have done it backward and just traversed the tree backward and everything would have been fine...
            // eg, store lastchild and prevsibling in node struct
        }
    }
    else        // if we are the root node
    {
        // newnode->parent is already NULL
        newnode->nextsibling = NULL;
    }

    // set child to NULL
    // maybe we can build this from the deepest level though, just for fun, something to think about
    newnode->firstchild = NULL;

    // set xml data
    newnode->tag = tag;
    newnode->data = data;

    return newnode;
}

// use this to test the add_node() function
char * node_to_str(struct node * curnode)
{
    return "This function is still a stub";
}

void traverse(struct node * root)
{
    return;
}

int main(int argc, char *argv[])
{

    if(argc < 2)
    {
        printf("Must specify html/xml file as command line argument.\n");
        return -1;
    }

    char ch;
    FILE * fp = fopen(argv[1], "r");        // should probably error check this too

    for(struct node * cur = NULL; (ch = getc(fp)) != EOF;)
    {
        printf("%c", ch);
        // if char is '<'
            // create new child node and enter
    }
    printf("\n");

    // test
    struct node * testheadnode = add_node("html", "test data", NULL);
    struct node * testchildnode = add_node("head", "more test data", testheadnode);

    return 0;
}
