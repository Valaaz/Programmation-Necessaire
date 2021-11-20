#include <stdio.h>
#include "db.h"
#include "form.h"

int main()
{
    // form read from file function pointer
    struct form *(*ptr_read)(FILE *, enum mode_t) = &read_form;
    // form view function pointer
    void (*ptr_view)(struct form *) = &view_form;
    // form write into file function pointer
    void (*ptr_write)(struct form *, enum mode_t, FILE *) = &write_form;
    // form deletion function pointer
    void (*ptr_del)(struct form *) = &del_form;
    // create form list from text/binary file
    struct list *L = read_list(TEXT, (void *(*)())ptr_read, ptr_del);
    // view form list
    view_list(L, ptr_view);
    // write form list into text/binary file
    write_list(L, BINARY, ptr_write);
    // delete form list
    del_list(L, ptr_del);
    // create form list from text/binary file
    L = read_list(BINARY, (void *(*)())ptr_read, ptr_del);
    // view form list
    view_list(L, ptr_view);
    // delete form list
    del_list(L, ptr_del);
    return EXIT_SUCCESS;
}