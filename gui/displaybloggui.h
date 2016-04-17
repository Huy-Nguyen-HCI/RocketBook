#ifndef DISPLAYBLOGGUI_H
#define DISPLAYBLOGGUI_H

#include <QWidget>
#include "scrapbookgui.h"

class ScrapbookGUI;

namespace Ui {
class DisplayBlogGUI;
}

class DisplayBlogGUI : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayBlogGUI(ScrapbookGUI *input, QWidget *parent = 0);
    ~DisplayBlogGUI();

private slots:
    void on_createBlog_clicked();

private:
    Ui::DisplayBlogGUI *ui;
    ScrapbookGUI *scrapbook;
};

#endif // DISPLAYBLOGGUI_H
