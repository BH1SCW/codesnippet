#include <iostream>
#include <gtk/gtk.h>


extern "C" void hello() {
    std::cout << "hello" << '\n';
    GtkWidget *window;
    GtkWidget *label;

 //   gtk_init (NULL,NULL);
//#if GTK_CHECK_VERSION(2, 12, 0)
//         GtkTooltip *tooltips;
//#else
         GtkTooltips *tooltips;
//#endif
//     GtkWidget *notebook;
//#if GTK_CHECK_VERSION(2, 12, 0)
//#else
    tooltips = gtk_tooltips_new (); 
//#endif

//    notebook = gtk_notebook_new ();

    /* create the main, top level, window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    /* give it the title */
    gtk_window_set_title (GTK_WINDOW (window), "Hello World");

    /* Connect the destroy signal of the window to gtk_main_quit
     *      * When the window is about to be destroyed we get a notification and
     *           * stop the main GTK+ loop
     *                */
    g_signal_connect (window, "destroy",
            G_CALLBACK (gtk_main_quit), NULL);

    /* Create the "Hello, World" label  */
    label = gtk_label_new ("Hello, World");

    /* and insert it into the main window  */
    gtk_container_add (GTK_CONTAINER (window), label);

    /* make sure that everything, window and label, are visible */
    gtk_widget_show_all (window);

    /* start the main loop, and let it rest there until the application is closed */
//    gtk_main ();


}
