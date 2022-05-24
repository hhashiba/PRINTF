CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	-I /include
NAME		=	libftprintf.a
SRCSDIR		=	src/
SRCS		=	$(SRCSDIR)check_printable_len.c	\
				$(SRCSDIR)convert.c				\
				$(SRCSDIR)ft_printf.c			\
				$(SRCSDIR)ft_strchr_null.c		\
				$(SRCSDIR)ft_strlen_chr.c		\
				$(SRCSDIR)ft_strlen.c			\
				$(SRCSDIR)print_c_s_p_per.c		\
				$(SRCSDIR)print_id_u_x.c		\
				$(SRCSDIR)toupper_str.c			\
				$(SRCSDIR)ft_calloc.c			\
				$(SRCSDIR)ft_memset.c			\
				$(SRCSDIR)ft_bzero.c			\

OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) r $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all