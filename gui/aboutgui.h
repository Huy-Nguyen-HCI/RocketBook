#ifndef ABOUTGUI_H
#define ABOUTGUI_H

#include <QWidget>
#include <map>

namespace Ui {
class AboutGUI;
}

/**
 * @brief The AboutGUI class
 * This class shows the about page for the GUI
 */
class AboutGUI : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief AboutGUI
     * @param parent The parent widget, default value is 0
     *
     * Default constructor of AboutGUI
     */
    explicit AboutGUI(QWidget *parent = 0);

    ~AboutGUI();

private:
    Ui::AboutGUI *ui;
    std::map<QString, QString> setupMap();
};

#endif // ABOUTGUI_H
