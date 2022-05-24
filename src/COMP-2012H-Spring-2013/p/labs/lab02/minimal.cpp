#include <qapplication.h>
#include <qlabel.h>

int main(int argc, char* argv[])
{
	// Create an application object.
	QApplication a(argc, argv);

	// Create a label.
	// The second parameter should be its parent widget.
	// Since it's the main widget and has no parent,
	// we just set it to NULL.
	QLabel* label = new QLabel("Hello", NULL);

	// To set the label as the main UI component.
	a.setMainWidget(label);

	// Resize the label
	label->resize(120, 30);

	// Let the system to draw the label in the application.
	label->show();

	// enter the window event loop
	return a.exec();
};
