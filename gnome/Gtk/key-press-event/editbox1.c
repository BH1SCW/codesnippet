#include <gtk/gtk.h> 
#include <stdio.h> 
#include <string.h> 
gint   test(GtkWidget*   widget, GdkEventKey*   event,gpointer   data) 
{  
    static   gchar   tmp[2]; 
    static   gchar   password[1024]= " "; 
    gchar   c; 
     
    if(event->keyval == 0xff0d) // linux下回车是'/r'
    { 
        printf( "Enter pressed \n "); 
        return FALSE;
    } 

    //event->keyval='*'; 
    return   0; 
}
int   main(int   argc,char*   argv[]) 
{ 
    GtkWidget   *window,*box,*entry; 
    gtk_set_locale(); 
    gtk_init(&argc,&argv);
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL); 
    gtk_window_set_title(GTK_WINDOW(window), "Enter   Password ");
    box=gtk_vbox_new(FALSE,0); 
    gtk_container_add(GTK_CONTAINER(window),box);
    entry=gtk_entry_new(); 
    gtk_entry_set_text(GTK_ENTRY(entry), " "); 
    gtk_editable_select_region(GTK_EDITABLE(entry),0,-1);
    gtk_box_pack_start(GTK_BOX(box),entry,TRUE,TRUE,0);
    // g_signal_connect(G_OBJECT(entry), "key_press_event",G_CALLBACK(test),NULL); 
    gtk_key_snooper_install(test,(gpointer)NULL); // 会同时捕捉按键和释放两个信号
    gtk_widget_show_all(window); 
    gtk_main(); 
    return   0; 
}

