#include "stylegui.h"

// QFont
QFont StyleGUI::smallFont = QFont("Arial", 8);
QFont StyleGUI::normalFont = QFont("Arial", 10);
QFont StyleGUI::listFont = QFont("Arial", 12);
QFont StyleGUI::bigFont = QFont("Arial", 20);
QFont StyleGUI::biggerFont = QFont("Arial", 24);

//QPalette
QPalette *StyleGUI::disabled = new QPalette();
QPalette *StyleGUI::enabled = new QPalette();

void StyleGUI::setPalette()
{
  disabled->setColor(QPalette::Base, Qt::gray);
  disabled->setColor(QPalette::Text, Qt::darkGray);
  enabled->setColor(QPalette::Base, Qt::white);
  enabled->setColor(QPalette::Text, Qt::black);
}

// QSize
QSize StyleGUI::sizeListWidgetItem = QSize(-1, 50);
QSize StyleGUI::sizeListWidgetItemIcon = QSize(32, 32);
QSize StyleGUI::imgLabelSize = QSize(264, 264);
QSize StyleGUI::toolDialogSize = QSize(220, 120);
QSize StyleGUI::warningDialogSize = QSize(280, 120);
QSize StyleGUI::insLayoutSize = QSize(300, 550);
QSize StyleGUI::searchDialogSize = QSize(300, 310);
QSize StyleGUI::infoLabelSize = QSize(264, 170);
// Width
int StyleGUI::listWidgetWidth = 350;
int StyleGUI::warningDialogButtonWidth = 50;
int StyleGUI::minWidthSortButton = 100;
int StyleGUI::minWidthButton = 250;

// Height
int StyleGUI::minHeightButton = 40;
int StyleGUI::maxHeightBar = 20;
int StyleGUI::insLayoutLabelHeight = 45;

// QString
QString StyleGUI::urlIcon = ("://assets/icon.png");
QString StyleGUI::noitem = ("://assets/noitem.png");
QString StyleGUI::urlDesktop = ("://assets/desktop.png");
QString StyleGUI::urlLaptop = ("://assets/laptop.png");
QString StyleGUI::urlTablet = ("://assets/tablet.png");
QString StyleGUI::urlDesktopIcon = ("://assets/desktopIcon.png");
QString StyleGUI::urlLaptopIcon = ("://assets/laptopIcon.png");
QString StyleGUI::urlTabletIcon = ("://assets/tabletIcon.png");
