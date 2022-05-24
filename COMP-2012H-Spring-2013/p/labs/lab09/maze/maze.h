#include <qwidget.h>
#include <cassert>
#include <vector>
using namespace std;

#ifndef _MAZE_H
#define _MAZE_H

// the coordinate system is:
// (x = 0, y = 0) is at the top-left corner.
// x is the horizontal axis, y is the vertical axis.

class Maze;

class Cell {
	friend class Maze;

	public:

	int GetX() const { return x; }
	int GetY() const { return y; }

	private:
	enum State {State_Wall, State_Empty};
	State state;

	int x, y;
};

class Maze: public QWidget
{
	Q_OBJECT

	public:
	// constructor
	Maze(QWidget* parent = 0, const char* name = 0);

	// destructor
	~Maze();

	// load the maze information from filename
	bool Load(const char* filename);

	///////////////////
	// event handlers
	///////////////////
	virtual void paintEvent(QPaintEvent* e);

	Cell* GetCell(int x, int y);

	// get the graphical width/height of this widget
	int GetPixelWidth() const;
	int GetPixelHeight() const;

	private:

	vector<vector<Cell> > cells;
	int numOfColumn;
	int numOfRow;
};

#endif
