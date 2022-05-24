#include <qapplication.h>

#include "MazeWindow.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	MazeWindow* w = new MazeWindow();
	a.setMainWidget(w);
	w->show();
	return a.exec();
};
