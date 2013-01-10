#include <gtk/gtk.h>

static gboolean
key_event(G_GNUC_UNUSED GtkWidget *widget,
          GdkEventKey *event)
{
    g_printerr("%s: keyval=%04x state=0x%04x\n",
               event->type == GDK_KEY_PRESS ? "press" : "release",
               event->keyval, event->state);
    g_printerr("%s: keyval=%04x state=0x%04x\n",
               event->type == GDK_KEY_RELEASE ? "press" : "release",
               event->keyval, event->state);
    return FALSE;
}

int
main(int argc, char *argv[])
{
    GtkWidget *window, *view;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 320, 240);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    view = gtk_text_view_new();
    g_signal_connect(view, "key-press-event", G_CALLBACK(key_event), NULL);
    g_signal_connect(view, "key-release-event", G_CALLBACK(key_event), NULL);
    gtk_container_add(GTK_CONTAINER(window), view);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

