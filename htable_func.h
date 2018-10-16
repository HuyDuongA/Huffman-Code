#ifndef H_TABLE_FUNC
#define H_TABLE_FUNC
#define ASCII_SIZE 256
#define ONE_NODE 1
typedef struct node node;
struct node{
    char c;
    int freq;
    char *h_encode;
    node *next;
    node *left;
    node *right;
};

node *new_node();
void char_to_array(const char, int *);
node *array_to_list(int *);
void add_node_before(node **,node *, node*, int, char);
void add_node_after(node *, int, char);
void insert_list(node **, int, char);
node *sort_tree(node *);
void insert_node(node *, node *);
node *two_to_one_node(node *, node *);
char **tree_to_h_table(node *);

#endif
