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

class CreateMultimediaGUI : public QWidget
{
    Q_OBJECT

public:
    explicit CreateMultimediaGUI(AccountController *inputAcc, ScrapbookGUI *input, QWidget *parent = 0);
    ~CreateMultimediaGUI();

private slots:
    void on_returnButton_clicked();

    void on_uploadVideoButton_clicked();

    void on_uploadPhotoButton_clicked();

    void on_filePathBox_returnPressed();


    void on_publishButton_clicked();

private:
    Ui::CreateMultimediaGUI *ui;
    ScrapbookGUI *scrapbook;
    QString filePath;
    AccountController *accountController;
};


#endif // CREATEMULTIMEDIAGUI_H
