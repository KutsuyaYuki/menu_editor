#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings.h"
#include <QStatusBar>
#include <QStyle>
#include <QDesktopWidget>
#include <QDirIterator>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Launch form in the center of the screen
    this->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
        ));

    // add status bar message
    statusBar()->showMessage("Statusbar!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_Exit_triggered()
{
    exit(1);
}

void MainWindow::on_action_Settings_triggered()
{
    // Open the settings form
    Settings *settings = new Settings();
    settings->exec();
}

void MainWindow::ScanFolders()
{
    /*
    QDir dir;
        dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        dir.setSorting(QDir::Size | QDir::Reversed);

        QFileInfoList list = dir.entryInfoList();

        StringList.append("mew");

    QDirIterator it("/home/yuki/menu_editor", QDirIterator::Subdirectories);
    while (it()) {
        qInfo( it.fileName().toStdString() );

    }*/
}

void MainWindow::on_pushButton_clicked()
{
    ScanFolders();
}


















