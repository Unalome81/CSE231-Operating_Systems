obj-m += Q3.o
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	sudo insmod Q3.ko
	sudo rmmod Q3
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
build:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
run:
	sudo insmod Q3.ko
	sudo rmmod Q3
load:
	sudo insmod Q3.ko
unload:
	sudo rmmod Q3
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
