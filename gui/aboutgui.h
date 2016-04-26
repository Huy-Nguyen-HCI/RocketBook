#ifndef ABOUTGUI_H
#define ABOUTGUI_H

#include <QWidget>
#include <map>

namespace Ui {
class AboutGUI;
}

class AboutGUI : public QWidget
{
    Q_OBJECT

public:
    explicit AboutGUI(QWidget *parent = 0);
    ~AboutGUI();

private:
    Ui::AboutGUI *ui;
    std::map<QString, QString> setupMap();
};

#endif // ABOUTGUI_H
