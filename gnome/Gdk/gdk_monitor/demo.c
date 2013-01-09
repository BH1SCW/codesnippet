#include <gtk/gtk.h>
#include <gdk/gdk.h>

void resize_cb(GdkScreen *screen, gpointer user_data)
{
    GtkWindow*window;
    gint w, wh;

    window = GTK_WINDOW(user_data);
    w = gdk_screen_get_width(screen);
    gtk_window_get_size(window, NULL, &wh);
    gtk_window_resize(window, w, wh);
}

int main(int argc, char **argv)
{
    GtkWidget *window;
    GdkScreen *screen;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(window), "delete-event", G_CALLBACK(gtk_main_quit), NULL);

    screen = gdk_screen_get_default();
    g_signal_connect(G_OBJECT(screen), "size-changed", G_CALLBACK(resize_cb), (gpointer)window);

    gtk_widget_show(window);

    gtk_main();
    return 0;
}

