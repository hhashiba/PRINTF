CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	-I /includes
NAME		=	libftprintf.a
LIBFTDIR	=	libft/
SRCSDIR		=	src/
SRCS		=	$(SRCSDIR)check_printable_len.c	\
				$(SRCSDIR)convert.c				\
				$(SRCSDIR)ft_printf.c			\
				$(SRCSDIR)ft_strchr_null.c		\
				$(SRCSDIR)ft_strlen_chr.c		\
				$(SRCSDIR)print_c_s_p_per.c		\
				$(SRCSDIR)print_id_u_x.c		\
				$(SRCSDIR)toupper_str.c			\

OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) bonus -C $(LIBFTDIR)
	cp $(LIBFTDIR)libft.a $(NAME)
	$(AR) rcs $@ $^

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFTDIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFTDIR)

re: fclean all