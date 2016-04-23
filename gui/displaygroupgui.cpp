#include "displaygroupgui.h"
#include "ui_displaygroupgui.h"

DisplayGroupGUI::DisplayGroupGUI(AccountController *inputAccountController, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayGroupGUI)
{
    ui->setupUi(this);
    this->accountController = inputAccountController;
    ui->groupTable->setColumnCount(2);
    ui->groupTable->hideColumn(1);
    ui->groupTable->horizontalHeader()->hide();
    ui->groupTable->verticalHeader()->hide();
    ui->groupTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    refreshGroups();
}

DisplayGroupGUI::~DisplayGroupGUI()
{
    delete ui;
}

void DisplayGroupGUI::refreshGroups()
{
    //pull out the group list. This should automatically be refreshed in the model
    std::vector<Group*> allGroups = accountController->getUser()->controlGroup()->getAllGroups();

    ui->groupTable->clear();
    ui->groupTable->setRowCount(allGroups.size());

    for (unsigned int i = 0; i < allGroups.size(); i++) {
        Profile* groupProfile = allGroups[i]->getProfile();
        QString groupPhoto = groupProfile->getPicturePath();
        QString groupName = groupProfile->getFullName();
        int groupID = groupProfile->getID();

        QTableWidgetItem* group = new QTableWidgetItem(QIcon(groupPhoto), groupName);
        ui->groupTable->setItem(i, 0, group);
        QTableWidgetItem* id = ui->groupTable->item(i, 1);
        id->setData(Qt::UserRole, groupID);
    }
}

void DisplayGroupGUI::on_cell_clicked( int row, int column )
{
}
