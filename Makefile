NAME        = cmeowth.filler
HEADER		= $(INCDIR)/filler.h
LIBFT		= $(LIBDIR)/libft.a

GCC			= /usr/bin/clang
WOPT		= -Wall -Wextra -Werror
OOPT		= -O2
IOPT		= -I$(INCDIR) -I$(LIBDIR)/includes

AR			= /usr/bin/ar -rc
RM			= /bin/rm -rf
RANLIB		= /usr/bin/ranlib
NORMINETTE	= /usr/bin/norminette
MKDIR		= /bin/mkdir -p


INCDIR		= ./includes
SRCDIR		= ./sources
OBJDIR		= ./objects
LIBDIR		= ./libft

SRCNAME     = filler.c \
              play.c \
              print.c

SRCS		= $(addprefix $(SRCDIR)/, $(SRCNAME))
OBJLIST		= $(patsubst %.c, %.o, $(SRCNAME))
#OBJS        = $(addprefix $(OBJDIR)/, $(patsubst %.c, %.o, $(SRCNAME)))
OBJS        = $(addprefix $(OBJDIR)/, $(SRCNAME:.c=.o))

CLEAR       = "\033[K"
EOC			= "\033[0;0m"
GREEN		= "\033[0;32m"
CR			= "\r"$(CLEAR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(HEADER) $(LIBDIR)/includes
	@$(GCC) $(WOPT) $(OOPT) $(IOPT) -L$(LIBDIR) -lft -o $(NAME) $(OBJS)
	@printf $(CR)$(GREEN)"✓ $(NAME) is created\n"$(EOC)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(GCC) $(WOPT) $(OOPT) $(IOPT) -o $@ -c $<

$(LIBFT):
	make -C $(LIBDIR)

clean:
	rm -rf $(OBJDIR)
	make clean -C $(LIBDIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBDIR)

re: fclean all