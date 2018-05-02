#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QList>
#include <QVector>
#include <QObject>
#include <iostream>
#include <unistd.h>
#include <QDebug>

#include <iostream>
#include <vector>

#define  rep(i,n)        for(int i = 0; i < n ; ++i)


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

    void clearData(){
        this->_list.clear();
    }


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

struct entity {
    int x,y,z;

    entity(int x, int y, int z)
        : x(x), y(y), z(z)
    {
        std::cout << "constructor!!!!" << x << std::endl;
    }

    entity(const entity& e)
        : x(e.x) , y(e.y) , z(e.z)
    {
        std::cout << "copied constructor!!!!" << e.x << std::endl;
    }
};

class obj {
private:
    int _x,_y,_z;
public:
    obj(int x, int y, int z): _x(x), _y(y), _z(z){
        std::cout << "constructor " << this->_x << " - address: " << this << std::endl;
    };

    obj(const obj& o): _x(o._x), _y(o._y), _z(o._z){
        std::cout << "copied constructor " << this->_x  << " - address: " << this << std::endl;
    }

    ~obj(){
        std::cout << "destroy " << this->_x  << " - address: " << this << std::endl;
    };


};

std::vector<obj> myVector;

std::vector<obj> createData(){
    std::vector<obj> tem;
    std::cout << " Create data " << std::endl;
    rep(i,10){
        std::cout << "_____________________________________________begin" << std::endl;
        obj o(i,i,i);
        tem.emplace_back(o);
        std::cout << "_____________________________________________end" << std::endl;
    }
    return tem;
}

void testFunc(){
    myVector = createData();
    std::cout << "datasize: " << myVector.size() << std::endl;
    return;
}

int main(int argc, char *argv[])
{
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

//    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//    if (engine.rootObjects().isEmpty())
//        return -1;

    testFunc();

    std::cout << "finished test" << std::endl;
    //std::cin.get();
//    return app.exec();
    return 0;
}
