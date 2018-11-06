/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widgetTitle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labIco;
    QLabel *labTitle;
    QWidget *widgetTop;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *btnMg;
    QToolButton *btnBs;
    QToolButton *btnConfig;
    QSpacerItem *horizontalSpacer;
    QWidget *widgetmenu;
    QGridLayout *gridLayout;
    QPushButton *btn_min;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_close;
    QPushButton *btn_max;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QLabel *label;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(800, 600);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        widgetTitle = new QWidget(Widget);
        widgetTitle->setObjectName(QStringLiteral("widgetTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetTitle->sizePolicy().hasHeightForWidth());
        widgetTitle->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(widgetTitle);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 0, 0, 0);
        labIco = new QLabel(widgetTitle);
        labIco->setObjectName(QStringLiteral("labIco"));

        horizontalLayout_2->addWidget(labIco);

        labTitle = new QLabel(widgetTitle);
        labTitle->setObjectName(QStringLiteral("labTitle"));

        horizontalLayout_2->addWidget(labTitle);

        widgetTop = new QWidget(widgetTitle);
        widgetTop->setObjectName(QStringLiteral("widgetTop"));
        horizontalLayout_3 = new QHBoxLayout(widgetTop);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        btnMg = new QToolButton(widgetTop);
        btnMg->setObjectName(QStringLiteral("btnMg"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnMg->sizePolicy().hasHeightForWidth());
        btnMg->setSizePolicy(sizePolicy1);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/main_main.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMg->setIcon(icon);
        btnMg->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnMg);

        btnBs = new QToolButton(widgetTop);
        btnBs->setObjectName(QStringLiteral("btnBs"));
        sizePolicy1.setHeightForWidth(btnBs->sizePolicy().hasHeightForWidth());
        btnBs->setSizePolicy(sizePolicy1);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/main_company.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnBs->setIcon(icon1);
        btnBs->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnBs);

        btnConfig = new QToolButton(widgetTop);
        btnConfig->setObjectName(QStringLiteral("btnConfig"));
        sizePolicy1.setHeightForWidth(btnConfig->sizePolicy().hasHeightForWidth());
        btnConfig->setSizePolicy(sizePolicy1);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/main_config.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnConfig->setIcon(icon2);
        btnConfig->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnConfig);


        horizontalLayout_2->addWidget(widgetTop);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        widgetmenu = new QWidget(widgetTitle);
        widgetmenu->setObjectName(QStringLiteral("widgetmenu"));
        gridLayout = new QGridLayout(widgetmenu);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btn_min = new QPushButton(widgetmenu);
        btn_min->setObjectName(QStringLiteral("btn_min"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btn_min->sizePolicy().hasHeightForWidth());
        btn_min->setSizePolicy(sizePolicy2);
        btn_min->setMinimumSize(QSize(30, 30));
        btn_min->setAutoDefault(true);

        gridLayout->addWidget(btn_min, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        btn_close = new QPushButton(widgetmenu);
        btn_close->setObjectName(QStringLiteral("btn_close"));
        sizePolicy2.setHeightForWidth(btn_close->sizePolicy().hasHeightForWidth());
        btn_close->setSizePolicy(sizePolicy2);
        btn_close->setMinimumSize(QSize(30, 30));
        btn_close->setFocusPolicy(Qt::NoFocus);
        btn_close->setAutoDefault(true);

        gridLayout->addWidget(btn_close, 0, 2, 1, 1);

        btn_max = new QPushButton(widgetmenu);
        btn_max->setObjectName(QStringLiteral("btn_max"));
        sizePolicy2.setHeightForWidth(btn_max->sizePolicy().hasHeightForWidth());
        btn_max->setSizePolicy(sizePolicy2);
        btn_max->setMinimumSize(QSize(30, 30));
        btn_max->setAutoDefault(true);

        gridLayout->addWidget(btn_max, 0, 1, 1, 1);


        horizontalLayout_2->addWidget(widgetmenu);


        verticalLayout->addWidget(widgetTitle);

        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy3);
        tabWidget->setMinimumSize(QSize(798, 380));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(label);

        textBrowser = new QTextBrowser(Widget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setMaximumSize(QSize(16777215, 150));

        verticalLayout->addWidget(textBrowser);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        labIco->setText(QApplication::translate("Widget", "Img", 0));
        labTitle->setText(QApplication::translate("Widget", "<html><head/><body><p><span style=\" font-family:'arial,verdana,sans-serif'; font-size:23px; color:#DCDCDC;\">6G\347\256\200\346\231\272\346\227\240\347\272\277\346\216\245\345\205\245\347\275\221\346\274\224\347\244\272\345\271\263\345\217\260</span>", 0));
        btnMg->setText(QApplication::translate("Widget", "\347\256\241\347\220\206\346\226\271\346\241\210", 0));
        btnBs->setText(QApplication::translate("Widget", "\351\205\215\347\275\256\345\237\272\347\253\231", 0));
        btnConfig->setText(QApplication::translate("Widget", "\347\263\273\347\273\237\350\256\276\347\275\256", 0));
        btn_min->setText(QString());
        btn_close->setText(QString());
        btn_max->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\345\234\260\345\233\276", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "X-MAP\345\234\260\345\233\276", 0));
        label->setText(QApplication::translate("Widget", "\346\266\210\346\201\257\346\241\206\350\276\223\345\207\272", 0));
        textBrowser->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">hello world</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
