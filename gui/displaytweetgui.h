#ifndef DISPLAYTWEETGUI_H
#define DISPLAYTWEETGUI_H

#include <QWidget>
#include "scrapbookgui.h"
#include "../model/scrapbook.h"

class ScrapbookGUI;

namespace Ui {
class DisplayTweetGUI;
}

class DisplayTweetGUI : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief DisplayTweetGUI the class constructor.
     * @param inputScrapbook pointer to the scrapbook of the user.
     * @param input the corresponding scrapbook GUI.
     * @param parent the parent QWidget class.
     */
    explicit DisplayTweetGUI(Scrapbook *inputScrapbook, ScrapbookGUI *input, QWidget *parent = 0);

    /**
      * @brief ~DisplayTweetGUI the class destructor. Deletes the pointer to ui.
      */
    ~DisplayTweetGUI();

    /**
     * @brief refreshTweets load and display all the tweets.
     */
    void refreshTweets();

private slots:
    /**
     * @brief on_createTweet_clicked segue to the create tweet view.
     */
    void on_createTweet_clicked();

    /**
     * @brief on_refreshMyTweets_clicked refresh the view.
     */
    void on_refreshMyTweets_clicked();

private:
    Ui::DisplayTweetGUI *ui;
    ScrapbookGUI *scrapbookGUI;
    Scrapbook *scrapbook;
};

#endif // DISPLAYTWEETGUI_H
