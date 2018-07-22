#include <QString>
#include <QtTest>
#include <QDebug>
#include <string>

#include "Spring.h"

using namespace spr;

class SpringUnitTestTest : public QObject
{
    Q_OBJECT

public:
    SpringUnitTestTest(){}

private Q_SLOTS:
//    void testCase2_data(){
//        QTest::addColumn<int>("a");
//        QTest::addColumn<int>("b");

//        QTest::newRow("case1") << 0 << 0;
//        QTest::newRow("case2") << 1 << 2;
//        QTest::newRow("case3") << 2 << 4;
//        QTest::newRow("case4") << 10 << 20;
//    }

    void testCase1()
    {
//        QFETCH(QString, lib);
//        QFETCH(QString, libName);

//        SpringLibrarySpecification info;
//        SpringRuntimeLibrary::getExternLibrarySpecification(lib.toStdString(), info);
//        qDebug()<<QString::fromStdString(info.libName);

//        QCOMPARE(info.libName, libName.toStdString());
    }

    void testCase1_data(){
        QTest::addColumn<QString>("lib");
        QTest::addColumn<QString>("libName");

        QTest::newRow("case1") << "C:/Users/zhangyw/QtProjects/build-Spring-Desktop_Qt_5_10_1_MinGW_32bit-Debug/TestThirdPartyLib/debug/TestThirdPartyLib.dll"
                               << "TestThirdPartyLib2";
    }
};


QTEST_APPLESS_MAIN(SpringUnitTestTest)

#include "tst_springunittesttest.moc"
