#include <poyoio.h>
#include <poyolib.h>
#include <xmodem.h>


static int dump(char *buf, long size) {
    long i;

    if (size < 0) {
        puts("no data.\n");
        return -1;
    }
    for (i = 0; i < size; i++) {
        putxval(buf[i], 2);
        if ((i & 0xf) == 15) {
            puts("\n");
        } else {
            if ((i & 0xf) == 7) puts(" ");
            puts(" ");
        }
    }
    puts("\n");

    return 0;
}


int main() {

    static char buf[16];
    static long size = -1;
    static unsigned char *loadbuf = NULL;
    //extern int buffer_start;

    init();

    puts("kzload (kozos boot loader) started.\n");

    while (1) {
        puts("kzload> ");
        gets(buf);

        if (!strcmp(buf, "load")) {
            //loadbuf = (char *)(&buffer_start);
            //size = xmodem_recv(loadbuf);
            //if (size < 0) {
	            //puts("\nXMODEM receive error!\n");
            //} else {
	            //puts("\nXMODEM receive succeeded.\n");
            //}
        } else if (!strcmp(buf, "dump")) {
            puts("size: ");
            //putxval(size, 0);
            puts("\n");
            //dump(loadbuf, size);
        } else {
            puts("unknown.\n");
        }
    }

    return 0;
}
