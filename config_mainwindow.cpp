#include "config_mainwindow.h"
#include "ui_config_mainwindow.h"
#include <array>
#include <QComboBox>
#include <QDebug>
#include <qmessagebox.h>
#include <QMessageBox>



config_mainwindow::config_mainwindow(QStringList eNBlist,SonTcpServer *server, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::config_mainwindow)
{
    widget = dynamic_cast<Widget*>(parent);
    ui->setupUi(this);
    server1 = server;
    tempeNBlist = eNBlist;
    ui->tableWidget->setColumnWidth(7, 130);
    //隔行变色(没用上)
    ui->tableWidget->setAlternatingRowColors(true);
    //ui->tableWidget->horizontalHeader()->setObjectName("hHeader");水平方向的header属性无法设置
    //设置垂直方向上的header属性
    ui->tableWidget->verticalHeader()->setObjectName("vHeader");
    ui->pushButton->setProperty("btn","white");//设置属性，与qss文件中的样式对应
    qDebug()<< "initialization: "<< tempeNBlist;
    //todo 关掉自配置界面后依然保持刷新的方法
    count = 0;
    if (!tempeNBlist.empty())
    {
        for (int i = 0; i < tempeNBlist.length(); i++)
        {
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            QTableWidgetItem *element = new QTableWidgetItem(tempeNBlist.at(i));
            element->setFlags(element->flags()&(~Qt::ItemIsEditable));
            element->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,element);
            add_eNB_otherinfo();
        }
    }
    //正则表达式限制输入

//    //no edit
//    //ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    //let first column can not 3edit
//    for(int i =0; i<3;i++){
//        QTableWidgetItem *itab = ui->tableWidget->item(i,0);
//        itab->setFlags(itab->flags() & (~Qt::ItemIsEditable));
//    }

//    //在tablewidget中添加comboBox
//    for(int i=0; i<3;i++){
//        QComboBox *combox_state = new QComboBox();
//        combox_state->addItem("工作");
//        combox_state->addItem("待机");
//        ui->tableWidget->setCellWidget(i,1,(QWidget*)combox_state);
//    }
//    for(int i=0; i<3;i++){
//        QComboBox *combox_point = new QComboBox();
//        combox_point->addItem("2.66GHz");
//        combox_point->addItem("2.36GHz");
//        ui->tableWidget->setCellWidget(i,2,(QWidget*)combox_point);
//    }
//    for(int i=0; i<3;i++){
//        QComboBox *combox_bw = new QComboBox();
//        combox_bw->addItem("5.00M");
//        combox_bw->addItem("10.0M");
//        combox_bw->addItem("20.0M");
//        ui->tableWidget->setCellWidget(i,3,(QWidget*)combox_bw);
//    }
    /*
    for(int i=0; i<3;i++){
        QComboBox *combox_tx = new QComboBox();
        combox_tx->addItem("95.00dB");
        combox_tx->addItem("105.0dB");
        combox_tx->addItem("115.0dB");
        ui->tableWidget->setCellWidget(i,4,(QWidget*)combox_tx);
    }
    for(int i=0; i<3;i++){
        QComboBox *combox_rx = new QComboBox();
        combox_rx->addItem("90.00dB");
        combox_rx->addItem("100.0dB");
        combox_rx->addItem("110.0dB");
        ui->tableWidget->setCellWidget(i,5,(QWidget*)combox_rx);
    }
    for(int i=0; i<3;i++){
        QComboBox *combox_pw = new QComboBox();
        combox_pw->addItem("10dBm");
        combox_pw->addItem("15dBm");
        combox_pw->addItem("20dBm");
        ui->tableWidget->setCellWidget(i,6,(QWidget*)combox_pw);
    }
    */


}

config_mainwindow::~config_mainwindow()
{
   delete ui;
}

//窗口关闭事件
void config_mainwindow::closeEvent(QCloseEvent *)
{
    emit close_cg();
}

