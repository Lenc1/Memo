#include "check1.h"
#include "ui_check1.h"
#include <Qdir>
#include <QFileDialog>
#include <QStringList>
#include <QDebug>
#include <QTextCodec>
#include <QMenu>
#include <QResizeEvent>
#include <QFile>
#include <QLabel>
#include <QCloseEvent>
#include <QProcess>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QInputDialog>
char cot1[12],det1[20];
FILE *fp3;
void nread3() //读取当前备忘文件数
{
    fp3=fopen("num.memo","r");
    fgets(cot1,11,fp3);
    fclose(fp3);
}
void dread3()//读取删除次数
{
    fp3=fopen("den.memo","r");
    fgets(det1,11,fp3);
    fclose(fp3);
}
QString myDir,dfname;
Check1::Check1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Check1)
{
    ui->setupUi(this);
    setFixedSize(800,600);
    this->setWindowTitle("查看Memo");
    this->setWindowIcon(QIcon("Memo.ico"));
    LoadList();
}
Check1::~Check1()
{
    delete ui;
}

void Check1::on_pushButton_clicked()
{
    reboot();
}

void Check1::on_listWidget_doubleClicked(const QModelIndex &index) //双击查看
{
        QString filename=ui->listWidget->currentItem()->text();
        QString dirname=myDir;
        dirname.append("/").append(filename);
        QFile file(dirname);
        bool isopen=file.open(QIODevice::ReadOnly);
        if(isopen)
        {
            QByteArray filetext=file.readAll();
            QTextCodec *codec=QTextCodec::codecForName("GBK");//转换编码格式
            QString text=codec->toUnicode(filetext);
            ui->textBrowser->setText(text);    //将文件内容显示到textBrower
        }
        else
        {
            qDebug()<<"openerror";
        }
}

void Check1::on_listWidget_customContextMenuRequested(const QPoint &pos) //右键菜单
{
    QMenu *cmenu = new QMenu(ui->pushButton);
        dfname=ui->listWidget->currentItem()->text(); //获取删除文件名
        QAction *action1 = new QAction(tr("删除"), this);
        QAction *action2 = new QAction(tr("重命名"),this);
        action1->setData(1);
        action2->setData(1);
        cmenu->addAction(action1);
        cmenu->addAction(action2);
        connect(action1, SIGNAL(triggered(bool)), this, SLOT(on_menu_click1(bool)));
        connect(action2, SIGNAL(triggered(bool)), this, SLOT(on_menu_click2(bool)));
        cmenu->exec(QCursor::pos());
}
void Check1::on_menu_click1(bool)
{
    int dn=0,num=0,i=0,k;
    nread3();
    dread3();
    while(cot1[i])  //转存文件数到数字num
    {
            num*=10;
            num+=cot1[i++]-48;
    }
    i=0;
    while(det1[i]) //转存删除数到数字dn
    {
            dn*=10;
            dn+=det1[i++]-48;
    }
    QMessageBox::Button btn = QMessageBox::question(this, "删除Memo", "是否删除该条Memo？");
    if(btn == QMessageBox::Yes)
    {
        myDir.append("./").append(dfname);
        QFile fileTemp(myDir);
        fileTemp.remove();  //删除了，好简单哈哈哈
        dn++;
        num--;
        if(num==0)
        {
            system("del .\\message\\*.memo*");
            fp3=fopen("den.memo","w");
            fputs("1",fp3);
            fclose(fp3);
            fp3=fopen("num.memo","w");
            fputs("0",fp3);
            fclose(fp3);
            ui->listWidget->clear();
            ui->textBrowser->clear();
        }
        else
        {
            for(i=0;dn>0;i++)  //重写删除数  这里就难一点了，屋屋
            {
                det1[i]=dn%10+'0';
                dn/=10;
            }
            for(i=0;num>0;i++)  //重写存在文件数
            {
                cot1[i]=num%10+'0';
                num/=10;
            }
        for(i=0;i<=strlen(cot1)/2;i++)  //写入
        k=cot1[i],cot1[i]=cot1[strlen(cot1)-1],cot1[strlen(cot1)-1]=k;
        for(i=0;i<=strlen(det1)/2;i++)
        k=det1[i],det1[i]=det1[strlen(det1)-1],det1[strlen(det1)-1]=k;
        fp3=fopen("den.memo","w");
        fputs(det1,fp3);
        fclose(fp3);
        fp3=fopen("num.memo","w");
        fputs(cot1,fp3);
        fclose(fp3);
        }
        LoadList();
    }
}
void Check1::on_menu_click2(bool) //重命名
{
   bool ok=false;
   QString definput="新建文件名";
   QLineEdit::EchoMode echoMode=QLineEdit::Normal;
   QString str = QInputDialog::getText(this,"重命名","输入文件名:",echoMode,definput,&ok);
   if(ok&&!str.isEmpty())
   {
       QString backDir;
       backDir=myDir;
       myDir.append("./").append(dfname);
       backDir.append("./").append(str).append(".memo");
       QFile fileTemp(myDir);
       fileTemp.rename(backDir);
       LoadList();
       ui->textBrowser->clear();
   }
}

void Check1::reboot() //重启函数
{
    QString program = QApplication::applicationFilePath();
    QStringList arguments = QApplication::arguments();
    QString workingDirectory = QDir::currentPath();
    QProcess::startDetached(program, arguments, workingDirectory);
    QApplication::exit();
}
void Check1::closeEvent(QCloseEvent *ev)//关闭按钮的改变
{
    reboot();
}

void Check1::on_pushButton_2_clicked()//清空按钮
{
    QMessageBox::Button btn = QMessageBox::question(this, "清空", "是否删除全部？");
    if(btn == QMessageBox::Yes)
    {
        system("del .\\message\\*.memo*");
        fp3=fopen("den.memo","w");
        fputs("1",fp3);
        fclose(fp3);
        fp3=fopen("num.memo","w");
        fputs("0",fp3);
        fclose(fp3);
        ui->listWidget->clear();
        ui->textBrowser->clear();
    }
}
QStringList Check1::findFiles(const QString &startDir, QStringList filters) //搜索
{
    QStringList names;
    QDir dir("./message");
    foreach (QString file, dir.entryList(filters, QDir::Files))
        names += file;
    foreach (QString subdir, dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot))
        names += findFiles(startDir + '/' + subdir, filters);
    return names;
}
void Check1::LoadList()  //加载列表
{
    QString dirpath="./message";//message文件地址
    QStringList filelist = findFiles(dirpath, QStringList() << "*.memo");
    ui->listWidget->clear();
    ui->listWidget->addItems(filelist);
    myDir=dirpath;
}
