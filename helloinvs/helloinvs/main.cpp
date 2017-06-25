#include "helloinvs.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	helloinvs w;
	w.show();
	return a.exec();
}