void config_mainwindow::on_pushButton_clicked()
{
    //发送信号给主界面
    qDebug() <<"config temp:" << tempeNBlist;
    if (!tempeNBlist.empty())
    {
        QString head=show_data()+"<font color=red>手动配置参数：</font>";
        emit emit_to_main(head);
        count = tempeNBlist.length();
        print_to_main(count);
    }
    else
        QMessageBox::information(0, "warning","请接入基站后重试");

}

//发送配置信息给主界面
void config_mainwindow::print_to_main(int length)
{
    QString checkData;
    QStringList  Tx, Rx, Pw, Prb;
    for(int i=0; i<length; i++){
        for(int k=4; k<8; k++){
            QTableWidgetItem *checkPrb = ui->tableWidget->item(i,k);
            QString checkPrbtext = checkPrb->text();
            checkData= checkData+","+checkPrbtext;
        }
        Tx.append(checkData.section(",",1,1));
        Rx.append(checkData.section(",",2,2));
        Pw.append(checkData.section(",",3,3));
        Prb.append(checkData.section(",",4,4));
    }
    for (int i=0; i<length; i++)
    {
        QRegExp regTRx("^[1-9][0-9]{0,2}\\.[0]{1,2}dB$");//TxRx
        QRegExp regPw("[1-9][0-9]dBm");
        QRegExp regPrb("[0-1]{13}");
        if((!regTRx.exactMatch(Tx[i]) || !regTRx.exactMatch(Rx[i]) || !regPw.exactMatch(Pw[i]) || !regPrb.exactMatch(Prb[i])) ||
                ( Tx[i].section('.',0,0).toInt()>127 || Rx[i].section('.',0,0).toInt() > 150))
        {
            QMessageBox::information(0, "warning","输入不符合规则！\n发送功率:60.00-127.0dB\n接收功率：60.00-150.0dB\n功率：\n物理资源块:13位，仅能输入0或1");
            return ;
        }
    }
    qDebug()<<"check"<<checkData;



    //发送信号给主界面
    QString head="ID                      状态                 频点                     带宽               发射增益           接收增益            功率                       PRB分配";
    emit emit_to_main(head);
    //遍历表中所有配置信息&发送
    for(int i=0; i<length; i++){
        QString data;
        QTableWidgetItem *itab = ui->tableWidget->item(i,0);
        QString itabtext = itab->text();
        data = itabtext+":  ";
        for(int j=1; j<4; j++){
            QComboBox* combo=(QComboBox*)ui->tableWidget->cellWidget(i,j);
            data=data+"            "+combo->currentText()+"  ";
        }
        for(int k=4; k<8; k++){
            QTableWidgetItem *prb = ui->tableWidget->item(i,k);
            QString prbtext = prb->text();
            data= data+"            "+prbtext+"  ";
        }
        emit emit_to_main(data);
        if (!check_on(data))
        {
            qDebug()<<itabtext <<":你选择了OFF,请选择ON进行传输!!!";
            continue;
        }
        for (int i=0; i<server1->socketMap.size(); i++)
        {
            if (!server1->socketList.empty())
            {
                if (server1->socketMap.value(server1->socketList.at(i)) == itabtext)
                {
                    qDebug() << "ABCDEFGHIJKLMNOGQRSTUVWXYZ";
                    if (!tempAllocList.empty())
                        data = data + "              "+ tempAllocList[i].mid(13,-1) + "              "+pwAllocList[i];
                    else
                        data = data +"              01111              0.10 20.00 97.00 -24.00 0.00 4.00";
                    qDebug() << data;
                    /*发送末端加上ip地址*/
                    data = data + "            " + getHostIpAddress() +"  ";
                    emit emit_confeNb(data, server1->socketList.at(i)); //发送数据以及套接字
                    break;
                }
            }
        }


    }
}

