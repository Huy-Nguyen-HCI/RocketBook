#include "scrapbook.h"
#include "ui_scrapbook.h"

Scrapbook::Scrapbook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Scrapbook)
{
    ui->setupUi(this);
}

Scrapbook::~Scrapbook()
{
    delete ui;
}
