#ifndef BLOGGUI_H
#define BLOGGUI_H

#include <QWidget>

namespace Ui {
class BlogGUI;
}

class BlogGUI : public QWidget
{
    Q_OBJECT

public:
    explicit BlogGUI(QWidget *parent = 0);
    ~BlogGUI();

private:
    Ui::BlogGUI *ui;
};

#endif // BLOGGUI_H