QString config_mainwindow::show_data()
{
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString str = time.toString("yyyy-MM-dd hh:mm:ss"); //设置显示格式
    QString data = "["+str+"]";
    return data;
}
/*获取SON服务器IP地址，下发给eNb进行配置文件自配置*/
QString config_mainwindow::getHostIpAddress()
{
    QString strIpAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // 获取第一个本机IPV4地址
    int nListSize = ipAddressesList.size();
    for (int i = 0; i < nListSize; i++)
    {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
                ipAddressesList.at(i).toIPv4Address())
        {
            strIpAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    if (strIpAddress.isEmpty())
        strIpAddress = QHostAddress(QHostAddress::LocalHost).toString();
    return strIpAddress;
}

//判断基站状态
bool config_mainwindow::check_on(QString check)
{
    if (check.contains("工作"))
        return true;
    else
        return false;
}

void config_mainwindow::add_eNB_otherinfo()
{
    QComboBox *combox_state = new QComboBox();
    combox_state->addItem("待机");
    combox_state->addItem("工作");
    ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1,1,(QWidget*)combox_state);
    QComboBox *combox_point = new QComboBox();
    combox_point->addItem("2.66GHz");
    combox_point->addItem("2.36GHz");
    ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1,2,(QWidget*)combox_point);
    QComboBox *combox_bw = new QComboBox();
    combox_bw->addItem("5.00M");
    combox_bw->addItem("10.0M");
    combox_bw->addItem("20.0M");
    ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1,3,(QWidget*)combox_bw);

    QTableWidgetItem *element_tx = new QTableWidgetItem("100.0dB");
    element_tx->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,4,element_tx);
    QTableWidgetItem *element_rx = new QTableWidgetItem("125.0dB");
    element_rx->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,5,element_rx);
    QTableWidgetItem *element_pw = new QTableWidgetItem("20dBm");
    element_pw->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,6,element_pw);
    QTableWidgetItem *element_prb = new QTableWidgetItem("0000000000000");
    element_prb->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,7,element_prb);
}

//点击覆盖最优
void config_mainwindow::on_cg_btn_cover_clicked()
{


    if (!tempeNBlist.empty())
    {
        QString head=show_data()+"<font color=red>[覆盖最优]策略参数：</font>";
        count = tempeNBlist.length();
        readPythonFile("Coverage_best", count);
        emit emit_to_main(head);

    }
    else
        QMessageBox::information(0, "warning","请接入基站后重试");


    //print_to_main();
}

//点击性能最优
void config_mainwindow::on_cg_btn_power_clicked()
{

    if (!tempeNBlist.empty())
    {
        QString head=show_data()+"<font color=red>[性能最优]策略参数：</font>";
        count = tempeNBlist.length();
        readPythonFile("self_optimization", count);
        emit emit_to_main(head);
    }
    else
        QMessageBox::information(0, "warning","请接入基站后重试");


    //print_to_main();
}

//点击吞吐量最优
void config_mainwindow::on_cg_btn_output_clicked()
{

    if (!tempeNBlist.empty())
    {
        QString head=show_data()+"<font color=red>[吞吐量最优]策略参数：</font>";
        count = tempeNBlist.length();
        readPythonFile("Throughput_best", count);
        emit emit_to_main(head);
    }
    else
        QMessageBox::information(0, "warning","请接入基站后重试");


    //print_to_main();
}
void config_mainwindow::readPythonFile(QString fileName, int eNBcount)
{
    Widget::judge_id = 0;
    qDebug() << "eNBcount: "<<eNBcount;
    threadPy = new threadReadPy(fileName);
    threadPy->start(QThread::HighestPriority);
    connect(threadPy, SIGNAL(finished()), threadPy, SLOT(deleteLater()));
    connect(threadPy,&threadReadPy::emit_endThread,threadPy,&threadReadPy::deleteLater);
    connect(threadPy, SIGNAL(finished()), widget, SLOT(heatmap()));
    connect(threadPy, SIGNAL(finished()), this, SLOT(readAllocFile()));
    connect(threadPy, SIGNAL(finished()), widget, SLOT(displayCoverate()));
}

