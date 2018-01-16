#include "settings.h"
#include "ui_settings.h"
#include <QCoreApplication>
#include <QSettings>
#include <QApplication>
#include <QFileDialog>

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

    settingsFile = QCoreApplication::applicationDirPath() + "/config.ini";
    loadSettings();
}

Settings::~Settings()
{
    delete ui;
}



// Make loading possible
void Settings::loadSettings()
{
    QSettings settings(settingsFile, QSettings::NativeFormat);
    QString sText = settings.value("local_directory", "").toString();

    ui->lineDirectory->setText(sText);
}

// Make savingpossible
void Settings::saveSettings()
{
    QString directory = ui->lineDirectory->text();

    QSettings settings(settingsFile, QSettings::NativeFormat);
    QString sText = directory;
    settings.setValue("local_directory", sText);
}

void Settings::on_buttonBox_accepted()
{
    saveSettings();
    this->close();
}

void Settings::on_toolButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select Directory"), "/home",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->lineDirectory->setText(dir);
}

void Settings::on_buttonBox_rejected()
{
    this->close();
}
