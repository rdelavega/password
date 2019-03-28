OBJS = main.o HELP.o REGEXOp.o validateOp.o fileOp.o resultOp.o

CFLAGS = -lm

passwordCheck:	$(OBJS)
	gcc -o password $(OBJS) $(CFLAGS)

main.o:	main.c headers.h
	gcc -c main.c

HELP.o:	HELP.c headers.h
	gcc -c HELP.c

REGEXOp.o: REGEXOp.c headers.h
	gcc -c REGEXOp.c

validateOp.o: validateOp.c headers.h
	gcc -c validateOp.c

fileOp.o: fileOp.c headers.h
	gcc -c fileOp.c

resultOp.o: resultOp.c headers.h
	gcc -c resultOp.c

clean:
	rm -f $(OBJS) password

run:
	./password -p ${PASS} -u ${USER}
