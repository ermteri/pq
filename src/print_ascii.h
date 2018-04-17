#ifndef PRINT_ASCII_H   /* Include guard */
#define PRINT_ASCII_H

typedef struct Trees{
  struct Trees *parent;
  struct Trees *left;
  struct Trees *right;
  float value;
  struct Trees *self;
}Tree;

void print_ascii_tree(Tree * t) ;  /* An example function declaration */

#endif // PRINT_ASCII_H
