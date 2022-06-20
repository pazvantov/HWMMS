#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define COUNT 10

typedef struct 
{
    char Title[151];
    char Author[101];
    int Pages;
    double Price;
}Book;

typedef struct node
{
    Book data;
    struct node* next;
}node_t;

void push(node_t** list, Book data);
void print_listR(node_t* list);

int main(int argc, char** argv)
{
    node_t *head = NULL;
    char input[20];
    strcpy(input,argv[1]);
    char output[20];
    strcpy(output,argv[2]);
    FILE *inputFptr;
    inputFptr = fopen(input,"rb");
    Book data;
    while(!feof(inputFptr))
    {
        fread(&data, sizeof(Book),1,inputFptr);
        push(&head,data);
    }
    fclose(inputFptr);
    print_listR(head);
    return 0;
}

void push(node_t** list, Book data){
    node_t* n = malloc(sizeof(node_t));
    strcpy(n->data.Author,data.Author);
    strcpy(n->data.Title,data.Title);
    n->data.Pages = data.Pages;
    n->data.Price = data.Price;
    n->next = *list;
    *list = n;
}

void print_listR(node_t* list){
    if (list == NULL){
        return;
    }
    printf("%20s %20s %5d %5.2lf\n ", list->data.Author, list->data.Title,
                                        list->data.Pages,list->data.Price);
    print_listR(list->next);
}