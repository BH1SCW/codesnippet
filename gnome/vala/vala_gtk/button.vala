using Gtk;

public void on_button_clicked(Button source)
{
    stdout.printf("Button clicked\n");
}

int main(string[] args)
{
    Gtk.init(ref args);

    var window = new Window();
    window.destroy.connect(Gtk.main_quit);

    var button = new Button.with_label("Button");
    button.clicked.connect(on_button_clicked);
    window.add(button);
    
    window.show_all();

    Gtk.main();
    return 0;
}
