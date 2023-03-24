#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct point
{
    char *name;
    struct point *next;
};
int put(struct point **list, char *nam)
{
    struct point *temp = (*list);
    (*list) = malloc(sizeof(struct point));
    (*list)->name = malloc(15 * sizeof(char));
    strcpy(((*list)->name), nam);
    (*list)->next = temp;
}
int print(struct point *list)
{
    while ((list) != NULL)
    {
        printf("%s-->", list->name);
        list = list->next;
    }
    printf("NULL");
    printf("\n");
}
int delete(struct point **list, char *dnam)
{
    while ((*list) != NULL)
    {
        if (strcmp((*list)->name, dnam) == 0)
        {
            struct point *temp = (*list);
            (*list) = (*list)->next;
            free(temp);
        }
        else
        {
            list = &((*list)->next);
        }
    }
}
int main(void)
{
    struct point *list;
    char *nam;
    list = NULL;
    nam = malloc(15 * sizeof(char));

    scanf("%s", nam);
    while (strcmp(nam, "END") != 0)
    {

        put(&list, nam);
        scanf("%s", nam);
    }
    print(list);
    delete (&list, "nikos");
    print(list);
}