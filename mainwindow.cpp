#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <fstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(ui->buttonApply, SIGNAL(clicked()),ui->widget,SLOT(applySpaceFilling()));
    connect(ui->checkFill, SIGNAL(stateChanged(int)),ui->widget,SLOT(setFill(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_radioBg_clicked()
{
    activeColorObject = 1;
    float *ff = ui->widget->getBgColor();
    ui->sliderR->setValue((int)(ff[0]*255));
    ui->sliderG->setValue((int)(ff[1]*255));
    ui->sliderB->setValue((int)(ff[2]*255));
}

void MainWindow::on_radioLine_clicked()
{
    activeColorObject = 2;
    float *ff = ui->widget->getLineColor();
    ui->sliderR->setValue((int)(ff[0]*255));
    ui->sliderG->setValue((int)(ff[1]*255));
    ui->sliderB->setValue((int)(ff[2]*255));
}

void MainWindow::on_radioPoly_clicked()
{
    activeColorObject = 3;
    float *ff = ui->widget->getPolygonColor();
    ui->sliderR->setValue((int)(ff[0]*255));
    ui->sliderG->setValue((int)(ff[1]*255));
    ui->sliderB->setValue((int)(ff[2]*255));
}

void MainWindow::on_sliderR_valueChanged(int value)
{
    if(activeColorObject == 1)
        ui->widget->setBackgroundColor(0,(float)value/255);
    else if(activeColorObject ==2 )
        ui->widget->setLineColor(0,(float)value/255);
    else if(activeColorObject==3)
        ui->widget->setPolygonColor(0,(float)value/255);
}

void MainWindow::on_sliderG_valueChanged(int value)
{
    if(activeColorObject == 1)
        ui->widget->setBackgroundColor(1,(float)value/255);
    else if(activeColorObject ==2 )
        ui->widget->setLineColor(1,(float)value/255);
    else if(activeColorObject==3)
        ui->widget->setPolygonColor(1,(float)value/255);
}

void MainWindow::on_sliderB_valueChanged(int value)
{
    if(activeColorObject == 1)
        ui->widget->setBackgroundColor(2,(float)value/255);
    else if(activeColorObject ==2 )
        ui->widget->setLineColor(2,(float)value/255);
    else if(activeColorObject==3)
        ui->widget->setPolygonColor(2,(float)value/255);
}

void MainWindow::on_buttonApply_clicked()
{
    ui->widget->applySpaceFilling(ui->spinIterations->value());
}

void MainWindow::on_actionExit_triggered()
{
    qApp->quit();
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save curve"),"",tr("Space Filling Curve (*.spc);;All Files (*)"));
    if(fileName.isEmpty())
        return;
    const char *str;;
    QByteArray ba;
    ba = fileName.toLatin1();
    str = ba.data();
    std::ofstream of;
    of.open(str);

    of << ui->widget->dumpCurve();
    of.close();
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Space Filling Curve"),"",tr("Space Filling Curve (*.spc);;All Files (*)"));
    if(fileName.isEmpty())
        return;
    const char *str;;
    QByteArray ba;
    ba = fileName.toLatin1();
    str = ba.data();
    std::ifstream of;
    of.open(str);
    int numIt,numVer;
    float *bgColor = new float[4],*lineColor=new float[4];
    of >> bgColor[0] >> bgColor[1] >> bgColor[2] >> bgColor[3] >> lineColor[0] >> lineColor[1] >> lineColor[2] >> lineColor[3];
    of >> numIt >> numVer;
    float *f1 = new float[numVer];
    float *f2 = new float[numVer];
    for(int i=0;i<numVer;i++)
        of>> f1[i] >> f2[i];
    ui->widget->loadCurve(bgColor,lineColor,numIt,numVer,f1,f2);
}

void MainWindow::on_actionNew_triggered()
{
    ui->widget->clearCurve();
}
