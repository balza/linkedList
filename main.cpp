#include <stdio.h>
#include <stdlib.h>

/**
Esercizio sulle linked list
addFirst: aggiunge un elemento alla prima posizione di una linked list creando (malloc) un nuovo elemento
addFirst2: aggiunge un elemento alla prima posizione della lista sostituendo i puntatori
*/

typedef struct alunno {
    char nome[20];
    char cognome[20];
    int matricola;
} Alunno;

typedef struct nodo {
    Alunno datiAlunno;
    struct nodo *nextNodo;
} Nodo;

Nodo addFirst2(Nodo *head, Nodo *nuovoElemento) {
    nuovoElemento -> nextNodo = head;
    return *nuovoElemento;
}

Nodo addFirst(Nodo *head, Nodo *nuovoElemento) {
    Nodo *tmp = (Nodo *)(malloc(sizeof(Nodo)));
    tmp->datiAlunno.matricola = nuovoElemento->datiAlunno.matricola;
    tmp->nextNodo = head;
    return *tmp;
}

void printList(Nodo *head) {
    Nodo *cursore = head;
    while (cursore != NULL) {
        printf("%d\n", cursore->datiAlunno.matricola);
        cursore = cursore->nextNodo;
    }
}

int main() {
    Nodo nodo1 = {"pino", "rossi", 456, NULL};
    Nodo nodo2 = {"giorgio", "chinotti", 123, NULL};
    Nodo head = addFirst2(&nodo1, &nodo2);
    printList(&head);

    return 0;
}