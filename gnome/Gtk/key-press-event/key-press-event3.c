#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h> //用第二种方法时要用到的头文件

/*第一种方法的处理函数
void key_enter(GtkWidget *widget,gpointer data)
{
gtk_widget_grab_focus(data);
}
*/

//下面为第二种方法的处理函数
void key_enter(GtkWidget *widget,GdkEventKey *event,gpointer data)
{
if(event->keyval==GDK_KP_Enter)
gtk_widget_grab_focus(data);
}
int main(int argc,char *argv[])
{
GtkWidget *window;
GtkWidget *box;
GtkWidget *entry[3];
int i;

gtk_init(&argc,&argv);

window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_widget_set_usize(window,500,300);
gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);

box=gtk_hbox_new(FALSE,3);
for(i=0;i<3;i++)
{
entry[i]=gtk_entry_new();
gtk_box_pack_start(GTK_BOX(box),entry[i],FALSE,FALSE,3);
}

gtk_container_set_border_width(GTK_CONTAINER(box),3);
gtk_container_add(GTK_CONTAINER(window),box);
/*第一种方法的函数调用，捕捉activate信号
g_signal_connect(G_OBJECT(entry[0]),"activate",G_CALLBACK(key_enter),entry[1]);
g_signal_connect(G_OBJECT(entry[1]),"activate",G_CALLBACK(key_enter),entry[2]);
g_signal_connect(G_OBJECT(entry[2]),"activate",G_CALLBACK(key_enter),entry[0]);
*/

//下面的为第二种方法的调用，捕捉“key_press_event"信号
g_signal_connect(G_OBJECT(entry[0]),"key_press_event",G_CALLBACK(key_enter),entry[1]);
g_signal_connect(G_OBJECT(entry[1]),"key_press_event",G_CALLBACK(key_enter),entry[2]);
g_signal_connect(G_OBJECT(entry[2]),"key_press_event",G_CALLBACK(key_enter),entry[0]);

g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);

gtk_widget_show_all(window);

gtk_main();

return FALSE;
}

