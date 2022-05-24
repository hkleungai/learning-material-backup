#include <iostream>
using namespace std;

#include "my_widget.h"

#include <qfiledialog.h>
#include <qpainter.h>
#include <qmessagebox.h>

MyMainWindow::MyMainWindow(QWidget* parent, const char* name)
:QMainWindow(parent, name)
{
	QPopupMenu* file = new QPopupMenu(this);
	file->insertItem("Load image...", this, SLOT(OnLoadImage()));
	menuBar()->insertItem("File", file);

	image = new QPixmap();
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
		paint.drawPixmap(0, menuBar()->height(), (*image));
	}
}

void MyMainWindow::OnLoadImage()
{
	QString s = QFileDialog::getOpenFileName("", "*.bmp", this, "", "Load image...");
	if (! s.isNull())
	{
		image->load(s);
	}
}

void MyMainWindow::mousePressEvent(QMouseEvent * e)
{
	QMessageBox::about( this, "bitmap", "Mouse click event!");
}
