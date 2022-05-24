//
// my_widget.cpp
//

using namespace std;

#include "my_widget.h"

#include <qpainter.h>

MyMainWindow::MyMainWindow(QWidget* parent, const char* name)
:QMainWindow(parent, name)
{
	// load a bitmap and set its display position to (0,0)
	image = new QPixmap();
	image->load("c12.bmp");
	x = 0;
	y = 0;

	// create a timer to change the image display position.
	// note: timer should be destroyed automatically here,
	// and MyMainWindow's destructor is not required.
	// reference: http://doc.trolltech.com/3.2/qtimer.html
	timer = new QTimer(this);
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(UpdateImagePosition()));
    // start to generate timer events
    timer->start(1000 /* milliseconds */, false /* generate continously */);
}

MyMainWindow::~MyMainWindow()
{
	delete image;
}

void MyMainWindow::paintEvent(QPaintEvent* e)
{
	QPainter paint(this);
	paint.drawPixmap(x, y, (*image));
}

void MyMainWindow::UpdateImagePosition()
{
	// randomly assign the image display position
	x = (int)( (float) rand() / RAND_MAX * ( width() - image->width() ));
	y = (int)( (float) rand() / RAND_MAX * ( height() - image->height() ));
	// generate a paint request
	repaint();
}
