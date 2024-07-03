all: factorial.c A.c B2.c B1.c
	@gcc factorial.c -o factorial
	@gcc A.c -o A
	@gcc B1.c -o B1
	@gcc B2.c -o B2
	@# while [ true ] ; do \
	# 	read -p 'Do you want to run a file (Y/N) ? ' a ;  \
	# 	echo "$(a)";\
	# 	if [ "$(a)" = 'Y' ] ; \
	# 	then  \
	# 		echo "Enter a file name" ; \
	# 		read a ; \
	# 		./$a ; \
	# 	elif [ '$(a)' = 'N' ] ; \
	# 	then  \
	# 		echo "NOa";\
	# 		break ; \
	# 	else  \
	# 		echo "Wrong Input !!" ; \
	# 	fi ;\
	# done ; \
	# true;
A: A.c
	@gcc A.c -o A
	@./A
B1: B1.c
	@gcc factorial.c -o factorial
	@gcc B1.c -o B1
	@./B1
B2: B2.c
	@gcc B2.c -o B2
	@./B2
cleanA:
	@rm A
cleanB1:
	@rm B1
	@rm factorial
cleanB2:
	@rm B2
clean:
	@rm A
	@rm B1
	@rm B2
	@rm factorial
runA:
	@./A
runB1:
	@./B1
runB2:
	@./B2