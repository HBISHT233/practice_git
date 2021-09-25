obj-m := main.o
ARCH=arm
CROSS_COMPILE=arm-linux-gnueabihf-
KVERSION =$(shell uname -r)

all:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean	
