#include <stdlib.h>
#include <stddef.h>
#include "htable_func.h"
#define ONE_NODE 1

node *new_node(){
    node *new_node = calloc(ONE_NODE, sizeof(node));
    new_node->c = (char)NULL;
    new_node->freq = 0;
    new_node->next = NULL;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

/* The function takes a character as index value and increase array[index]
 * in each encounter in the array. 
 * */
void char_to_array(const char c, int *array){
   array[(int)c]++; 
}


/* The function converts a frequency array to a linked list, and 
 * return the list. The list is sorted by frequency in ascending order.
 * */
node *array_to_list(int *array){
    node *head = NULL;
    for(int i = 0; i < ASCII_SIZE; ++i){
        if(array[i]){
            if(head == NULL){
                head = new_node();
                head->c = i;
                head->freq = array[i];
            }
            else
                insert_node(head, array[i], (char)i);    
        }
    }
    return head;
}

void add_node_before(node *prev, node *curr, int f, char c){
    prev->next = new_node();
    prev->next->c = c;
    prev->next->freq = f;
    prev->next->next = curr;
}

void add_node_after(node *curr, int f, char c){
    node *temp = curr->next;
    curr->next = new_node();
    curr->next->c = c;
    curr->next->freq = f;
    curr->next->next = temp;
}

/* Insert node to the right place in the list.
 * */
void insert_node(node *head, int f, char c){
    node *prev, *curr;
    curr = prev = head;
    while(curr->next && curr->next->freq <= f){
        prev = curr;
        curr = curr->next;
    }
    if(curr->freq < f){
        add_node_after(curr, f, c);
    }
    else if(curr->freq == f){
        if(curr->c > c)
            add_node_before(prev, curr, f, c);
        else
            add_node_after(curr, f, c);
    }
    else
        add_node_before(prev, curr, f, c);
}

/* The function takes the linked list and create a tree. This function calls
 * two_to_one_node function to combine first two nodes together.
 * */
node *sort_tree(node *list){
    node *n_node = new_node();
    return n_node;
}

/* The function takes in two nodes, and combine them into one node 
 * that has 2 children. The node also contains the left node character 
 * with the added frequency.
 * */
node *two_to_one_node(node *first, node *second){
    node *n_node = new_node();
    return n_node;
}

/* The function takes tree input, and trace each leaf and add the code
 * into double pointer of char.
 * */
char **tree_to_h_table(node *tree){
    char **p_array = NULL;
    return p_array;
}
