/*
Compile with:
gcc -Wall -g -o combo_enter `pkg-config --cflags --libs gtk+-2.0` combo_enter.c

Note: gdk/gdkkeysyms is not included in gtk.h. It contains the keycodes we need
      to capture the "return" key being pressed.
*/
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

/* prototypes */
static void destroy (GtkWidget*, gpointer);
gboolean on_combo_key_press (GtkWidget *widget, GdkEventKey *event, gpointer user_data);

int main (int argc, char *argv[])
{
    GtkWidget       *window = NULL;
    GtkWidget       *combo = NULL;
   
    gtk_init (&argc, &argv);

    /* setup GtkWindow */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request (window, 150, 30);
    g_signal_connect (G_OBJECT (window), "destroy",
            G_CALLBACK (destroy), NULL);
 
    /* setup a test GtkComboBox */
    combo = gtk_combo_box_new_text ();
    gtk_combo_box_append_text (GTK_COMBO_BOX(combo), "test 1");
    gtk_combo_box_append_text (GTK_COMBO_BOX(combo), "test 2");
    g_signal_connect (G_OBJECT (combo), "key-press-event",
            G_CALLBACK (on_combo_key_press), NULL);
               
    gtk_container_add (GTK_CONTAINER (window), combo);
 
    /* show window */
    gtk_widget_show_all (window);
    gtk_main ();
   
    return 0;
}

static void
destroy (GtkWidget *window, gpointer data)
{
    gtk_main_quit ();
}

gboolean
on_combo_key_press (GtkWidget *widget, GdkEventKey *event, gpointer user_data)
{
    /* user has pressed a key on/in the GtkComboBox */
   
    if (event->keyval == GDK_Return)
    {
        /* user pressed the enter key */
        gchar *str = gtk_combo_box_get_active_text (GTK_COMBO_BOX(widget));
        g_print ("Value: %s\n", str);
        g_free (str);
       
        return TRUE;    /* don't let the box "drop down" */
    }
    else
    {
        return FALSE; /* propogate event */
    }
}

