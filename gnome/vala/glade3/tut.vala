using Gtk;
using Cairo;


public class ChartApplication : GLib.Object
{
    const string GLADE  =  "tut.glade";

    public Gtk.Window      main_window        {get; set;}
           Gtk.DrawingArea chart_area;


    construct
    {
        try
        {
            Gtk.Builder builder  =  new Gtk.Builder ();
                        
                builder.add_from_file (GLADE);
                
                main_window  =  builder.get_object ("main_window") as Gtk.Window;
                chart_area   =  builder.get_object ("chart_area")  as Gtk.DrawingArea;
                                
                main_window.destroy.connect (Gtk.main_quit);
                builder.connect_signals (this);
                                
        } catch (Error e) 
          {
              stderr.printf ("Could not load UI: %s\n", e.message);
          }
    }
        

    [CCode (instance_pos = -1)]
    public bool on_chart_area_expose_event (Gtk.Widget source, Gdk.EventExpose event) 
    {
        Cairo.Context cairo  =  Gdk.cairo_create (source.window);
                
            cairo.set_source_rgb (0, 1, 0);
            cairo.paint ();
                        
        return true;
    }
}


int main (string[] args) 
{     
    Gtk.init (ref args);
    
    ChartApplication app  =  new ChartApplication();
        
        app.main_window.show_all ();
        Gtk.main ();

    return 0;
}

