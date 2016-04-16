#include "createmultimediagui.h"
#include "ui_createmultimediagui.h"

CreateMultimediaGUI::CreateMultimediaGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateMultimediaGUI)
{
    ui->setupUi(this);
}

CreateMultimediaGUI::~CreateMultimediaGUI()
{
    delete ui;
}
