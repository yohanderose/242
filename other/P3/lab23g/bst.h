#ifndef BST_H_
#define BST_H_
typedef struct bstnode *bst;
extern bst bst_free(bst b);
extern bst bst_inorder(bst b, void f(char *str));
extern bst bst_insert(bst b, char *str);
extern bst bst_new();
extern bst bst_preorder(bst b, void f(char *str));
extern int bst_search(bst b, char *str);
#endif
