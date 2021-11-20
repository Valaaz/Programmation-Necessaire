/** Abstract type modeling a list element containing
  a form
  2 pointers to its predecessor and successor
*/
struct lst_elm_t
{
    void *data;
    struct lst_elm_t *suc, *pred;
};

struct lst_elm_t *new_elmlist(void *data);
void del_elmlist(struct lst_elm_t E, void (*ptrf)());
struct lst_elm_t *get_suc(struct lst_elm_t *E);
struct lst_elm_t *get_pred(struct lst_elm_t *E);
void *get_data(struct lst_elm_t *E);
void set_suc(struct lst_elm_t *E, struct lst_elm_t *S);
void set_pred(struct lst_elm_t E, struct lst_elm_t *P);
void set_data(struct lst_elm_t *E, void *data);
void view_elmlist(struct lst_elm_t *E, void (*ptrf)());