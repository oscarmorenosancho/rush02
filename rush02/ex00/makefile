NAME=rush00
FLAGS= -Wall -Wextra -Werror
all: $(NAME).exe
main.o: main.c
	gcc $(FLAGS) -c main.c
ft_str.o: ft_str.c
	gcc $(FLAGS) -c ft_str.c
read_dict.o: read_dict.c
	gcc $(FLAGS) -c read_dict.c
split_text_in_lines.o: split_text_in_lines.c
	gcc $(FLAGS) -c split_text_in_lines.c
process_lines.o: process_lines.c
	gcc $(FLAGS) -c process_lines.c
$(NAME).exe: main.o ft_str.o split_text_in_lines.o process_lines.o read_dict.o
	gcc $(FLAGS) main.o ft_str.o split_text_in_lines.o process_lines.o read_dict.o -o $(NAME).exe
clean:
	rm main.o
	rm ft_str.o	
	rm read_dict.o
	rm split_text_in_lines.o
	rm process_lines.o
fclean: clean
	rm $(NAME).exe
