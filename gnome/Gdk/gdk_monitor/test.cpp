#include <gtkmm.h>
#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
	Gtk::Main lKit(argc, argv);
	std::vector<Gtk::Window *> lWindows;

	Glib::RefPtr<Gdk::Display> lDisplay = Gdk::Display::get_default();
	int lScreenCount = lDisplay->get_n_screens();

	std::cout << "Display has " << lScreenCount << " screens\n";
	for (int s = 0; s < lScreenCount; s++)
	{
		Glib::RefPtr<Gdk::Screen> lScreen = lDisplay->get_screen(s);
		int lMonitorCount = lScreen->get_n_monitors();
		std::cout << "    Screen " << s << " has " << lMonitorCount << " monitors\n";
		for (int m = 0; m < lMonitorCount; m++)
		{
			std::cout << "        Opening window on Screen " << s << ", monitor " << m << std::endl;   
			Gtk::Window *lWindow = new Gtk::Window;
			lWindow->set_screen(lScreen);
			Gdk::Rectangle lMonitorRect;
			lScreen->get_monitor_geometry(m, lMonitorRect);
			lWindow->move(lMonitorRect.get_x(), lMonitorRect.get_y());
			lWindow->fullscreen();
			lWindow->show();

			lWindows.push_back(lWindow);

		}
	}

	Gtk::Main::run();
}

