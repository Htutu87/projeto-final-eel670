# Makefile

CC = g++
CFLAGS = -Wall

%o:%.c
	$(CC) $(CFLAGS) $< -o $@

db:
	$(CC) $(CFLAGS) db.cpp -o db -L/usr/include/mysql -lmysqlclient
clean:
	rm db
