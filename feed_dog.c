#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <time.h>

struct watchdog_info{
    unsigned int options;   //options the card/driver supprots 19         
    unsigned int firmware_version;  //firmcard version of the card
    unsigned char identity[32];     //identity of the board 21
 };

#define WATCHDOG_IOCTL_BASE 'W'
#define WDIOC_GETSUPPORT _IOR(WATCHDOG_IOCTL_BASE, 0, struct watchdog_info)
#define WDIOC_SETTIMEOUT _IOWR(WATCHDOG_IOCTL_BASE, 6, int)
#define WDIOC_GETTIMEOUT _IOR(WATCHDOG_IOCTL_BASE, 7, int)
#define WDIOS_DISABLECARD 0x0001        /* Turn off the watchdog timer */
#define WDIOS_ENABLECARD 0x0002 /* Turn on the watchdog timer */
#define WDIOC_SETOPTIONS _IOR(WATCHDOG_IOCTL_BASE, 4, int)
#define WDIOC_KEEPALIVE _IOR(WATCHDOG_IOCTL_BASE, 5, int)

#define TIMEOUT 20
#define SLEEP_TIME TIMEOUT * 50

 //suspend some seconds
int zsleep(int millisecond)
{
     unsigned long usec;
     usec = 1000 * millisecond;
     usleep(usec);
}

int main(int argc,char **argv)
{
    int fd, ch;
    int i, j;
    struct watchdog_info wi;
    fd = open("/dev/watchdog", O_RDWR); 
    if(fd < 0) {
        printf("device open fail\n");
        exit(0);
    }

    ioctl(fd, WDIOC_GETSUPPORT, &wi);
    // printf("options : %d, identity : %s\n", wi.options,wi.identity);

    i = TIMEOUT;
    ioctl(fd, WDIOC_SETTIMEOUT, &i);
    // printf("SETTIMEOUT %d\n" ,ioctl(fd, WDIOC_SETTIMEOUT, &i));
    ioctl(fd, WDIOC_GETTIMEOUT, &i);
    // printf("GETTIMEOUT %d\n", ioctl(fd, WDIOC_GETTIMEOUT, &i));
    // printf("%d\n",i); 

    i = WDIOS_DISABLECARD;
    ioctl(fd, WDIOC_SETOPTIONS, &i);
    // printf("DISABLECARD %d\n", ioctl(fd, WDIOC_SETOPTIONS, &i));

    i = WDIOS_ENABLECARD;
    ioctl(fd, WDIOC_SETOPTIONS, &i);
    // printf("ENABLECARD %d\n", ioctl(fd, WDIOC_SETOPTIONS, &i));

    while(1)
    {
        zsleep(SLEEP_TIME);
        ioctl(fd, WDIOC_KEEPALIVE,NULL);
    }
    close(fd);
    return 0;
}