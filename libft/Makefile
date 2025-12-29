NAME 		= 		libft.a

CC 			=		cc

CFLAGS 		=		-Wall -Wextra -Werror

HEADER 		=		libft.h	

COBJS 		= 		$(SRCS:.c=.o)

SRCS 		=		ft_isalpha.c 		\
	   				ft_isdigit.c 		\
	  		 		ft_isalnum.c 		\
	   				ft_isascii.c 		\
	   				ft_isprint.c 		\
	   				ft_strlen.c  		\
	   				ft_memset.c  		\
	   				ft_bzero.c   		\
	   				ft_memcpy.c			\
	   				ft_strlcpy.c		\
	   				ft_strlcat.c		\
	   				ft_toupper.c		\
	   				ft_tolower.c		\
	   				ft_strchr.c			\
	   				ft_strrchr.c		\
	   				ft_strnstr.c		\
	   				ft_strncmp.c		\
	   				ft_memchr.c			\
	   				ft_memcmp.c			\
	   				ft_memmove.c 		\
	   				ft_atoi.c			\
	   				ft_calloc.c			\
	   				ft_strdup.c			\
	   				ft_substr.c			\
	   				ft_strjoin.c		\
	   				ft_strtrim.c		\
	   				ft_split.c			\
	   				ft_itoa.c			\
		   			ft_strmapi.c		\
		   			ft_striteri.c		\
		   			ft_putchar_fd.c		\
		   			ft_putstr_fd.c		\
		   			ft_putendl_fd.c		\
		   			ft_putnbr_fd.c		\

COBJS_BONUS = 		$(BONUS_SRCS:.c=.o)

BONUS_SRCS 	=		ft_lstnew.c			\
					ft_lstadd_front.c	\
					ft_lstsize.c		\
					ft_lstlast.c		\
					ft_lstadd_back.c	\
					ft_lstdelone.c		\
					ft_lstiter.c		\
					ft_lstmap.c			\
					ft_lstclear.c		\

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(COBJS)
	ar rcs $(NAME) $(COBJS)

clean:
	rm -rf $(COBJS) $(COBJS_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
	
bonus: $(COBJS_BONUS)
	ar rcs $(NAME) $(COBJS_BONUS)

.PHONY: fclean all clean re bonus
