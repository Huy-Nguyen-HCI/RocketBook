#ifndef DISPLAYMULTIMEDIAGUI_H
#define DISPLAYMULTIMEDIAGUI_H

#include <QDebug>

#include <QWidget>
#include <QListWidgetItem>
#include "scrapbookgui.h"
#include "../model/accountcontroller.h"
//#include "viewmultimediaitem.h"
//#include "multimediaitem.h"

class MultimediaItem;
class ScrapbookGUI;

namespace Ui {
class DisplayMultimediaGUI;
}

class DisplayMultimediaGUI : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief DisplayMultimediaGUI the class constructor.
     * @param inputScrapbook pointer to the scrapbook that contains information about the user.
     * @param input the corresponding scrapbook GUI.
     * @param parent the QWidget parent.
     */
    explicit DisplayMultimediaGUI(Scrapbook *inputScrapbook, ScrapbookGUI *input, QWidget *parent = 0);

    /**
      * @brief ~DisplayMultimediaGUI the class destructor. Delete the pointer to ui.
      */
    ~DisplayMultimediaGUI();

    /**
     * @brief refreshMultimedia refresh the view.
     */
    void refreshMultimedia();

private slots:
    /**
     * @brief on_postButton_clicked segue to the add multimedia view.
     */
    void on_postButton_clicked();

    /**
     * @brief on_loadButton_clicked
     */
    void on_loadButton_clicked();

    /**
     * @brief on_viewButton_clicked create a new view to display the media in more detail.
     */
    void on_viewButton_clicked();

    /**
     * @brief on_editButton_clicked segue to the edit media view.
     */
    void on_editButton_clicked();

    /**
     * @brief on_deleteButton_clicked delete the media content from the database.
     */
    void on_deleteButton_clicked();

private:
    Ui::DisplayMultimediaGUI *ui;
    ScrapbookGUI *scrapbookGUI;
    Scrapbook *scrapbook;
    std::vector<Multimedia*> allMulti;
};

#endif // DISPLAYMULTIMEDIAGUI_H
