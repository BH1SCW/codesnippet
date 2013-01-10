using Gtk;

public void on_button_toggled(ToggleButton source)
{
    stdout.printf("ToggleButton toggled\n");
}

int main(string[] args)
{
    Gtk.init(ref args);

    var window = new Window();
    window.destroy.connect(Gtk.main_quit);

    var togglebutton = new ToggleButton.with_label("ToggleButton");
    togglebutton.toggled.connect(on_button_toggled);
    window.add(togglebutton);
    
    window.show_all();

    Gtk.main();
    return 0;
}
