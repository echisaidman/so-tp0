#include "shared_utils.h"
#include <commons/collections/list.h>
#include <stdlib.h>

void simpleListDestroyer(t_list *list)
{
    void simpleElementDestroyer(void *element)
    {
        free(element);
    }
    list_destroy_and_destroy_elements(list, simpleElementDestroyer);
}
