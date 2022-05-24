#include <qmainwindow.h>
#include <qapplication.h>
#include <qpixmap.h>

#ifndef _MY_WIDGET_H
#define _MY_WIDGET_H

class MyMainWindow: public QMainWindow {
	// All classes that contain signals or slots
	// must mention Q_OBJECT in their declaration.
	Q_OBJECT

	public:
	MyMainWindow(QWidget* parent = 0, const char* name = 0);
	~MyMainWindow();

	/** event handler */
	virtual void paintEvent(QPaintEvent* e);
	virtual void keyPressEvent(QKeyEvent* e);

	private:
	QPixmap* image;
	int x,y;  //current position of the image
	int step; //moving step
};

#endif
