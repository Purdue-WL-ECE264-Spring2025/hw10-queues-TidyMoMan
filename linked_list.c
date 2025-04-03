#include "linked_list.h"

#include <stdlib.h>

struct list_node* new_node(size_t value) {
  struct list_node* newNode = malloc(sizeof(struct list_node*));
  newNode->next = NULL;
  newNode->value = value;
  return newNode;
}

void insert_at_head(struct linked_list *list, size_t value) {
  struct list_node* newNode = new_node(value); //create a new node with value set
  //does head->next exist???
  newNode = list->head;
  list->head = newNode;
}

void insert_at_tail(struct linked_list *list, size_t value) {
  struct list_node* tempHead = list->head;

  while(tempHead->next != NULL){ //go until the next node is null, meaning we have reached the end of the list
    tempHead = tempHead->next;
  }

  tempHead->next = new_node(value); //make a new node at the end of the list.
}

size_t remove_from_head(struct linked_list *list) {
  struct list_node* toDelete = list->head;
  list->head = list->head->next;
  free(toDelete);
  return 0;
}

size_t remove_from_tail(struct linked_list *list) {
  struct list_node* tempHead = list->head;

  while(tempHead->next != NULL){ //go until the next node is null, meaning we have reached the end of the list
    tempHead = tempHead->next;
  }
 
  free(tempHead->next);
  return 0;
}

void free_list(struct linked_list list) {
  while(list.head->next != NULL){
    list.head = list.head->next;
    remove_from_head(&list); //set list to itself without the first node!
  }
}

// Utility function to help you when debugging, do not modify
void dump_list(FILE *fp, struct linked_list list) {
  fprintf(fp, "[ ");
  for (struct list_node *cur = list.head; cur != NULL; cur = cur->next){
    fprintf(fp, "%zu ", cur->value);
  }
  fprintf(fp, "]\n");
}
