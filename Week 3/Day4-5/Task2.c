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
void mergeSort(node_t** list);
void frontBackSplit(node_t* list, node_t** front, node_t** back);
node_t* sortedMerge(node_t* listA, node_t* listB);

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
    mergeSort(&head);
    FILE* outputFptr = fopen(output,"w");
    node_t* temp = head;
    while(temp != NULL)
    {
        fprintf(outputFptr,"%20s %20s %5d %5.2lf\n ",
            temp->data.Author, temp->data.Title,
            temp->data.Pages,temp->data.Price);
            temp = temp->next;
    }
    fclose(outputFptr);
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

// merge sort
node_t* sortedMerge(node_t* listA, node_t* listB){
    node_t* sorted = NULL;
    if (listA == NULL){
        return listB;
    }
    if (listB == NULL){
        return listA;
    }
    if (strcmp(listB->data.Author,listA->data.Author) > 0){
        sorted = listA;
        sorted->next = sortedMerge(listA->next, listB);
    } else {
        sorted = listB;
        sorted->next = sortedMerge(listA, listB->next);
    }
    return sorted;
}

void frontBackSplit(node_t* list, node_t** front, node_t** back){
    node_t* slow = list;
    node_t* fast = list->next;
    while (fast != NULL){
        fast = fast->next;
        if (fast  != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = list;
    *back = slow->next;
    slow->next = NULL;
}

void mergeSort(node_t** list){
    if (*list == NULL || (*list)->next == NULL){
        return;
    }
    node_t *front = NULL, *back = NULL;
    frontBackSplit(*list, &front, &back);
    mergeSort(&front);
    mergeSort(&back);
    *list = sortedMerge(front, back);
}