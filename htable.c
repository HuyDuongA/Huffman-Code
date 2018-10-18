#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "htable_func.h"

void print_list(node *list){
    node *temp = list;
    while(temp){
        printf("%c: %d\n", temp->c, temp->freq);
        temp = temp->next;
    }
}

void print_tree(node *tree){

}

int main(const int argc, const char *argv[]){
    char c;
    int fd = open(argv[1], O_RDONLY);
    int array[ASCII_SIZE] = {0}; 
    char **h_table;
    node *list, *tree;
    while(read(fd, &c, sizeof(char))){
        char_to_array(c, array);
    }
    list = array_to_list(array);
    print_list(list);
    tree = sort_tree(list);
    h_table = tree_to_h_table(tree);
    print_tree(tree);
    return 0;
}
