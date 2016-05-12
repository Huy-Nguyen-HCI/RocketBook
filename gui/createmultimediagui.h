#ifndef CREATEMULTIMEDIAGUI_H
#define CREATEMULTIMEDIAGUI_H

#include <QWidget>
#include <QFileDialog>
#include "scrapbookgui.h"
#include "../model/accountcontroller.h"


class ScrapbookGUI;

namespace Ui {
class CreateMultimediaGUI;
}

/**
 * @brief The CreateMultimediaGUI class is a controller class for user to input information and post a new multimedia item, either photo or video
 */
class CreateMultimediaGUI : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief CreateMultimediaGUI default constructor
     * @param currentAccount The current account that is creating the multimedia post
     * @param inputScrapbook The scrapbook the post is posted to
     * @param input The GUI to return to
     * @param parent
     */
    explicit CreateMultimediaGUI(AccountController *currentAccount, Scrapbook *inputScrapbook, ScrapbookGUI *input, QWidget *parent = 0);
    ~CreateMultimediaGUI();
    void clearViews();

private slots:
    /**
     * @brief on_returnButton_clicked
     * Return to previous window
     */
    void on_returnButton_clicked();

    /**
     * @brief on_uploadPhotoButton_clicked
     * Upload a photo
     */
    void on_uploadPhotoButton_clicked();

    /**
     * @brief on_filePathBox_returnPressed
     * Accept the file path
     */
    void on_filePathBox_returnPressed();

    /**
     * @brief on_publishButton_clicked add the media to the database and display it in the view.
     */
    void on_publishButton_clicked();

private:
    Ui::CreateMultimediaGUI *ui;
    ScrapbookGUI *scrapbookGUI;
    QString filePath;
    AccountController *accountController;
    Scrapbook* scrapbook;
};


#endif // CREATEMULTIMEDIAGUI_H
