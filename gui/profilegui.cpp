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


    QString descr = currentProfile->getDescription();
    QString myName = currentProfile->getFullName();

    //QSqlQueryModel *model = new QSqlQueryModel();
    //QAbstractItemModel model;
    //QModelIndex modelIndex;

//    QListWidget profileList(ui->listView_profile);
//    QListWidgetItem description(descr, &profileList, 0);
//    QListWidgetItem descriptionTest(descrTest, &profileList, 0);
    //profileList.addItem(&description);
//    profileList.addItem(descrTest);
//    profileList.addItem(descr);

    //QStringList *toAdd = new QStringList();
    //toAdd->append(descr);
    //toAdd->append(descrTest);

    //QStringListModel profileModel = new QStringListModel(toAdd, NULL);
    //profileModel.setStringList(*toAdd);

    //ui->listView_profile->model()->insertRow(0, );


    ui->listWidget->clear();
    ui->listWidget->addItem("Name:    "+descr);

    ui->listWidget->addItem("My Description:    "+myName);





}

void ProfileGUI::on_listView_profile_activated(const QModelIndex &index)
{

}
