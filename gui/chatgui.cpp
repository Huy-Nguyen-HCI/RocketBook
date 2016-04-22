#include "chatgui.h"
#include "ui_chatgui.h"

ChatGUI::ChatGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatGUI)
{
    ui->setupUi(this);
}

ChatGUI::~ChatGUI()
{
    delete ui;
}
