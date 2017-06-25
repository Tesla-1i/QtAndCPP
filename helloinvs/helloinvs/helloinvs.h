#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_helloinvs.h"

class helloinvs : public QMainWindow
{
	Q_OBJECT

public:
	helloinvs(QWidget *parent = Q_NULLPTR);

private:
	Ui::helloinvsClass ui;
};
