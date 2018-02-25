#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPicture>
#include <QDir>
#include <QFile>
#include <QStringList>
#include <QPainter>
#include <QProgressBar>
#include <QListView>
#include <QListWidget>
#include <QDebug>
#include <QDirIterator>
#include <windows.h>
#include <fstream>
#include <iostream>

void MainWindow::loadTests()
{
    QDir dir("./debug/tests");
    QStringList list = dir.entryList(QDir::Files);
    QString drctr="";
    if(list.size()==0)
    {ui->questionTextLabel->setText("empty");}
        foreach (QString s, list) {
            drctr+=" "+s;
            ui->questionTextLabel->setText(drctr);
            QFile f("./debug/tests/"+s);
                if (!f.open(QFile::ReadOnly | QFile::Text)) break;
            QTextStream in(&f);
            QString stringTest=in.readAll();

            ui->testNameLabel->setText(stringTest);

            Test test;
            test.parseTest(stringTest);
            tests.push_back(test);
            new QListWidgetItem(test.testName, ui->testsListWidget);
            //ui->testsListWidget->addItem(test.testName);
            ui->resultsLabel->setVisible(false);
    }
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Preparations, hiding testing elements
    for(int i=0;i<6;i++)
    {
        answers[i]=new QCheckBox(parent);
       // ui->answersLayout->addItem(answers[i]);
        ui->answersLayout->addWidget(answers[i]);
        answers[i]->setText("answer 1");
        answers[i]->setVisible(false);
    }
    ui->nextButton->setVisible(false);
    loadTests();
    swapMenusToTest(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::startTest(Test test)
{
    int qCount = test.questions.size();
    int qRightCount = 0;
    ui->testProgressBar->setMaximum(qCount);
    ui->testProgressBar->setValue(0);
    ui->testProgressBar->setMinimum(qRightCount);
}

void MainWindow::loadQuestion(Question question)
{
    int i=0;
   // const QString qtxt(question.questionText.c_str());

    ui->questionTextLabel->setText(question.questionText);
    for(i=0;i<question.answers.size();i++)
    {
        const QString atxt(question.answersText[i]);
       // answers[i]->setChecked(question.answers[i]);
        answers[i]->setChecked(false);
        answers[i]->setText(atxt);
        answers[i]->setVisible(true);

    }
    for(i;i<6;i++)
    {
        answers[i]->setVisible(false);
    }
}

int MainWindow::checkQuestion(Question question)
{
    for(int i=0;i<question.answers.size();i++)
    {
        if(answers[i]->isChecked()==question.answers[i])
        {
            continue;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}
void MainWindow::swapMenusToTest(bool choise)
{
    ui->pictureLabel->setVisible(choise);
    ui->testNameLabel->setVisible(choise);
    ui->nextButton->setVisible(choise);
    ui->testProgressBar->setVisible(choise);
    ui->questionTextLabel->setVisible(choise);
    for(int i=0;i<6;i++)
    {
        answers[i]->setVisible(choise);
    }
    ui->testsListWidget->setVisible(!choise);
    ui->startButton->setVisible(!choise);
}
void MainWindow::showTestResults()
{
 //   ui->questionTextLabel->setText(rights+"/"+activeTest.questions.size());
    swapMenusToTest(false);

   // ui->questionTextLabel->setVisible(true);
    double result = 1.0*rights/activeTest.questions.size()*100;
    ui->resultsLabel->setVisible(true);
    QString name=trUtf8("Алло");
    QString results=QString(QString("Previous results:\n")+QString("Test: \"")+activeTest.testName+"\"\n"+QString("Student: ")+FIO+"\n" + QString("Score: ")+QString::number(rights)+"/"+QString::number(activeTest.questions.size())+" | "+QString::number(result)+"%");
    ui->resultsLabel->setText(results);
}






void MainWindow::on_startButton_clicked()
{


    if(ui->testsListWidget->currentItem()==0)
    {

    }
    else
    {
       // ui->resultsLabel->clear();
         ui->resultsLabel->setVisible(false);
        if(tests.size()==0)
        {
            ui->questionTextLabel->setText("Sizeerror");
        }
        else
        {
            int index=ui->testsListWidget->currentIndex().row();
            activeTest=tests[index];
        }

        swapMenusToTest(true);
        ui->testNameLabel->setText(activeTest.testName);
       // int qCount = activeTest.questions.size();
        //int qRightCount = 0;
        rights=0;
        ui->testProgressBar->setMaximum(activeTest.questions.size());
        ui->testProgressBar->setValue(activeTest.currentQuestion+1);
        ui->testProgressBar->setMinimum(0);

        if(activeTest.questions.size()==0)
        {
            ui->questionTextLabel->setText("noQuestions");
        }

        loadQuestion(activeTest.questions[0]);
        ui->nextButton->setVisible(true);
    }
}

void MainWindow::on_nextButton_clicked()
{
    if(checkQuestion(activeTest.questions[activeTest.currentQuestion])==0)
    {
            rights++;
    }
    if(activeTest.nextQuestion())
    {
        showTestResults();
    }
    else
    {
        ui->testProgressBar->setValue(activeTest.currentQuestion+1);
        loadQuestion(activeTest.questions[activeTest.currentQuestion]);
    }
}

