#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
#include "Test.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    std::vector <Test> tests;
    QCheckBox *answers[6];
    QString FIO;
    Test activeTest;
    int rights;
    void swapMenusToTest(bool choise);
    void loadTests();
    bool startTest(Test test);
    void loadQuestion(Question question);
    int checkQuestion(Question question);
    void showTestResults();
private slots:
    void on_startButton_clicked();

    void on_nextButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
