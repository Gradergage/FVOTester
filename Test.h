#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "Question.h"

class Test
{

public:
    std::vector <Question> questions;
    QString testName;
    int currentQuestion;
    Test();

    virtual ~Test();
    int parseTest(QString textTest);
   // int parseTest(const char textt[]);
    Question parseQuestion(QTextStream &questionStream);
    double getResult();
    void cleanAnswers();
    Question getCurrentQuestion();
    int nextQuestion();
};
