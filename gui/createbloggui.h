#ifndef CREATEBLOGGUI_H
#define CREATEBLOGGUI_H

#include <QWidget>

namespace Ui {
class CreateBlogGUI;
}

class CreateBlogGUI : public QWidget
{
    Q_OBJECT

public:
    explicit CreateBlogGUI(QWidget *parent = 0);
    ~CreateBlogGUI();

private:
    Ui::CreateBlogGUI *ui;
};

#endif // CREATEBLOGGUI_H
