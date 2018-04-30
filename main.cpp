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
        for (int i = 0; i < 500000; ++i)
        {
            objectTest test("asdfnnmgkdfawngdfnkdlngansdfknalkklfashdglajbdglkjasdbflkasdjfklahgakdfehinlfjnalkjdghkadjshfadshgdgjaksldlkasjdhfkajbdgldlkfjbaldkfghasdf",i);
            this->_list.append(test);
        }
    };


    QList<objectTest> getlist() {
        QList<objectTest> _listTest;

        for (int i = 0; i < 500000; ++i)
        {
            objectTest test("asdfnnmgkdfawngdfnkdlngansdfknalkklfashdglajbdglkjasdbflkasdjfklahgakdfehinlfjnalkjdghkadjshfadshgdgjaksldlkasjdhfkajbdgldlkfjbaldkfghasdf",i);
            _listTest.append(test);
        }

        std::cout <<" begin count to show "  << std::endl;
        sleep(5);
        std::cout <<" begin return data "  << std::endl;

        return _listTest;
    }

    void testDataUsing(){
        std::cout << "begin test getlist" << std::endl;
        this->_list = getlist();
        std::cout << "close test getlist" << std::endl;
    }


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


    uQList qlist;
    //qlist.testDataUsing();
    qlist.setData();

    return app.exec();
}
