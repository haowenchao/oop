all:main.c cmd.c gpio.c
	gcc -o oop main.c gpio.c cmd.c

clean:
	rm -rf oop
