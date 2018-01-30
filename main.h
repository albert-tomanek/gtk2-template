#ifndef MAIN_H
#define MAIN_H

#include <gtkmm.h>
#include <gtkmm/window.h>

class MyApp
{
	Gtk::Window *root;
	Gtk::Table  *grid;
	
	Gtk::Label *label;
	
	/* File Menu */
	Gtk::MenuBar  *menubar;
	
	Gtk::Menu     *file_menu;
	Gtk::MenuItem *file_menu_item;
	
	Gtk::MenuItem *file_new_item;
	Gtk::MenuItem *file_open_item;
	Gtk::MenuItem *file_saveas_item;
	Gtk::MenuItem *file_quit_item;

	Gtk::Menu     *help_menu;
	Gtk::MenuItem *help_menu_item;
	
	Gtk::MenuItem *help_about_item;
	
	/* Methods */
	void create_ui();
	void create_menus();
			
public:
	MyApp();
	~MyApp();
	
	void new_file();
	void open_dialog();
	void saveas_dialog();
	void about();
	
	void load(char *path);
	void save(char *path);
	
	void run();
	void quit();
};

#endif
