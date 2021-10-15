# Universidade Federal do Rio de Janeiro
# EEL670 - Linguagens de Programção
# Prof.: Miguel Campista
# Exercício avaliado 04
# Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

CC = g++
CFLAGS = -Wall -std=c++11\
		 -I/usr/include/mysql -lmysqlclient

OBJDIR = obj
SRCDIR = src

OBJS = $(OBJDIR)/main.o\
	   	$(OBJDIR)/siga.o\
	   	$(OBJDIR)/disciplina.o\
		$(OBJDIR)/aluno.o

EXEC = bin/siga_app

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

siga: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(EXEC)
	
.PHONY: clean clean-objs

clean:
	rm $(EXEC)
clean-objs:
	rm $(OBJDIR)/*.o
