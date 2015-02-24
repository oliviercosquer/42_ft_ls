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
	struct s_file	*next;
	struct s_file	*parent;
	struct s_file	*files;

}				t_file;

typedef t_file t_folder;

t_file	*ft_read(char *path, char *options);
void	ft_read_folder(DIR *stream, char *options, t_file *root);
t_file	*ft_new_file(t_file *parent);
char	*ft_get_options(int argc, char **argv);
void	ft_fill_file_info(t_file *file, struct dirent *dir);
char	*ft_get_full_path(char *filename, t_file *folder);
void	ft_add_file(t_file *file, t_file *root);
void	ft_add_folder(t_file *folder, t_file *root);
int		ft_is_folder(t_file *file);
void	ft_display_folder(t_file *root, char *options);
void	ft_display_files(t_file *files, char *options);
void	ft_order_asc(t_file **root);
void	ft_swap(t_file *prev, t_file *cur, t_file *next, t_file **root);
char	*ft_get_real_path(char *filename, t_file *folder);
void	ft_putoff_t(off_t size);
void	ft_putnlink_t(nlink_t size);
char	*ft_get_perms(mode_t bin_perms);
void	ft_display_lfiles(t_file *file, char *options);
void	ft_check_files(char *path);
int		ft_check_options(char *options);
int		ft_check_errors(int argc, char **argv, char *options);
void	ft_order(t_file **root, char *options);
#endif
