#include <ft_ls.h>

t_folder    *ft_new_folder(char *path, char *name, t_folder *root)
{
    t_folder    *new_folder;

    new_folder = (t_folder *)malloc(sizeof(t_folder));

    if (new_folder)
    {
        new_folder->root = root;
        new_folder->left = NULL;
        new_folder->right = NULL;
        new_folder->path = ft_strdup(path);
        new_folder->name = ft_strdup(name);
    }
    return (new_folder);
}

void        ft_add_folder(t_folder *root, t_folder *folder)
{
    t_folder    *tmp;

    tmp = root;
    while (tmp && tmp->left)
        tmp = tmp->left;
    tmp->left = folder;
}

t_folder    ft_del_folder(t_folder **folder)
{
    ft_strdel(*folder->path);
    ft_strdel(*folder->name);
    free(*folder);
    **folder = NULL;
}
