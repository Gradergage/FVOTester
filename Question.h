#include <vector>
#include <string>
#include <sstream>
#include <Qstring>
#include <QTextStream>
class Question
{
public:
    int rightAnswer;
    QString questionText;
    std::vector <QString> answersText;
    std::vector <bool> answers;
    Question();
    virtual ~Question();
};
