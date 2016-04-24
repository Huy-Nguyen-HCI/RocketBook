#include "chatgui.h"
#include "ui_chatgui.h"

ChatGUI::ChatGUI(AccountController *input, int chatId, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatGUI)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
        accountController = input;
        this->chatId=chatId;
        refreshMembers();
        refreshMessages();
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(refreshMessages()));
        connect(timer, SIGNAL(timeout()), this, SLOT(refreshMembers()));
        timer->start(5000);

    this->setWindowTitle("chat name");//username + " 's Profile");
}

ChatGUI::~ChatGUI()
{
    delete ui;
    delete timer;
}

void ChatGUI::refreshMessages() {

    RocketUser *user = accountController->getUser();

    user->getChatController()->updateChats();

    QStringList messages = user->getChatController()->getMessageListGUI(chatId);

    QStringListModel *model = new QStringListModel(messages);

    ui->messageList->setModel(model);

    ui->messageList->setEditTriggers(QAbstractItemView::NoEditTriggers);

}




void ChatGUI::refreshMembers() {

    RocketUser *user = accountController->getUser();

    user->getChatController()->updateChats();

    QStringList members = user->getChatController()->getChatMembersGUI(chatId);

    QStringListModel *model = new QStringListModel(members);

    ui->memberList->setModel(model);

    ui->memberList->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

void ChatGUI::on_send_clicked(){

    QString message = ui->chatBox->text();
    ui->chatBox->clear();

    if(message.toStdString()!=("")){
    accountController->getUser()->getChatController()->sendMessage(chatId,message);
    refreshMessages();
    }



}


void ChatGUI::on_close_clicked(){
   delete this;
    }



