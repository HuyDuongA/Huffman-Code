#ifndef H_TABLE_FUNC
#define H_TABLE_FUNC
#define ASCII_SIZE 256
#define ONE_NODE 1
#define L_STR "0"
#define R_STR "1"
#define COUNT 5

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
void add_list_before(node **,node *, node*, int, char);
void add_list_after(node *, int, char);
void insert_list(node **, int, char);
node *sort_tree(node *);
void insert_node(node **, node *);
node *two_to_one_node(node *, node *);
char **tree_to_h_table(node *);
void encode_node(node *);
void table_encode(char **, node *);
void print_htable(char **);
void print_tree(node *, int);

#endif
