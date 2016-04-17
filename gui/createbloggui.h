#ifndef CREATEBLOGGUI_H
#define CREATEBLOGGUI_H

#include <QWidget>
#include "scrapbookgui.h"

class ScrapbookGUI;

namespace Ui {
class CreateBlogGUI;
}

class CreateBlogGUI : public QWidget
{
    Q_OBJECT

public:
    explicit CreateBlogGUI(ScrapbookGUI *input, QWidget *parent = 0);
    ~CreateBlogGUI();

private slots:
    void on_returnButton_clicked();

private:
    Ui::CreateBlogGUI *ui;
    ScrapbookGUI *scrapbook;
};

#endif // CREATEBLOGGUI_H
