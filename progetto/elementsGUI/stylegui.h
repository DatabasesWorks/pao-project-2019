#ifndef STYLEGUI_H
#define STYLEGUI_H

#include <QFont>
#include <QSize>
#include <QPalette>

/*
  Classe usata per avere dimensioni, font, palette, colori usati dall'applicazione
*/

class StyleGUI
{
public:
  // QFont
  static QFont smallFont;                // Font small:       "Arial", 8
  static QFont normalFont;               // Font normal:      "Arial", 10
  static QFont listFont;                 // Font QListWidget: "Arial", 12
  static QFont bigFont;                  // Font big:         "Arial", 20
  static QFont biggerFont;               // Font bigger:      "Arial", 24

  //QPalette
  static QPalette *disabled;             // Palette usato per i QPushButton disabilitati
  static QPalette *enabled;              // Palette usato per ripristinare il colore di StyleGUI::disabled
  static void setPalette();              // Funzione per settare il colore dei palette

  // QSize
  static QSize sizeListWidgetItem;       // Dimensione ComputerListItem in QListWidget
  static QSize sizeListWidgetItemIcon;   // Dimensione icona di un oggetto ComputerListItem di QListWidget
  static QSize imgLabelSize;             // Dimensione di imgLabel
  static QSize toolDialogSize;           // Dimensione ToolDialog
  static QSize warningDialogSize;        // Dimensione WarningDialog
  static QSize insLayoutSize;            // Dimensione InsLayout
  static QSize searchDialogSize;         // Dimensione SearchDialog
  static QSize infoLabelSize;            // Dimensione baseLayout -> infoLabel

  // Width
  static int listWidgetWidth;            // Width QListWidget
  static int warningDialogButtonWidth;   // Width WarningDialog button
  static int minWidthSortButton;         // Width sortButton
  static int minWidthButton;             // Width QPushButton

  // Height
  static int minHeightButton;            // Height QPushButton
  static int maxHeightBar;               // Height QMenuBar
  static int insLayoutLabelHeight;       // Height infoLabelInsLayout

  // QString
  static QString urlIcon;                // Path .qrc: icon.png
  static QString noitem;                 // Path .qrc: noitem.png
  static QString urlDesktop;             // Path .qrc: desktop.png
  static QString urlLaptop;              // Path .qrc: laptop.png
  static QString urlTablet;              // Path .qrc: tablet.png
  static QString urlDesktopIcon;         // Path .qrc: desktopIcon.png
  static QString urlLaptopIcon;          // Path .qrc: laptopIcon.png
  static QString urlTabletIcon;          // Path .qrc: tabletIcon.png
};

#endif // STYLEGUI_H
