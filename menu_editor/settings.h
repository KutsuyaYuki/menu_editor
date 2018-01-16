#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

private slots:
    void on_buttonBox_accepted();

    void on_toolButton_clicked();

    void on_buttonBox_rejected();

private:
    Ui::Settings *ui;

    // Make saving/loading possible
    QString settingsFile;
    QString str;
    QLabel* m_pLabel;
    QLineEdit* m_pEdit;
    QPushButton* m_pButton;
    void loadSettings();
    void saveSettings();
};

#endif // SETTINGS_H
