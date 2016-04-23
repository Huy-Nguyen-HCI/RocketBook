#ifndef DISPLAYGROUPGUI_H
#define DISPLAYGROUPGUI_H

#include <QWidget>
#include "../model/accountcontroller.h"

namespace Ui {
class DisplayGroupGUI;
}

class DisplayGroupGUI : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayGroupGUI(AccountController *inputAccountController, QWidget *parent = 0);
    ~DisplayGroupGUI();

private:
    Ui::DisplayGroupGUI *ui;
    AccountController* accountController;
    void refreshGroups();

private slots:
    void on_cell_clicked( int row, int column );
};

#endif // DISPLAYGROUPGUI_H
