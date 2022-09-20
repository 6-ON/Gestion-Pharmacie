CC = gcc
OBJS = menu.o product.o product_list.o  controller.o main.o
SRCS = libs/sources/menu.c libs/sources/product.c libs/sources/product_list.c  libs/sources/controller.c main.c
APP =  Gestion_Pharmacie
all:LINK

COMPILE: 
	$(CC) $(SRCS) -c
LINK: COMPILE
	$(CC) $(OBJS) -o $(APP)

clean:LINK
	rm *.o

run:
	./$(APP)
