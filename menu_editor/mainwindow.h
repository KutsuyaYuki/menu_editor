#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_Exit_triggered();

    void on_action_Settings_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void ScanFolders();
};

#endif // MAINWINDOW_H
