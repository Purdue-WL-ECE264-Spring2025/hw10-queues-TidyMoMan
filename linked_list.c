#include "linked_list.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

int cont(struct list_node*, size_t);
void freedom(struct list_node*);

// Returns a pointer to a node
struct list_node *new_node(uint64_t value) {
  struct list_node *pt_to_node = malloc(sizeof(struct list_node)); // Allocate memory for a node with size sufficient for a list node
  pt_to_node -> value = value; // Dereference the pointer to node and set the value as value provided to function
  pt_to_node -> next = NULL; // Dereference the pointer to node and set the next pointer to NULL
  return pt_to_node;
}

void insert_at_head(struct linked_list *list, uint64_t value) {
  struct list_node *pt_new_node = new_node(value); // Create a pointer to a new node
  pt_new_node -> next = list->head; // Point to where the head is currently pointing to
  list->head = pt_new_node; // Make head point to where pt_new_node is pointing to (i.e. to the new node
}

void insert_at_tail(struct linked_list *list, uint64_t value) {

  //if(!cont(list->head, value)){

  if (list->head == NULL){
    insert_at_head(list, value);
  } else{
    struct list_node *tail = list->head;
    while (tail -> next != NULL){
      tail = tail->next;
    }
    struct list_node *pt_new_node = new_node(value);
    tail->next = pt_new_node;
  }

  //}
}

uint64_t remove_from_head(struct linked_list *list) {
  uint64_t remove_val = list->head->value;
  struct list_node *temp_pt = list->head->next;
  free(list->head);
  //list->head = malloc(sizeof(struct list_node));
  list->head = temp_pt;

  return remove_val;
}

uint64_t remove_from_tail(struct linked_list *list) {
  struct list_node *tail = list->head;
  while (tail->next->next != NULL){
    tail = tail->next;
  }
  uint64_t remove_val = tail->next->value;
  free(tail->next);
  tail->next = malloc(sizeof(struct list_node));
  tail->next = NULL;
  return remove_val;
}

void free_list(struct linked_list list){
  freedom(list.head);
}

void freedom(struct list_node* head){
  printf("freed once\n");
  if(head == NULL){return;}
  struct list_node* next = head->next;
  free(head);
  freedom(next);
}

int cont(struct list_node* head, size_t target){
  if(head == NULL){return 0;}
  if(head->value == target){return 1;}
  return cont(head->next, target);
}

// Utility function to help you debugging, do not modify
void dump_list(FILE *fp, struct linked_list list) {
  fprintf(fp, "[ ");
  for (struct list_node *cur = list.head; cur != NULL; cur = cur->next) {
    fprintf(fp, "%zu ", cur->value);
  }
  fprintf(fp, "]\n");
}