/*function:用于获取算法中的PRB及功率分配结果*/
void config_mainwindow::readAllocFile()
{
    /*change to QStringlist*/
    /*rballoc read*/
    QFile file("/home/nano/S0_list.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray out;
    while(!file.atEnd())
    {
        out = file.readLine();
        tempAlloc = QString::fromLocal8Bit(out);
        tempAllocList.append(tempAlloc.remove(" ").trimmed());
    }
    /*用于刷新PRB显示*/
    for (int i = 0; i<count; i++)
    {
        ui->tableWidget->item(i,7)->setText(tempAllocList[i].mid(0,13));
        //qDebug() << tempAllocList[i];
        //qDebug() << tempAllocList[i].mid(0,13);
    }
    file.close();
    /*P_W read*/
    QFile P_file("/home/nano/PW_list.txt");
    P_file.open(QIODevice::ReadOnly | QIODevice::Text);
    while(!P_file.atEnd())
    {
        out = P_file.readLine();
        pwAlloc = QString::fromLocal8Bit(out);
        pwAllocList.append(pwAlloc.trimmed());
    }
    qDebug() << pwAllocList;
    P_file.close();
    for (int i = 0; i<count; i++)
    {
        //qDebug()<< pwAllocList[i].section(" ",2,2);
        //ui->tableWidget->item(i,4)->setText("25");
        ui->tableWidget->item(i,4)->setText(pwAllocList[i].section(" ",2,2)+"dB");

        //qDebug() << tempAllocList[i];
        //qDebug() << tempAllocList[i].mid(0,13);
    }
    print_to_main(count);
    tempAllocList.clear();
    pwAllocList.clear();

}

void config_mainwindow::display_eNB(QString eNB)
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    QTableWidgetItem *element = new QTableWidgetItem(eNB);
    element->setFlags(element->flags()&(~Qt::ItemIsEditable));
    element->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,element);
    tempeNBlist.append(eNB);
    add_eNB_otherinfo();

//    QComboBox *combox_state = new QComboBox();
//    combox_state->addItem("工作");
//    combox_state->addItem("待机");
//    ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1,1,(QWidget*)combox_state);
//    QComboBox *combox_point = new QComboBox();
//    combox_point->addItem("2.66GHz");
//    combox_point->addItem("2.36GHz");
//    ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1,2,(QWidget*)combox_point);
//    QComboBox *combox_bw = new QComboBox();
//    combox_bw->addItem("5.00M");
//    combox_bw->addItem("10.0M");
//    combox_bw->addItem("20.0M");
//    ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1,3,(QWidget*)combox_bw);

//    QTableWidgetItem *element_tx = new QTableWidgetItem("100.0dB");
//    element_tx->setFlags(element->flags()&(~Qt::ItemIsEditable));
//    element_tx->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
//    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,4,element_tx);
//    QTableWidgetItem *element_rx = new QTableWidgetItem("125.0dB");
//    element_rx->setFlags(element->flags()&(~Qt::ItemIsEditable));
//    element_rx->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
//    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,5,element_rx);
//    QTableWidgetItem *element_pw = new QTableWidgetItem("20dBm");
//    element_pw->setFlags(element->flags()&(~Qt::ItemIsEditable));
//    element_pw->setTextAlignmempeNBlist.ent(Qt::AlignHCenter|Qt::AlignVCenter);
//    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,6,element_pw);
//    QTableWidgetItem *element_prb = new QTableWidgetItem("0000000000000");
//    element_prb->setFlags(element->flags()&(~Qt::ItemIsEditable));
//    element_prb->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
//    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,7,element_prb);

}



void config_mainwindow::deleteeNB(QString eNB)
{
    tempeNBlist.removeAll(eNB);
    QList<QTableWidgetItem *> itemList;
    for(int i =0; i<ui->tableWidget->rowCount();i++){
        itemList<<ui->tableWidget->item(i,0);
    }
    foreach(QTableWidgetItem *item, itemList){
        if(item->text()== eNB){
            ui->tableWidget->removeRow(item->row());
        }
    }
    //tempeNBlist.removeAll(eNB);
}
