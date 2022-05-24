#include <iostream>
using namespace std;

#include "my_widget.h"

#include <qpainter.h>
#include <qmessagebox.h>

MyMainWindow::MyMainWindow(QWidget* parent, const char* name)
:QMainWindow(parent, name)
{
	image = new QPixmap();
	image->load("s1.JPG");
	x = 0;
	y = 0;
	step = 10;

    //setFocusPolicy(QWidget::ClickFocus);

}

MyMainWindow::~MyMainWindow()
{
	delete image;
}

void MyMainWindow::paintEvent(QPaintEvent* e)
{
	QPainter paint(this);
	if (! image->isNull())
	{
		paint.drawPixmap(x, y, (*image));
	}
}

void MyMainWindow::keyPressEvent(QKeyEvent* e)
{
	const int k = e->key();

	switch (k)
	{
	case Qt::Key_Left:  
		{
			if (x - step >= 0) 
				x = x - step;
			else 
				x = 0;
			break;		
		}
	case Qt::Key_Up: 
		{   
			if (y - step >= 0) 
				y = y - step; 
			else
				y = 0;
			break;	
		}			
	case Qt::Key_Right: 
		{
			if (x+image->width()+step <= this->width()) 
				x = x + step; 
			else
				x = this->width() - image->width();
			break; 
		}
	case Qt::Key_Down: 
		{ 
		    if (y+image->height()+step <= this->height()) 
			    y = y + step; 
		    else
                y = this->height() - image->height();
		    break; 
		}
	}
	cout << "Position: (" << x << ", " << y << ")" << endl;
	repaint();
}