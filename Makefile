NAME		=	push_swap
INCLUDES	=	include/
LIBFT		=	libft/
SRCS_DIR	=	./
OBJS_DIR	=	obj/
CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM		=	rm -f
AR		=	ar rcs

SRCS_FILES 	= \
			main \
			initialization \
			input_checks \
			operations \
			sort \
			
SRCS		=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS		=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))

all:			$(NAME)

$(NAME):	 	$(OBJS)
				@make -C $(LIBFT)
				$(CC) $(CFLAGS) $(OBJS) $(LIBFT)/libft.a -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
			@mkdir -p $(OBJS_DIR)
			$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
			$(RM) -r $(OBJS_DIR)
			@make clean -C $(LIBFT)

fclean:		clean
			@$(RM) $(NAME)
			@make fclean -C $(LIBFT)

re:		fclean all

.PHONY:	all clean fclean re