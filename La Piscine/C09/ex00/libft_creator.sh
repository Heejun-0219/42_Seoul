#!/bin/sh

gcc -Wall -Wextra -Werror -c *c 
ar -cr libft.a *.o
