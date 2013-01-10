using Gtk;

public void on_entry_activated(Entry source)
{
    stdout.printf("Entry activated\n");
}

int main(string[] args)
{
    Gtk.init(ref args);

    var window = new Window();
    window.destroy.connect(Gtk.main_quit);
    
    var entry = new Entry();
    entry.activate.connect(on_entry_activated);
    window.add(entry);
    
    window.show_all();

    Gtk.main();
    return 0;
}
