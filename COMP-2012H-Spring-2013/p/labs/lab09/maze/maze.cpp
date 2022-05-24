#include <qpainter.h>
#include <qtimer.h>
#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;

#include "maze.h"

const int BUFFER_SIZE=4096;
const int CELL_WIDTH=26; 
const int CELL_HEIGHT=26;


Maze::Maze(QWidget* parent, const char* name)
:QWidget(parent, name)
{
    numOfColumn = 0;
    numOfRow = 0;
}

Maze::~Maze()
{
}

bool Maze::Load(const char* filename)
{
	ifstream fin(filename);
	if (! fin) {
		cerr << "error: cannot load " << filename << endl;
		return false;
	}

	int x, y;
	char buffer[BUFFER_SIZE];

	fin >> numOfColumn >> numOfRow;
	fin.getline(buffer, BUFFER_SIZE); // remove the '\n'
	
	cout << "number of column = " << numOfColumn << endl;
	cout << "number of row = " << numOfRow << endl;

	// build a 2D array
	cells.resize(numOfColumn);
	for (x = 0; x < numOfColumn; ++x) {
		cells[x].resize(numOfRow);
	}

	// load the values to the array
	for (y = 0; y < numOfRow; ++y) {
		fin.getline(buffer, BUFFER_SIZE);
		for (x = 0; x < numOfColumn; ++x) {
			char ch = buffer[x];

			Cell* pC = GetCell(x, y);
			pC->x = x;
			pC->y = y;

			if (ch == 'x') {
				pC->state = Cell::State_Wall;
			} else if (ch == ' ') {
				pC->state = Cell::State_Empty;
			} 
			else {
				assert(false);
			}
		}
	}
	fin.close();

	// resize the window according to the dimension of the maze
	this->resize(numOfColumn * CELL_WIDTH, numOfRow * CELL_HEIGHT);

	repaint();

	return true;
}

void Maze::paintEvent(QPaintEvent* e)
{

	QPainter paint(this);

	int x, y;
	for (y = 0; y < numOfRow; ++y) {
		for (x = 0; x < numOfColumn; ++x) {
			Cell* pC = GetCell(x, y);

			QColor color;

			switch (pC->state)
			{
				case Cell::State_Wall:
				{
					color.setRgb(200, 0, 0);  //red color for wall
					break;
				}
				case Cell::State_Empty:
				{
   					color.setRgb(0, 0, 0);  // black color for space
                }
			}

			paint.fillRect(x * CELL_WIDTH, y * CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, color);
		}
	}	
}

Cell* Maze::GetCell(int col, int row) {
	return &(cells[col][row]);
}


int Maze::GetPixelWidth() const {
	return numOfColumn * CELL_WIDTH;
}

int Maze::GetPixelHeight() const {
	return numOfRow * CELL_HEIGHT;
}

