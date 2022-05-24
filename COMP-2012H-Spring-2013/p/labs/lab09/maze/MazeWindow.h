#include <qstring.h>
#include <qmainwindow.h>
#include <qpopupmenu.h>
#include <qmenubar.h>
#include <qapplication.h>

#include "maze.h"

#ifndef _MAZEWINDOW_H
#define _MAZEWINDOW_H

class MazeWindow: public QMainWindow
{
	Q_OBJECT

	public:
	MazeWindow(QWidget* parent = 0, const char* name = 0);

	public slots:
	void OnLoadGame();
	void OnExit();

	private:
	void CreateMenuBar();
	Maze* maze;
};

#endif
