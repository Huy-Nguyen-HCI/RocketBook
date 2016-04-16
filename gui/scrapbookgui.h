#ifndef SCRAPBOOKGUI_H
#define SCRAPBOOKGUI_H

#include <QWidget>

namespace Ui {
class ScrapbookGUI;
}

class ScrapbookGUI : public QWidget
{
    Q_OBJECT

public:
    explicit ScrapbookGUI(QWidget *parent = 0);
    ~ScrapbookGUI();

private:
    Ui::ScrapbookGUI *ui;
};

#endif // SCRAPBOOKGUI_H
