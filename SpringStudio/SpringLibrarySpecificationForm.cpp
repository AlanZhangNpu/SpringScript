//#include "SpringLibrarySpecificationForm.h"
//#include "ui_SpringLibInformationForm.h"

//#include "Spring.h"

//using namespace spr;

//SpringLibrarySpecificationForm::SpringLibrarySpecificationForm(QWidget *parent) :
//    QWidget(parent),
//    ui(new Ui::SpringLibInformationForm)
//{
//    ui->setupUi(this);
//    this->setWindowTitle("Spring Standard/Extension Library");
//}

//SpringLibrarySpecificationForm::~SpringLibrarySpecificationForm()
//{
//    delete ui;
//}

//void SpringLibrarySpecificationForm::setExternLibraryPaths(std::vector<std::string> libs)
//{
//    for(auto path : libs){
//        SpringLibrarySpecification s;
//        std::string status = SpringRuntimeLibrary::getExternLibrarySpecification(path, s);
//        if(!status.empty())
//            continue;

//        QTreeWidgetItem *items1 = new QTreeWidgetItem(ui->treeWidget,
//                                    QStringList(QString::fromStdString(s.libName)));

//        items1->setBackgroundColor(0, Qt::gray);
//        items1->setBackgroundColor(1, Qt::gray);
//        items1->setTextColor(0, Qt::white);

//        QTreeWidgetItem *items11 = new QTreeWidgetItem(items1,
//        {QString("name"), QString::fromStdString(s.libName)});

//        QTreeWidgetItem *items2 = new QTreeWidgetItem(items1,
//        {QString("path"), QString::fromStdString(path)});

//        QTreeWidgetItem *items3 = new QTreeWidgetItem(items1,
//        {QString("description"), QString::fromStdString(s.libDescription)});

//        QTreeWidgetItem *items4 = new QTreeWidgetItem(items1,
//        {QString("author"), QString::fromStdString(s.libAuthor)});

//        QTreeWidgetItem *items5 = new QTreeWidgetItem(items1,
//        {QString("version"), QString::fromStdString(s.libVersion)});

//        QTreeWidgetItem *items6 = new QTreeWidgetItem(items1,
//        {QString("functions"), ""});

//        for(auto f: s.functions){
//            QTreeWidgetItem *items2 = new QTreeWidgetItem(items6,
//            {QString::fromStdString(f.funcName), QString::fromStdString(f.funcDescription)});
//        }
//    }

//    ui->treeWidget->expandAll();
//    ui->treeWidget->setColumnWidth(0, 400);
//    ui->treeWidget->setAlternatingRowColors(true);
//    ui->treeWidget->setSortingEnabled(false);
//}

//void SpringLibrarySpecificationForm::setRuntimeLibraryNames(std::vector<std::string> libs)
//{
////    for(auto lib : libs){
////        SpringLibrarySpecification s = Spring::runtimeEnvironment.springRuntimeLib.getLibrarySpecification(lib);

////        QTreeWidgetItem *items1 = new QTreeWidgetItem(ui->treeWidget,
////                                    QStringList(QString::fromStdString(s.libName)));

////        items1->setBackgroundColor(0, Qt::gray);
////        items1->setBackgroundColor(1, Qt::gray);
////        items1->setTextColor(0, Qt::white);

////        QTreeWidgetItem *items11 = new QTreeWidgetItem(items1,
////        {QString("name"), QString::fromStdString(s.libName)});

////        QTreeWidgetItem *items3 = new QTreeWidgetItem(items1,
////        {QString("description"), QString::fromStdString(s.libDescription)});

////        QTreeWidgetItem *items4 = new QTreeWidgetItem(items1,
////        {QString("author"), QString::fromStdString(s.libAuthor)});

////        QTreeWidgetItem *items5 = new QTreeWidgetItem(items1,
////        {QString("version"), QString::fromStdString(s.libVersion)});

////        QTreeWidgetItem *items6 = new QTreeWidgetItem(items1,
////        {QString("functions"), ""});

////        for(auto f: s.functions){
////            QTreeWidgetItem *items2 = new QTreeWidgetItem(items6,
////            {QString::fromStdString(f.funcName), QString::fromStdString(f.funcDescription)});
////        }
////    }
////    ui->treeWidget->expandAll();
////    ui->treeWidget->setColumnWidth(0, 400);
////    ui->treeWidget->setAlternatingRowColors(true);
////    ui->treeWidget->setSortingEnabled(false);
//}
