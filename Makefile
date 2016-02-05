# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cledant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 10:40:13 by cledant           #+#    #+#              #
#    Updated: 2016/01/17 11:11:25 by cledant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDES = ./includes

INCLUDES_LIBFT = ./libft/includes

LIBFT_PATH = ./libft

SRC_NAME =	ft_mstat_new.c ft_mstat_compare_name.c ft_mstat_compare_time.c \
			ft_mstat_del.c ft_mstat_save.c ft_mstat_is_content_dir.c \
			ft_mstat_is_content_null.c ft_mstat_is_content_sp_char.c \
			ft_mstat_is_content_sp_block.c ft_mstat_is_content_link.c \
			ft_mstat_explore_hidden.c ft_option_init.c ft_option_ls.c \
			ft_option_what_to_display.c ft_option_fill_struct.c \
			ft_btree_new.c ft_btree_linfo.c ft_btree_linfo_apply_infix.c \
			ft_btree_linfo_apply_reverse_infix.c ft_btree_delone.c \
			ft_btree_del_all_node.c ft_btree_del_all_0_size_node.c \
			ft_btree_del_all_0_size_node_other.c ft_btree_add_node.c \
			ft_btree_sort_dir.c ft_btree_apply_infix.c \
			ft_btree_apply_reverse_infix.c ft_btree_apply_postfix.c \
			ft_btree_mstat_file.c ft_ssort_init.c \
			ft_ssort_del.c ft_linfo_init.c \
			ft_linfo_btree_compare_size.c ft_free_content.c ft_strcmp_nchar.c \
			ft_fuse_chain.c ft_title_cap_r.c ft_argv_is_opt.c ft_putendl_colon.c \
			ft_display_all.c ft_display_no_dot.c ft_display_l_all.c \
			ft_display_l_no_dot.c ft_display_l_mode.c ft_display_l_mode_right.c \
			ft_display_l_mode_right_group.c ft_display_l_mode_right_other.c \
			ft_display_l_mode_type.c ft_display_l_mode_user.c \
			ft_display_l_mode_group.c ft_display_l_mode_other.c \
			ft_display_l_username.c ft_display_l_groupname.c \
			ft_display_l_major.c ft_display_l_minor.c ft_display_l_time.c \
			ft_display_l_symlink.c ft_compare_six_month.c ft_is_year_leapyear.c \
			ft_display_blocksize.c ft_display_l_offset_user.c \
			ft_display_l_offset_grp_size.c \
			ft_explore_hidden.c ft_is_path_dir.c ft_is_path_link.c \
			ft_lastchar_is_slash.c main.c ft_seek_mod_time.c \
			ft_display_l_mode_right_special_bit_set_other.c \
			ft_display_l_mode_right_special_bit_set_group.c \
			ft_display_l_mode_right_special_bit_set_user.c \
			ft_mstat_is_content_link_a_dir.c ft_is_path_link_a_dir.c \
			ft_argv_is_opt_valid.c ft_return_major_size.c ft_return_minor_size.c \
			ft_cmp_content.c ft_cmp_content_time.c ft_put_to_screen.c \
			ft_int_solve_ls.c ft_linfo_fill.c

SRC_PATH = ./srcs/

SRC =	$(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ =	$(SRC_NAME:.c=.o)

NAME = ft_ls

all :	libft $(NAME)

libft :
	make -C $(LIBFT_PATH)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) -lft -I$(INCLUDES) -I$(INCLUDES_LIBFT) -L$(LIBFT_PATH)

$(OBJ) :
	$(CC) -c $(SRC) $(CFLAGS) -I$(INCLUDES) -I$(INCLUDES_LIBFT)

clean :
	rm -rf $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean

re : fclean all

.PHONY : all clean fclean re libft
