# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 17:13:05 by tkannane          #+#    #+#              #
#    Updated: 2024/02/03 18:41:29 by tkannane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmd = cc

client = client

server = server

client_bonus = client_bonus

server_bonus = server_bonus

src_client = mandatory/client.c

src_server = mandatory/server.c

src_utils = mandatory/minitalk_utils.c

src_client_bonus = bonus/client_bonus.c

src_server_bonus = bonus/server_bonus.c

src_utils_bonus = bonus/minitalk_utils_bonus.c bonus/minitalk_utils_bonus1.c

obj_client = $(src_client:.c=.o)

obj_server = $(src_server:.c=.o)

obj_utils = $(src_utils:.c=.o)

obj_client_bonus = $(src_client_bonus:.c=.o)

obj_server_bonus = $(src_server_bonus:.c=.o)

obj_utils_bonus = $(src_utils_bonus:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all :	$(client) $(server)

%.o:%.c minitalk.h
	$(cmd) $(CFLAGS) -c $< -o $@

$(client):	$(obj_client) $(obj_utils)
			$(cmd) $(obj_client) $(obj_utils) -o $@

$(server):	$(obj_server) $(obj_utils)
			$(cmd) $(obj_server) $(obj_utils) -o $@


$(client_bonus):	$(obj_client_bonus) $(obj_utils_bonus)
			$(cmd) $(obj_client_bonus) $(obj_utils_bonus) -o $@

$(server_bonus):	$(obj_server_bonus) $(obj_utils_bonus)
			$(cmd) $(obj_server_bonus) $(obj_utils_bonus) -o $@

bonus:	$(client_bonus) $(server_bonus)
clean:
		rm -rf $(obj_client) $(obj_server) $(obj_utils) $(obj_client_bonus) $(obj_server_bonus) $(obj_utils_bonus)

fclean:	clean
		rm -rf $(server) $(client) $(server_bonus) $(client_bonus)

re:	fclean all

