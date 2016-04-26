#include "aboutgui.h"
#include "ui_aboutgui.h"


/**
    IMAGE SOURCES:
    rocket.png:         https://thenounproject.com/term/rocket/1758/
    message.png:        http://icons.iconarchive.com/icons/osullivanluke/orb-os-x/512/Messages-icon.png
    post.png:           https://cdn1.iconfinder.com/data/icons/social-media-3/512/615556-Pencil_Document-512.png
    group.png:          http://icons.iconarchive.com/icons/hopstarter/sleek-xp-basic/256/User-Group-icon.png
    logout.png:         https://cdn1.iconfinder.com/data/icons/web-ui/30/power-01-128.png
    feed.png:           https://icons8.com/
    scrapbook.png:      https://icons8.com/
    friends.png:        https://icons8.com/
    notification.png:   https://icons8.com/
    user.png:           https://icons8.com/
    settings.png:       https://icons8.com/
  */

AboutGUI::AboutGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutGUI)
{
    ui->setupUi(this);
}

AboutGUI::~AboutGUI()
{
    delete ui;
}


std::map<QString, QString> AboutGUI::setupMap() {

    std::map<QString, QString> sourceMap;

    return sourceMap;
}
