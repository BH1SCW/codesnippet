#include <stdio.h>
#include <unistd.h>
#include <linux/uinput.h>
#include <fcntl.h>


int CreateUinput( char* filename)
{
    int i = 0;
    int ret = 0;
    struct uinput_user_dev device = { .name = "Uinput" };
    int fd = open( filename, O_WRONLY | O_NDELAY );
    if( fd < 0 ) 
    {
        printf("can't open device\n");
        return( -1 );
    }

    ioctl( fd, UI_SET_EVBIT, EV_SYN );
    ioctl( fd, UI_SET_EVBIT, EV_KEY );
    ioctl( fd, UI_SET_EVBIT, EV_REL );
    for( i = 0; i < 256; i++ )
    {
        ioctl( fd, UI_SET_KEYBIT, i );
    }
    for( i = 0x110; i < 0x118; i++ )
    {
        ioctl( fd, UI_SET_KEYBIT, i );
    }
    for( i = 0x150; i < 0x152; i++ )
    {
        ioctl( fd, UI_SET_KEYBIT, i );
    }
    ioctl( fd, UI_SET_RELBIT, REL_X );
    ioctl( fd, UI_SET_RELBIT, REL_Y );
    ioctl( fd, UI_SET_RELBIT, REL_WHEEL );
    ioctl( fd, UI_SET_RELBIT, REL_HWHEEL );

    ret = write( fd, &device, sizeof(device) );
    if( ret > 0 && !ioctl( fd, UI_DEV_CREATE ) )
    {
        return( fd );
    }

    close( fd );
    return( -1 );
}

int main(int argc, char** argv)
{
    int fd;
    struct input_event event;
    fd = CreateUinput(argv[1]);
    if(fd<0)
    return 0;
    memset( &event, 0, sizeof(event) );
    gettimeofday( &event.time, NULL );
    
    while(1)
    {
        event.type = EV_KEY;
        event.value = 1;
        event.code = BTN_LEFT;
        write( fd, &event, sizeof(event) );

        event.type = EV_SYN;
        event.code = SYN_REPORT;
        event.value = 0;
        write( fd, &event, sizeof(event) );

        event.type = EV_KEY;
        event.value = 0;
        event.code = BTN_LEFT;
        write( fd, &event, sizeof(event) );

        event.type = EV_SYN;
        event.code = SYN_REPORT;
        event.value = 0;
        write( fd, &event, sizeof(event) );
#if 1
        usleep (10000);
#else
        sleep(1);
#endif
    }
    
}
