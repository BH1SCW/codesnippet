using Gtk;

int main(string[] args)
{
    Gtk.init(ref args);

    var window = new Window();
    window.destroy.connect(Gtk.main_quit);
    
    window.show_all();

    Gtk.main();
    return 0;
}
