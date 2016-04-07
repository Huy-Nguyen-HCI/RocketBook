#ifndef SCRAPBOOK_H
#define SCRAPBOOK_H

#include <QWidget>

namespace Ui {
class Scrapbook;
}

class Scrapbook : public QWidget
{
    Q_OBJECT

public:
    explicit Scrapbook(QWidget *parent = 0);
    ~Scrapbook();

private:
    Ui::Scrapbook *ui;
};

#endif // SCRAPBOOK_H
