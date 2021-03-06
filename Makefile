all: main.c motor.c motor.h maze.c maze.h qtr_driver.c qtr_driver.h
	avr-gcc -mmcu=atmega328 -O2 main.c motor.c qtr_driver.c maze.c -o main

check: 
	avrdude -c buspirate -P /dev/buspirate -p atmega328

upload: all
	avrdude -c buspirate -P /dev/buspirate -p atmega328 -U flash:w:main

clean: main
	rm -f main 
