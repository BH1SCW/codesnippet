#include <gtk/gtk.h>

void on_view_button_press_event (GtkWidget *widget, gpointer data);
static void
button_clicked_cb (GtkWidget *widget, void *data)
{
    g_message("clicked\n");
}

void key_press_cb(G_GNUC_UNUSED GtkWidget *widget, GdkEventKey *event, gpointer data) {

    GtkWidget *button = (GtkWidget *)data;
    g_printerr("%s: keyval=%04x state=0x%04x\n",
            event->type == GDK_KEY_PRESS ? "press" : "release",
            event->keyval, event->state);
    g_printerr("%s: keyval=%04x state=0x%04x\n",
            event->type == GDK_KEY_RELEASE ? "press" : "release",
            event->keyval, event->state);

    if (0xff0d == event->keyval && event->type == GDK_KEY_PRESS) {
        g_signal_emit_by_name(G_OBJECT(button), "clicked", NULL);
    }


    //g_signal_emit_by_name(G_OBJECT(button), "clicked", NULL);
//    g_signal_emit_by_name(G_OBJECT(button), "activate", NULL);

    return FALSE;

}

int main (int argc, char *argv[])
{
	GtkWidget *window, *view, *button;	
	GtkWidget *box;	
	GtkTextBuffer *buffer;	
    GtkWidget *entry1;

	gtk_init(&argc, &argv);		
	window =gtk_window_new(GTK_WINDOW_TOPLEVEL);	
    gtk_window_set_default_size(GTK_WINDOW(window), 100, 50);
    box = gtk_hbox_new(FALSE,3);

    entry1 = gtk_entry_new();
    button = gtk_button_new_with_label("OK");

    //g_signal_connect_after(G_OBJECT(entry1), "key_press_event", G_CALLBACK(key_press_cb), button);
    g_signal_connect (G_OBJECT(entry1), "key_press_event", G_CALLBACK(key_press_cb), button);
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (button_clicked_cb), NULL);


    gtk_box_pack_start(GTK_BOX(box),entry1,FALSE,FALSE,3);
    gtk_box_pack_start(GTK_BOX(box),button,FALSE,FALSE,3);

    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_container_add(GTK_CONTAINER(window), box);

    //g_signal_connect_after (G_OBJECT(view), "button_press_event", G_CALLBACK(on_view_button_press_event), NULL);		
    g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    

    gtk_widget_show_all(window);
	gtk_main();	
	return 0;
}

void on_view_button_press_event (GtkWidget *widget, gpointer data) 
{
	gtk_main_quit();
}

