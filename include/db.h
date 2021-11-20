/* file mode : text or binary */
enum mode_t
{
    TEXT,
    BINARY
};
/** write a list into a text or binary file acording to the mode */
void write_list(struct list *L, enum mode_t mode, void (*ptrf)());
/** read a list from a text or binary file acording to the mode */
struct list *read_list(enum mode_t mode, void *(*ptrf)(), void(ptr_del)());