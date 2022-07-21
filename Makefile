obj-m := sch311x_wdt.o

ifeq ($(KERNELDIR),)
KERNELDIR=/lib/modules/$(shell uname -r)/build
endif

all:
	make -C $(KERNELDIR) M=$(PWD) modules
	make feed_dog

feed_dog: feed_dog.c
	gcc -o feed_dog feed_dog.c

clean:
	make -C $(KERNELDIR) M=$(PWD) clean
	rm feed_dog