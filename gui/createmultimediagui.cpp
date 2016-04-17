#include "createmultimediagui.h"
#include "ui_createmultimediagui.h"

CreateMultimediaGUI::CreateMultimediaGUI(ScrapbookGUI *input, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateMultimediaGUI)
{
    ui->setupUi(this);
    scrapbook = input;
}

CreateMultimediaGUI::~CreateMultimediaGUI()
{
    delete ui;
}

void CreateMultimediaGUI::on_returnButton_clicked()
{
    scrapbook->switchMultimediaViews();
}
