#include"Árvore binária de busca.h"
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    BINARY_TREE_BUSCA tree;
    struct node * next;
}NODE;
typedef struct {
    NODE *firstNode;
    NODE *lastNode;
    int length;
}HEAD_NODE;
typedef HEAD_NODE *LINKED_LINE ;

void createLine(LINKED_LINE *line);
int lineIsEmpty(LINKED_LINE line);
void insertElementIntoLine(LINKED_LINE line, BINARY_TREE_BUSCA tree);
BINARY_TREE_BUSCA returnElementFromLine(LINKED_LINE line);
void deleteElementFromLine(LINKED_LINE line);
BINARY_TREE_BUSCA returnAndDeleteElementFromLine(LINKED_LINE line);
void destroyLine1(LINKED_LINE line);
void destroyLine2(LINKED_LINE line);
int lengthOfLine(LINKED_LINE line);
void printLine(LINKED_LINE line);


void createLine(LINKED_LINE *line) {
    (*line) = (HEAD_NODE *) malloc(sizeof(HEAD_NODE));
    if(!(*line)) {
        printf("\nNot storage enough\n\n");
        exit(1);
    }
    (*line)->firstNode = (*line)->lastNode = NULL;
    (*line)->length = 0;
}

int lineIsEmpty(LINKED_LINE line) {
    return (line->firstNode == NULL);
}

void insertElementIntoLine(LINKED_LINE line, BINARY_TREE_BUSCA tree) {
    NODE *alocado = (NODE *)malloc(sizeof(NODE));
    if(!alocado) {
        printf("\nNot storage enough\n\n");
        exit(1);
    }
    alocado->tree = tree;
    alocado->next = NULL;

    if(line->lastNode == NULL) {
        line->firstNode = alocado;
    } else  {
        line->lastNode->next = alocado;
    }
    line->lastNode = alocado;
    line->length++;
}

BINARY_TREE_BUSCA returnElementFromLine(LINKED_LINE line) {
    if(lineIsEmpty(line)) {
        printf("\nThe line is empty\n\n");
        exit(2);
    }
    return line->firstNode->tree;
}

void deleteElementFromLine(LINKED_LINE line) {
    if(lineIsEmpty(line)) {
        printf("\nThe line is empty\n\n");
        exit(2);
    } else {
        NODE *aux = line->firstNode;
        line->firstNode = line->firstNode->next;
        if(aux == line->lastNode)
            line->lastNode = line->firstNode;
        free(aux);
    }
    line->length--;
}

BINARY_TREE_BUSCA returnAndDeleteElementFromLine(LINKED_LINE line) {
    BINARY_TREE_BUSCA value;
    if(lineIsEmpty(line)) {
        printf("\nThe line is empty\n\n");
        exit(2);
    } else {
        value = line->firstNode->tree;
        NODE *aux = line->firstNode;
        line->firstNode = line->firstNode->next;
        if(aux == line->lastNode)
            line->lastNode = line->firstNode;
        free(aux);
    }
    line->length--;
    return value;
}

void destroyLine1(LINKED_LINE line) {
    if(!line->firstNode) {
        printf("\nThe line is empty\n\n");
        return;
    } else {
        line->lastNode = line->firstNode;
        while(line->lastNode) {
            line->firstNode = line->lastNode->next;
            free(line->lastNode);
            line->lastNode = line->firstNode;
        }
        free(line);
    }
}

void destroyLine2(LINKED_LINE line) {
    if(!line->firstNode) {
        printf("\nThe line is empty\n\n");
        exit(2);
    } else {
        NODE *aux = line->firstNode;
        while(aux) {
            line->firstNode = aux->next;
            free(aux);
            aux = line->firstNode;
        }
        free(line);
    }
}

int lengthOfLine(LINKED_LINE line) {
    return line->length;
}

void printLine(LINKED_LINE line) {
    NODE *aux;
    for(aux = line->firstNode; aux; aux = aux->next) {
        printf("%d...", aux->tree->value);
    }
    printf("\n\n");
}
