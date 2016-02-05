/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 09:30:05 by cledant           #+#    #+#             */
/*   Updated: 2016/01/17 11:10:14 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <sys/acl.h>

typedef struct		s_mstat
{
	char			*name;
	uint16_t		namelen;
	dev_t			dev;
	mode_t			mode;
	nlink_t			hardlink;
	ino_t			inode;
	uid_t			uid;
	gid_t			gid;
	dev_t			rdev;
	time_t			mod_time;
	off_t			size;
	ssize_t			has_xattr;
	size_t			has_acl;
	char			*folder;
}					t_mstat;

typedef struct		s_linfo
{
	size_t			namelen;
	size_t			devlen;
	size_t			hardlinklen;
	size_t			uidlen;
	size_t			gidlen;
	size_t			majorlen;
	size_t			minorlen;
	time_t			mode_time;
	size_t			sizelen;
}					t_linfo;

typedef struct		s_btree
{
	struct s_btree	*right;
	struct s_btree	*left;
	void			*content;
	size_t			content_size;
}					t_btree;

typedef struct		s_option
{
	int				hidden;
	int				sort;
	int				detail;
	int				reverse;
	int				all_dir;
	int				other;
}					t_option;

typedef struct		s_ssort
{
	char		*name;
	size_t		is_dir;
	time_t		mod_time;
}					t_ssort;

t_mstat				*ft_mstat_new(uint16_t namelen);
int					ft_mstat_compare_name(void *s1, void *s2);
int					ft_mstat_compare_time(void *s1, void *s2);
void				ft_mstat_del(void *del);
int					ft_mstat_save(char *path, struct dirent *dir,
						t_mstat *saved);
int					ft_mstat_is_content_dir(t_mstat *stat);
int					ft_mstat_is_content_link_a_dir(t_mstat *stat);
int					ft_mstat_is_content_null(t_mstat *stat);
int					ft_mstat_is_content_sp_char(t_mstat *stat);
int					ft_mstat_is_content_sp_block(t_mstat *stat);
int					ft_mstat_is_content_link(t_mstat *stat);
int					ft_mstat_explore_hidden(t_mstat *stat, int hidden);
void				ft_option_init(t_option *opt);
int					ft_option_ls(char *path, t_option *opt, t_linfo *linfo);
void				ft_option_what_to_display(t_btree *root, t_option *opt,
						t_linfo *linfo);
int					ft_option_fill_struct(char *s, t_option *opt);
t_btree				*ft_btree_new(void const *content, size_t content_size);
void				ft_btree_linfo(t_btree *root, t_option *opt,
						t_linfo *l_stat);
void				ft_btree_linfo_apply_infix(t_btree *root, t_linfo *pad,
						t_option *opt);
void				ft_btree_linfo_apply_reverse_infix(t_btree *root,
						t_linfo *pad, t_option *opt);
void				ft_btree_delone(t_btree **alst, void (*del)(void *,
						size_t));
void				ft_btree_del_all_node(t_btree **alst);
void				ft_btree_del_all_0_size_node(t_btree **alst);
void				ft_btree_del_all_0_size_node_other(t_btree **alst);
void				ft_btree_add_node(t_btree *root, t_btree *new, int
						(*cmpf)(void *, void *));
t_btree				*ft_btree_sort_dir(char *path, int sort);
void				ft_btree_apply_reverse_infix(t_btree *root,
						void (*applyf)(void *));
void				ft_btree_apply_infix(t_btree *root, void (*applyf)
						(void *));
void				ft_btree_apply_postfix(t_btree *root, void (*applyf)
						(void *));
t_btree				*ft_btree_mstat_file(char *path);
t_ssort				*ft_ssort_init(char *name);
void				ft_ssort_del(void *del);
void				ft_linfo_init(t_linfo *new);
void				ft_linfo_fill(t_btree *root, t_option *opt, t_linfo *lstat);
int					ft_linfo_btree_compare_size(t_btree *root, t_linfo *l_stat);
void				ft_free_content(void *content, size_t content_size);
int					ft_strcmp_nchar(const char *s1, const char *s2, size_t n);
char				*ft_fuse_chain(char *path, char *name);
char				*ft_title_cap_r(char *new_path);
int					ft_argv_is_opt(char *s);
int					ft_argv_is_opt_valid(char *s);
void				ft_putendl_colon(char const *s);
void				ft_display_all(void *content);
void				ft_display_no_dot(void *content);
void				ft_display_l_all(void *content, t_linfo *pad);
void				ft_display_l_no_dot(void *content, t_linfo *pad);
void				ft_display_l_mode(t_mstat *stat);
void				ft_display_l_mode_right(mode_t right, mode_t set);
void				ft_display_l_mode_right_group(mode_t right, mode_t set);
void				ft_display_l_mode_right_other(mode_t right, mode_t set);
int					ft_display_l_mode_right_special_bit_set_other(mode_t set);
int					ft_display_l_mode_right_special_bit_set_group(mode_t set);
int					ft_display_l_mode_right_special_bit_set_user(mode_t set);
void				ft_display_l_mode_type(mode_t mode);
void				ft_display_l_mode_user(mode_t mode);
void				ft_display_l_mode_group(mode_t mode);
void				ft_display_l_mode_other(mode_t mode);
void				ft_display_l_username(uid_t uid);
void				ft_display_l_groupname(gid_t gid);
void				ft_display_l_major(dev_t rdev);
void				ft_display_l_minor(dev_t rdev);
void				ft_display_l_time(time_t time);
void				ft_display_l_symlink(char *folder, char *name);
int					ft_compare_six_month(time_t s1, time_t s2, int flag);
int					ft_is_year_leapyear(int	n);
void				ft_display_blocksize(char *path, int flag);
size_t				ft_display_l_offset_user(uid_t uid, size_t maxlen);
size_t				ft_display_l_offset_grp_size(gid_t gid, size_t gmaxlen,
						off_t size, size_t smaxlen);
size_t				ft_return_major_size(dev_t rdev);
size_t				ft_return_minor_size(dev_t rdev);
int					ft_explore_hidden(char *path, int hidden);
int					ft_is_path_dir(char *path);
int					ft_is_path_link(char *path);
int					ft_is_path_link_a_dir(char *path);
int					ft_lastchar_is_slash(char *path);
time_t				ft_seek_mod_time(char *path);
int					ft_cmp_content(void *s1, void *s2);
int					ft_cmp_content_time(void *s1, void *s2);
void				ft_put_to_screen(t_btree *root, t_option *opt, int flag,
						int *space);
int					ft_int_solve_ls(char **argv, int argc, int skip,
						t_option *opt);

#endif
