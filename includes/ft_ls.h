#ifndef FT_LS_H
# define FT_LS_H
# include <dirent.h>
# include <libft.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <grp.h>
# include <pwd.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>

typedef struct	s_file
{
	char			*name;
	char			*perms;
	char			*owner;
	char			*group;
	char			*access_time;
	int				hard_links;
	int				month;
	int				access_day;
	off_t			size;
	struct s_file	*left;
	struct s_file	*root;
	struct s_file	*children;
}				t_file;

//ft_display
void	ft_display_folder(t_file *root, char *options);
void	ft_display_files(t_file *files, char *options);
void	ft_display_lfiles(t_file *file, char *options);

//ft_errors
void	ft_check_files(char *path);
int		ft_check_options(char *options);
int		ft_check_errors(int argc, char **argv, char *options);

//ft_file
t_file	*ft_new_file(t_file *parent);
void	ft_fill_file_info(t_file *file, struct dirent *dir);
char	*ft_get_full_path(char *filename, t_file *folder);
char	*ft_get_real_path(char *filename, t_file *folder);

//ft_file2
t_file	*ft_create_root(int argc, char **argv);
void	ft_add_file(t_file *file, t_file *root);
void	ft_add_folder(t_file *folder, t_file *root);
char	*ft_get_perms(mode_t bin_perms);

//ft_order
void	ft_order(t_file **root, char *options);
void	ft_order_asc(t_file **root);
void	ft_swap(t_file *prev, t_file *cur, t_file *next, t_file **root);

//ft_order_asc
void	ft_order_by_name_asc(t_file **root);

//ft_order_desc
void	ft_order_by_name_desc(t_file **root);

//ft_read_folder
t_file	*ft_read(char *path, char *options);
void	ft_read_folder(DIR *stream, char *options, t_file *root);
int		ft_is_folder(t_file *file);

//ft_folder

//ft_tools
void	ft_putoff_t(off_t size);
void	ft_putnlink_t(nlink_t size);
int		ft_strcmp_tolower(char *s1, char *s2);

//ft_get_options
char	*ft_get_options(int argc, char **argv);
int     ft_is_option(char *str);
#endif
