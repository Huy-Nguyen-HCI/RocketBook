#include "chatgui.h"
#include "ui_chatgui.h"

ChatGUI::ChatGUI(AccountController *input, int chatId, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatGUI)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();

    this->setWindowTitle("title");//username + " 's Profile");
}

ChatGUI::~ChatGUI()
{
    delete ui;
}
