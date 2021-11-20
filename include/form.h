#include <stdbool.h>
#include <stdio.h>
#include "db.h"
/**
Form of manufactured products modeled with :
   - A product name (char *)
   - A stock (int)
   - A price before tax (double)
*/
#define len_max 20
struct form
{
   char product[len_max];
   int stock;
   double pbt;
};

/** Delete a form */
void del_form(struct form *F);
/** Read a form from FILE */
struct form *read_form(FILE *fd, enum mode_t mode);
/** Write a form to FILE */
void write_form(struct form *F, enum mode_t mode, FILE *fd);
/** Get the product name of the form F */
char *get_product(struct form *F);
/** Get the stock of the form F */
int get_stock(struct form *F);
/** Get the price before tax of the form F */
double get_price(struct form *F);
/** Display a form on stdout stream */
void view_form(struct form *F);
/** Is F1's product name less than or equal to F2's product name ? */
bool gt_form(struct form *F1, struct form *F2);