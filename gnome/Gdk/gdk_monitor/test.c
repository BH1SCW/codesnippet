#include <gtk/gtk.h>
#include <gdk/gdk.h>

int main(int argc, char *argv[])
{
	GdkScreen *screen;
	gint width, height;
	gint index;
	gint point_1, point_2;
	gint mm_height, mm_width;
	GdkRectangle rect0, rect1;
	GdkWindow * wind;

	gtk_init(&argc, &argv);
	g_type_init();
	screen = gdk_screen_get_default();
	gint number = gdk_screen_get_n_monitors(screen);
	
	width = gdk_screen_get_width(screen);
	height = gdk_screen_get_height(screen);

	if(number > 1 )
	{
		index = gdk_screen_get_primary_monitor(screen);
		
		point_1 = gdk_screen_get_monitor_at_point(screen , 20, 20);
		point_2 = gdk_screen_get_monitor_at_point(screen , 2700, 20);

		printf("number is %d\n width %d\t height %d\n primary monitor index %d\n", number, width, height, index);

		printf("point1 is in monitor %d\n", point_1);
		printf("point2 is in monitor %d\n", point_2);
/*
		mm_height = gdk_screen_get_monitor_height_mm (screen, 0);
		printf("monitor0 height  %d\n", mm_height);
		mm_height = gdk_screen_get_monitor_height_mm (screen, 1);
		printf("monitor1 height  %d\n", mm_height);
		
		mm_width = gdk_screen_get_monitor_width_mm (screen, 0);
		printf("monitor0 width  %d\n", mm_width);
		mm_width = gdk_screen_get_monitor_width_mm (screen, 1);
		printf("monitor1 width  %d\n", mm_width);
*/
		gdk_screen_get_monitor_geometry(screen, 0, &rect0);
		printf("monitor0 rect.x %d rect.y %d\n rect.width %d rect.weight %d\n", rect0.x, rect0.y, rect0.width, rect0.height);
		
		gdk_screen_get_monitor_geometry(screen, 1, &rect1);
		printf("monitor1 rect.x %d rect.y %d\n rect.width %d rect.weight %d\n", rect1.x, rect1.y, rect1.width, rect1.height);

		wind = gdk_screen_get_active_window(screen);
		gint monitor = gdk_screen_get_monitor_at_window(screen, wind);
		printf("active window at monitor   %d\n", monitor);

	}
    else{
		printf("sorry, only one monitor! \n");
    }
}
