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

int main(const int argc, const char *argv[]){
    int c;
    int array[ASCII_SIZE] = {0};
    char **h_table;
    node *list, *tree;
    FILE *fp = NULL;
    if((fp = fopen(argv[1],"r"))){
        while((c = getc(fp)) != EOF){
            char_to_array(c, array);
        }
        list = array_to_list(array);
        if(list){
            tree= sort_tree(list);
            h_table = tree_to_h_table(tree);
            print_htable(h_table);
            clean_tree(tree);
        }
    }
    else{
        perror(argv[1]);
    }
    return 0;
}
