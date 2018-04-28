#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QList>
#include <QVector>
#include <QObject>
#include <iostream>
#include <unistd.h>

class objectTest{
private:
    QString             _proString;
    int                 _proInt;

public:
    objectTest(QString proString, int proInt) : _proString(proString), _proInt(proInt){
        std::cout << "created object" << std::endl;
    };

    ~objectTest(){
        std::cout << "released object " << _proInt << std::endl;
    };

};


class uQList {
private:
    QList<objectTest>       _list;

public:
    uQList(){
        std::cout << "created object uQList" << std::endl;
    };

    ~uQList(){
        std::cout << "released object uQList" << std::endl;
    };

    void setData(){
        for (int i = 0; i < 50000; ++i)
        {
            objectTest test("testdataaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",i);
            this->_list.append(test);
        }
    };

};

class uQVector {
private:
    QVector<objectTest>     _vector;

public:
    uQVector(){

    }

};

class UIchecker:  public QObject
{
    Q_OBJECT

};


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    std::cout << sizeof(objectTest) << std::endl;
    sleep(2);

    {
        uQList qlist;
        qlist.setData();
        sleep(10);
    }

    return app.exec();
}
