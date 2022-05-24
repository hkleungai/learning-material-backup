#include <iostream>
using namespace std;

#include <qfiledialog.h>

#include "MazeWindow.h"

MazeWindow::MazeWindow(QWidget* parent, const char* name)
:QMainWindow(parent, name)
{
	CreateMenuBar();

	maze = new Maze(this);
	setCentralWidget(maze);

	// forward all keyboard events to maze
	setFocusProxy(maze);
	setFocusPolicy(QWidget::ClickFocus);
	maze->setFocus();
}

void MazeWindow::CreateMenuBar()
{
	QPopupMenu* file = new QPopupMenu(this);
	file->insertItem("Load Game...", this, SLOT(OnLoadGame()));
	file->insertItem("Exit", this, SLOT(OnExit()));
	menuBar()->insertItem("File", file);
}

void MazeWindow::OnLoadGame()
{
	QString f = QFileDialog::getOpenFileName("", "*.maze", this, 0, "Load Maze...");
	if (maze->Load(f)) {
		cout << f << " loaded" << endl;

		const int h = maze->GetPixelHeight() + menuBar()->height();
		this->resize(maze->GetPixelWidth(), h);
	} else {
		cerr << "error: cannot load a new game " << f << endl;
	}
}

void MazeWindow::OnExit()
{
	qApp->quit();
}

