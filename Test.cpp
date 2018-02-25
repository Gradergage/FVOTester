#include "Test.h"

Test::Test()
{
    currentQuestion=0;
    //ctor
}

Test::~Test()
{
    //dtor
}

Question Test::parseQuestion(QTextStream &questionStream)
{
    QString temp;
    Question question;
    question.questionText=questionStream.readLine();// std::getline(questionStream,question.questionText);
    while(true)
    {
       // std::getline(questionStream,temp);
        temp=questionStream.readLine();
        /*   char str[512];
           questionStream.getline(str,512);
           std::string temp(str); */
        if(temp=="}" || temp=="")
        {
            break;
        }
        else {
            question.answers.push_back(temp[0]=='+');
            question.answersText.push_back(temp.mid(1,temp.length()-1));
        }
    }
    return question;
}

int Test::parseTest(QString textTest)
//int Test::parseTest(const char textt[])
{

    QTextStream questionStream(&textTest);
    questionStream.setCodec("ANSI");
   // questionStream<<textTest;
    QString temp;
    testName=questionStream.readLine();

    while(!questionStream.atEnd())
    {
        temp=questionStream.readLine();
        if(temp=="{")
        {
            questions.push_back(parseQuestion(questionStream));
        }
    }

    return 0;
}
Question Test::getCurrentQuestion()
{
    return questions[currentQuestion];
}

int Test::nextQuestion()
{
    if(currentQuestion<questions.size()-1)
    {
        currentQuestion++;
        return 0;
    }
    else
    {
        return 1;
    }
}

