#include "chatgui.h"
#include "ui_chatgui.h"

ChatGUI::ChatGUI(AccountController *input, int chatId, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatGUI)
{
    // set up the pointers
    ui->setupUi(this);
    scene = new QGraphicsScene();
    accountController = input;
    this->chatId = chatId;

    // load the view for the first time
    refreshMembers();
    refreshMessages();

    // set a timer for refreshing
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(refreshMessages()));
    connect(timer, SIGNAL(timeout()), this, SLOT(refreshMembers()));
    timer->start(500);

    // set window title
    this->setWindowTitle("Chat Room: " + QString::number(chatId));//username + " 's Profile");
}

ChatGUI::~ChatGUI()
{
    delete ui;
    delete timer;
}

void ChatGUI::refreshMessages() {

    // get all the chat messages
    RocketUser *user = accountController->getUser();
    user->getChatController()->updateChats();
    QStringList messages = user->getChatController()->getMessageListGUI(chatId);

    // display the messages
    QStringListModel *model = new QStringListModel(messages);
    ui->messageList->setModel(model);
    ui->messageList->setEditTriggers(QAbstractItemView::NoEditTriggers);

}


void ChatGUI::refreshMembers() {

    // get all the members
    RocketUser *user = accountController->getUser();
    user->getChatController()->updateChats();
    QStringList members = user->getChatController()->getChatMembersGUI(chatId);

    // display all the members
    QStringListModel *model = new QStringListModel(members);
    ui->memberList->setModel(model);
    ui->memberList->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

void ChatGUI::on_send_clicked(){

    // get the input message
    QString message = ui->chatBox->text();
    ui->chatBox->clear();

    if (message.isEmpty()) return;

    // submit the message and display it to everyone in the chat
    accountController->getUser()->getChatController()->sendMessage(chatId,message);
    refreshMessages();
}


void ChatGUI::closeEvent(QCloseEvent *event){
    delete this;
    event->accept();
}


void ChatGUI::on_chatBox_returnPressed()
{
    // get the input message
    QString message = ui->chatBox->text();
    ui->chatBox->clear();

    if (message.isEmpty()) return;

    // submit the message and display it to everyone in the chat
    accountController->getUser()->getChatController()->sendMessage(chatId,message);
    refreshMessages();
}
