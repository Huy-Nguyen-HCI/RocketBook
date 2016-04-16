#ifndef CREATEACCOUNTGUI_H
#define CREATEACCOUNTGUI_H

#include <QWidget>

namespace Ui {
class CreateAccountGUI;
}

class CreateAccountGUI : public QWidget
{
    Q_OBJECT

public:
    explicit CreateAccountGUI(QWidget *parent = 0);
    ~CreateAccountGUI();

private:
    Ui::CreateAccountGUI *ui;
};

#endif // CREATEACCOUNTGUI_H
