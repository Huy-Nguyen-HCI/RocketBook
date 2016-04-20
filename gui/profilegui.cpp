#include "profilegui.h"
#include "ui_profilegui.h"

ProfileGUI::ProfileGUI(AccountController *inputAccountController, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfileGUI)
{
    ui->setupUi(this);
    accountController = inputAccountController;
}

ProfileGUI::~ProfileGUI()
{
    delete ui;
}

void ProfileGUI::on_pushButton_loadProfile_clicked()
{
    Profile *currentProfile = accountController->getUser()->getProfile();
    //ui->listView_profile->

    const QString descr = currentProfile->getDescription();


    //QSqlQueryModel *model = new QSqlQueryModel();
    //QAbstractItemModel model;
    //QModelIndex modelIndex;

    QListWidget profileList(ui->listView_profile);
    //QListWidgetItem description(descr, &profileList, 0);
    //profileList.addItem(&description);
    profileList.addItem(descr);



}

void ProfileGUI::on_listView_profile_activated(const QModelIndex &index)
{

}
