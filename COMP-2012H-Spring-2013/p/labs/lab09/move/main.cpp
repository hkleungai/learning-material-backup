#include <qapplication.h>

#include "my_widget.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	QWidget* w = new MyMainWindow();
	a.setMainWidget(w);
	w->show();
	return a.exec();
};
