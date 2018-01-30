#include "main.h"

MyApp :: MyApp()
{
	this->create_ui();
}

MyApp :: ~MyApp()
{
	/* Widgets */
	delete this->label;
	
	/* Menus */
	delete this->file_new_item;
	delete this->file_open_item;
	delete this->file_saveas_item;
	delete this->file_quit_item;
	
	delete this->file_menu;
	delete this->file_menu_item;
	delete this->menubar;
	
	/* Main */
	delete this->grid;
	delete this->root;
}

void MyApp :: create_ui()
{
	this->root = new Gtk::Window;
	this->root->set_title("MyApp");
	this->root->set_border_width(12);
	
	this->grid = new Gtk::Table;
	
	this->create_menus();
	
	/* Window Contents */
	this->label = new Gtk::Label("Contents");
	this->label->set_size_request(320, 240);
	
	this->grid->attach(*(this->label), 0, 1, 1, 2);
		
	this->root->add(*this->grid);
	this->root->show_all();
}

void MyApp :: create_menus()
{
	/* Expects ->grid to have been initialized */
	
	/* File menu */
	this->menubar   = new Gtk::MenuBar();
	
	this->file_menu = new Gtk::Menu();
	
	this->file_menu_item = new Gtk::MenuItem("_File", true);
	this->file_menu_item->set_submenu(*(this->file_menu));
	
	this->file_new_item = new Gtk::MenuItem("_New", true);
	this->file_new_item->signal_activate().connect(sigc::mem_fun(this, &MyApp::new_file));
	this->file_menu->append(*(this->file_new_item));
	this->file_open_item = new Gtk::MenuItem("_Open...", true);
	this->file_open_item->signal_activate().connect(sigc::mem_fun(this, &MyApp::open_dialog));
	this->file_menu->append(*(this->file_open_item));
	this->file_saveas_item = new Gtk::MenuItem("Save _as...", true);
	this->file_saveas_item->signal_activate().connect(sigc::mem_fun(this, &MyApp::saveas_dialog));
	this->file_menu->append(*(this->file_saveas_item));
	this->file_quit_item = new Gtk::MenuItem("_Quit", true);
	this->file_quit_item->signal_activate().connect(sigc::mem_fun(this, &MyApp::quit));
	this->file_menu->append(*(this->file_quit_item));
	
	this->menubar->append(*(this->file_menu_item));

	this->help_menu = new Gtk::Menu();
	this->help_menu_item = new Gtk::MenuItem("_Help", true);
	this->help_menu_item->set_right_justified(true);
	this->help_menu_item->set_submenu(*(this->help_menu));

	this->help_about_item = new Gtk::MenuItem("_About", true);
	this->help_about_item->signal_activate().connect(sigc::mem_fun(this, &MyApp::about));
	this->help_menu->append(*(this->help_about_item));
	
	this->menubar->append(*(this->help_menu_item));
	
	this->grid->attach(*(this->menubar), 0, 1, 0, 1);
}

void MyApp :: new_file()
{
	puts("Create new file");
}

void MyApp :: open_dialog()
{
	Gtk::FileChooserDialog dialog(*(this->root), "Open file", Gtk::FILE_CHOOSER_ACTION_OPEN);
	dialog.set_current_folder("~/");
	
	/* Add Buttons */
	dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
	dialog.add_button("_Open", Gtk::RESPONSE_OK);

	/* Add Filters */
	Gtk::FileFilter filter_textfile;
	filter_textfile.set_name("Text files");
	filter_textfile.add_mime_type("text/plain");
	dialog.add_filter(filter_textfile);

	int result = dialog.run();

	/* Handle the response */
	switch(result)
	{
		case Gtk::RESPONSE_OK:
		{
			this->load((char *) dialog.get_filename().c_str());
			break;
		}
		case Gtk::RESPONSE_CANCEL:
		{
			break;
		}
	}
}

void MyApp :: saveas_dialog()
{
	Gtk::FileChooserDialog dialog(*(this->root), "Save as", Gtk::FILE_CHOOSER_ACTION_SAVE);
	dialog.set_current_folder("~/");
	
	/* Add Buttons */
	dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
	dialog.add_button("_Save", Gtk::RESPONSE_OK);

	/* Add Filters */
	Gtk::FileFilter filter_textfile;
	filter_textfile.set_name("Text files");
	filter_textfile.add_mime_type("text/plain");
	dialog.add_filter(filter_textfile);

	int result = dialog.run();

	/* Handle the response */
	switch(result)
	{
		case Gtk::RESPONSE_OK:
		{
			this->save((char *) dialog.get_filename().c_str());
			break;
		}
		case Gtk::RESPONSE_CANCEL:
		{
			break;
		}
	}
}

void MyApp :: about()
{
	puts("About");
}

void MyApp :: load(char *path)
{
	printf("Loading %s\n", path);
}

void MyApp :: save(char *path)
{
	printf("Saving %s\n", path);
}

void MyApp :: run()
{
	Gtk::Main::run(*this->root);	
}

void MyApp :: quit()
{
	Gtk::Main::quit();
}

int main(int argc, char *argv[])
{
	Gtk::Main kit(argc, argv);

	MyApp app;
	
	if (argc >= 2) app.load(argv[1]);

	app.run();
	
	return 0;
}
