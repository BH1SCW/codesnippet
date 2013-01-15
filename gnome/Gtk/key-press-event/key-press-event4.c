#include <gtk/gtk.h>

void on_view_button_press_event (GtkWidget *widget, gpointer data);

int main (int argc, char *argv[])
{
	GtkWidget *window, *view;	
	GtkTextBuffer *buffer;	

	gtk_init(&argc, &argv);		
	window =gtk_window_new(GTK_WINDOW_TOPLEVEL);	
	buffer = gtk_text_buffer_new(NULL);		
	view = gtk_text_view_new_with_buffer (buffer);	
	g_signal_connect_after (G_OBJECT(view), "button_press_event", 
G_CALLBACK(on_view_button_press_event), NULL);		
	gtk_container_add(GTK_CONTAINER(window), view);	
	gtk_widget_show(view);	
	gtk_widget_show(window);	
	
	gtk_main();	
	return 0;
}

void on_view_button_press_event (GtkWidget *widget, gpointer data) 
{
	gtk_main_quit();
}

