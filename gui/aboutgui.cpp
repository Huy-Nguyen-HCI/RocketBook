#include "aboutgui.h"
#include "ui_aboutgui.h"


AboutGUI::AboutGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutGUI)
{
    ui->setupUi(this);

    // load the source map to list
    std::map<QString, QString> sourceMap = setupMap();

    for (auto const& source : sourceMap) {

        QListWidgetItem *item = new QListWidgetItem(QIcon(source.first), source.second, ui->listSource);

        ui->listSource->addItem(item);
    }

    ui->listSource->setIconSize(QSize(50,50));
}

AboutGUI::~AboutGUI()
{
    delete ui;
}


std::map<QString, QString> AboutGUI::setupMap() {

    std::map<QString, QString> sourceMap;

    sourceMap.insert( std::pair<QString, QString>("rocket.png", "https://thenounproject.com/term/rocket/1758/"));
    sourceMap.insert( std::pair<QString, QString>("message.png", "http://icons.iconarchive.com/icons/osullivanluke/orb-os-x/512/Messages-icon.png"));
    sourceMap.insert( std::pair<QString, QString>("post.png", "https://cdn1.iconfinder.com/data/icons/social-media-3/512/615556-Pencil_Document-512.png"));
    sourceMap.insert( std::pair<QString, QString>("group.png", "http://icons.iconarchive.com/icons/hopstarter/sleek-xp-basic/256/User-Group-icon.png"));
    sourceMap.insert( std::pair<QString, QString>("logout.png", "https://cdn1.iconfinder.com/data/icons/web-ui/30/power-01-128.png"));
    sourceMap.insert( std::pair<QString, QString>("feed.png", "https://icons8.com/"));
    sourceMap.insert( std::pair<QString, QString>("scrapbook.png", "https://icons8.com/"));
    sourceMap.insert( std::pair<QString, QString>("friends.png", "https://icons8.com/"));
    sourceMap.insert( std::pair<QString, QString>("notification.png", "https://icons8.com/"));
    sourceMap.insert( std::pair<QString, QString>("user.png", "https://icons8.com/"));
    sourceMap.insert( std::pair<QString, QString>("settings.png", "https://icons8.com/"));
    sourceMap.insert( std::pair<QString, QString>("about.png", "https://icons8.com/"));
    sourceMap.insert( std::pair<QString, QString>("rocketbackground.gif", "https://d13yacurqjgara.cloudfront.net/users/163741/screenshots/1228007/dribbble_shot_hq.gif"));
    return sourceMap;
}
