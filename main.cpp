#include "main.h"

MyApp :: MyApp()
{
	this->root = new Gtk::Window;
	this->root->set_title("MyApp");
	this->root->set_border_width(12);
	
	this->grid = new Gtk::Table;
	
	this->label = new Gtk::Label("Contents");
	this->label->set_size_request(320, 240);
	
	this->grid->attach(*(this->label), 0, 1, 0, 1);
	
	this->root->add(*this->grid);
	this->root->show_all();
}

MyApp :: ~MyApp()
{
	delete this->label;
	
	delete this->grid;
	delete this->root;
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

int main(int argc, char *argv[])
{
	Gtk::Main kit(argc, argv);

	MyApp app;
	
	if (argc >= 2) app.load(argv[1]);

	app.run();
	
	return 0;
}
