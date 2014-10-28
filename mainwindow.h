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

    void on_radioBg_clicked();

    void on_radioLine_clicked();

    void on_radioPoly_clicked();

    void on_sliderR_valueChanged(int value);

    void on_sliderG_valueChanged(int value);

    void on_sliderB_valueChanged(int value);

    void on_buttonApply_clicked();


    void on_actionExit_triggered();

    void on_actionSave_triggered();

    void on_actionOpen_triggered();

    void on_actionNew_triggered();

private:
    Ui::MainWindow *ui;
    int activeColorObject;
};

#endif // MAINWINDOW_H
