#include "mainwindow.h"
#include "windows.h"
#include "string.h"
#include "ui_mainwindow.h"
#include "kid.h"
#include "check1.h"
#include "iostream"
#include <fstream>
#include <QCloseEvent>
#include <QMessageBox>
#include <QResizeEvent>
#include <QDebug>
#include <QFile>
#include <QGraphicsDropShadowEffect>
using namespace std;
using std::string;
FILE *fp;
QString str;
char co1[12],dco[20];
void nread() //读取当前备忘文件数
{
    fp=fopen("num.memo","r");
    fgets(co1,11,fp);
    fclose(fp);
}
void dread()//读取删除次数
{
    fp=fopen("den.memo","r");
    fgets(dco,11,fp);
    fclose(fp);
}
MainWindow::MainWindow(QWidget *parent) :  //主菜单
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    nread();
    dread();
    ui->setupUi(this);
    setFixedSize(420,600);
    QGraphicsDropShadowEffect *s1 = new QGraphicsDropShadowEffect;
    QGraphicsDropShadowEffect *s2 = new QGraphicsDropShadowEffect;
    QGraphicsDropShadowEffect *s3 = new QGraphicsDropShadowEffect;
    QGraphicsDropShadowEffect *s4 = new QGraphicsDropShadowEffect;
    this->setWindowTitle("Memo ");//设置主窗口标题
    this->setWindowIcon(QIcon("Memo.ico"));//设置图标
    ui->label1->setText("[当前有      条Memo]");
    str=co1; //用string型字符串输出,因为setText不支持字符数组
    ui->label->setText(str);
    s1->setColor(QColor(200,200,200));
    s1->setBlurRadius(8);
    s1->setOffset(3);
    s2->setColor(QColor(200,200,200));
    s2->setBlurRadius(8);
    s2->setOffset(3);
    s3->setColor(QColor(200,200,200));
    s3->setBlurRadius(8);
    s3->setOffset(3);
    s4->setColor(QColor(200,200,200));
    s4->setBlurRadius(8);
    s4->setOffset(3);
    ui->newmemo->setGraphicsEffect(s1);
    ui->viewmemo->setGraphicsEffect(s2);
    ui->backpackbt->setGraphicsEffect(s3);
    ui->browse->setGraphicsEffect(s4);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::showChildDialog()
{
    connect(ui->newmemo,&QPushButton::clicked,this,&MainWindow::showChildDialog);
}
void MainWindow::closeEvent(QCloseEvent *ev)
{
    QMessageBox::Button btn = QMessageBox::question(this, "退出Memo", "是否退出Memo？");
    if(btn == QMessageBox::Yes)
        ev->accept();
    else
        ev->ignore();
}

void MainWindow::on_newmemo_clicked()
{
    kid* w =new kid;
    w->setWindowModality(Qt::ApplicationModal);
    w->show();
}

void MainWindow::on_viewmemo_clicked()
{
    //explicit Check1(QWidget *parent = 0);
    Check1* w =new Check1;
    w->setWindowModality(Qt::ApplicationModal);
    w->show();
}

void MainWindow::on_backpackbt_clicked()
{
    QMessageBox::Button btn=QMessageBox::information(this,"备份","不好意思这部分还没做");
}
