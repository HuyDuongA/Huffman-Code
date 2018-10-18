#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "htable_func.h"
#define ONE_NODE 1

node *new_node(){
    node *new_node = calloc(ONE_NODE, sizeof(node));
    new_node->c = (char)NULL;
    new_node->freq = 0;
    new_node->h_encode = NULL;
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
                insert_list(&head, array[i], (char)i);    
        }
    }
    return head;
}

/* Insert node to the right place in the list.
 * */
void insert_list(node **head, int f, char c){
    node *prev, *curr;
    curr = prev = *head;
    while(curr->next && curr->next->freq <= f){
        prev = curr;
        curr = curr->next;
    }
    if(curr->freq < f){
        add_list_after(curr, f, c);
    }
    else if(curr->freq == f){
        if(curr->c > c)
            add_list_before(head, prev, curr, f, c);
        else
            add_list_after(curr, f, c);
    }
    else
        add_list_before(head, prev, curr, f, c);
}

void add_list_before(node **head, node *prev, node *curr, int f, char c){
    if(prev == curr){
        prev = new_node();
        prev->c = c;
        prev->freq = f;
        prev->next = curr;
        *head = prev;
    }
    else{
        prev->next = new_node();
        prev->next->c = c;
        prev->next->freq = f;
        prev->next->next = curr;
    }
}

void add_list_after(node *curr, int f, char c){
    node *temp = curr->next;
    curr->next = new_node();
    curr->next->c = c;
    curr->next->freq = f;
    curr->next->next = temp;
}

/* The function takes the linked list and create a tree. This function calls
 * two_to_one_node function to combine first two nodes together.
 * */
node *sort_tree(node *list){
    node *new_node, *head, *first, *second;
    head = list;
    while(head->next){
        if(!head->next->next)
            head = two_to_one_node(head, head->next);
        else{
            first = head;
            second = head->next;
            head = head->next->next;
            new_node = two_to_one_node(first, second);
            insert_node(&head, new_node);
        }
    }
    return head;
}

void insert_node(node **head, node *new_node){
    node *prev, *curr, *temp;
    curr = prev = *head;
    while(curr->next && curr->next->freq <= new_node->freq){
        prev = curr;
        curr = curr->next;
    }
    if(curr == *head && curr->freq <= new_node->freq){
        temp = *head;
        *head = new_node;
        new_node->next = temp;
    }
    else if(curr->freq < new_node->freq){
        temp = curr->next;
        curr->next = new_node;
        new_node->next = temp;
    }
    else if(curr->freq == new_node->freq){
        if(curr->c > new_node->c){
            temp = prev->next;
            prev->next = new_node;
            new_node->next = temp;
        }
        else{
            temp = curr->next;
            curr->next = new_node;
            new_node->next = temp;
        }
    }
}

/* The function takes in two nodes, and combine them into one node 
 * that has 2 children. The node also contains the left node character 
 * with the added frequency.
 * */
node *two_to_one_node(node *first, node *second){
    node *n_node = new_node();
    first->next = NULL;
    second->next = NULL;
    n_node->freq = first->freq + second->freq;
    if(first->freq == second->freq){
        if(first->c < second->c){
            n_node->c = first->c;
            n_node->left = first;
            n_node->right = second;
        }
        else{
            n_node->c = second->c;
            n_node->left = second;
            n_node->right = first;
        }
    }
    else{
        n_node->c = first->c;
        n_node->left = first;
        n_node->right = second;
    }
    return n_node;
}

/* The function put Huffman code into each node of the tree and convert 
 * the tree to the array of pointer.
 * */
char **tree_to_h_table(node *tree){
    char **h_table = calloc(ASCII_SIZE, sizeof(char*)); 
    tree->h_encode = "0";
    encode_node(tree);
    table_encode(h_table, tree);
    return h_table;
}


/* The function takes tree input, and trace each leaf. If the leaf is going 
 * to the right, add "1" into the p_array[index]. Else if the leaf is going
 * to the left, add "0" into the p_array[index].
 * */
void encode_node(node *tree_node){
    char *par_code = calloc(strlen(tree_node->h_encode+1), sizeof(char));
    par_code = strcpy(par_code, tree_node->h_encode);
    if(tree_node->left){
        tree_node->left->h_encode = strcat(par_code, L_STR);
        encode_node(tree_node->left);
    }
    if(tree_node->right){ 
        tree_node->right->h_encode = strcat(par_code, R_STR);
        encode_node(tree_node->right);
    }
    free(par_code);
}

/* The function traverse through the tree to get the code for each character
 * then store the code into the h_table.
 * */
void table_encode(char **h_table, node *tree){
}
