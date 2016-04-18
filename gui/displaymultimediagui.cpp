#include "displaymultimediagui.h"
#include "ui_displaymultimediagui.h"

DisplayMultimediaGUI::DisplayMultimediaGUI(ScrapbookGUI *input, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayMultimediaGUI)
{
    ui->setupUi(this);
    scrapbook = input;
}

DisplayMultimediaGUI::~DisplayMultimediaGUI()
{
    delete ui;
}

void DisplayMultimediaGUI::on_postButton_clicked()
{
    scrapbook->switchMultimediaViews();
}
