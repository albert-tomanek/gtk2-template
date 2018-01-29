#ifndef MAIN_H
#define MAIN_H

#include <gtkmm.h>

class MyApp
{
	Gtk::Window *root;
	Gtk::Table  *grid;
	
	Gtk::Label *label;
		
public:
	MyApp();
	~MyApp();
	
	void load(char *path);
	void save(char *path);
	
	void run();
};

#endif
