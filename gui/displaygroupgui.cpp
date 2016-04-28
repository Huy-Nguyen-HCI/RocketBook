#include "displaygroupgui.h"
#include "ui_displaygroupgui.h"

DisplayGroupGUI::DisplayGroupGUI(AccountController *inputAccountController,
                                 GroupGUI* groupGUI,
                                 QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayGroupGUI)
{
    ui->setupUi(this);

    //set up input
    this->accountController = inputAccountController;
    this->groupGUI = groupGUI;

    ui->enterGroupButton->hide();

    //set up group table
    ui->groupTable->setColumnCount(2);
    ui->groupTable->hideColumn(1);
    ui->groupTable->horizontalHeader()->hide();
    ui->groupTable->verticalHeader()->hide();
    ui->groupTable->setShowGrid(false);
    ui->groupTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->groupTable->setSelectionMode( QAbstractItemView::SingleSelection );

    refreshGroups();

    connect( ui->groupTable, SIGNAL(cellClicked(int,int)), this, SLOT(cell_clicked()) );
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
        int groupID = allGroups[i]->getID();

        QTableWidgetItem* group = new QTableWidgetItem(QIcon(groupPhoto), groupName);
        QTableWidgetItem* id = new QTableWidgetItem(QString::number(groupID));

        group->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        id->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        ui->groupTable->setItem(i, 0, group);
        ui->groupTable->setItem(i, 1, id);

    }
    ui->groupTable->setIconSize(QSize(200, 200));
    ui->groupTable->resizeColumnsToContents();
    ui->groupTable->resizeRowsToContents();

}

void DisplayGroupGUI::cell_clicked( )
{
    ui->enterGroupButton->show();
}

void DisplayGroupGUI::on_enterGroupButton_clicked()
{

    //get the group ID by looking at the hidden column
    QList<QTableWidgetItem*> groupRow = ui->groupTable->selectedItems();
    int row = groupRow.at(0)->row();
    int groupID = ui->groupTable->item(row, 1)->text().toInt();

    //Create the profileGUI and scrapbookGUI for groups
    Group* group = accountController->getUser()->controlGroup()->getGroup(groupID);
    Scrapbook* groupScrapbook = group->getProfile()->getScrapbook();
    GroupProfileGUI* groupProfileGUI = new GroupProfileGUI(group);
    ScrapbookGUI* groupScrapbookGUI = new ScrapbookGUI(accountController, groupScrapbook);

    //Add the GUIs to the stackedwidget
    groupGUI->addGroupProfile(groupProfileGUI);
    groupGUI->addGroupScrapbook(groupScrapbookGUI);

    //Switch group views to the profile view
    groupGUI->switchGroupViews(GroupGUI::GroupGUIType::ViewGroupProfile);

}

void DisplayGroupGUI::on_createGroupButton_clicked()
{
    groupGUI->switchGroupViews(GroupGUI::GroupGUIType::CreateGroup);
}
