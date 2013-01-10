#include <gtk/gtk.h>

gint key_press_cb(GtkWidget *widget, GdkEventKey *kevent, gpointer data)  {
    GtkWidget *btn = (GtkWidget *)data;
    
    if(kevent->type == GDK_KEY_PRESS)  {
        g_message("%04x, %c;", kevent->keyval, kevent->keyval);
    }

    // void g_signal_emit_by_name(GObject *object, const gchar *name, ... );
    // g_signal_emit_by_name(G_OBJECT(btn), "clicked", NULL);
    g_signal_emit_by_name(G_OBJECT(widget), "clicked", NULL);
g_signal_emit_by_name(G_OBJECT(widget), "activate", NULL);

    return TRUE;
}

static void
button_clicked_cb (GtkWidget *widget, void *data)
{
    g_message("clicked\n");
}
int main(int argc, char *argv[]) 
{
    GtkWidget *window, *button;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 100, 50);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    button = gtk_button_new_with_label("OK");

	g_signal_connect (G_OBJECT (button),
			  "clicked",
			  G_CALLBACK (button_clicked_cb),
			  NULL);

    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_container_add(GTK_CONTAINER(window), button);
    gtk_widget_show_all(window);

    // g_signal_connect(G_OBJECT(window), "key_press_event", G_CALLBACK(key_press_cb), button);
    g_signal_connect(G_OBJECT(button), "key_press_event", G_CALLBACK(key_press_cb), button);
    gtk_main();
    
    return 0;
}

