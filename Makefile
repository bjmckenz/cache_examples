all: factorial1 factorial2 factorial3 factorial4

CC=clang
CFLAGS= -Wall -g

factorial1: factorial1.c
	$(CC) $(CFLAGS) -o $@ $<

factorial2: factorial2.c
	$(CC) $(CFLAGS) -o $@ $<

factorial3: factorial3.c
	$(CC) $(CFLAGS) -o $@ $<

factorial4: factorial4.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf *.o *.dSYM factorial?
