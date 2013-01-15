using Gtk;

int main(string[] args)
{
    Gtk.init(ref args);
    
    var aboutdialog = new AboutDialog();
    aboutdialog.set_program_name("Vala GTK Tutorial");
    aboutdialog.set_version("1.0");
    aboutdialog.set_website("http://learngtk.org/");
    
    aboutdialog.run();
    aboutdialog.destroy();
    
    return 0;
}
