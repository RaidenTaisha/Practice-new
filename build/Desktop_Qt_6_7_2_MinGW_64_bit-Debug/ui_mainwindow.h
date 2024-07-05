/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *showMorePref;
    QAction *action_3;
    QWidget *centralwidget;
    QPushButton *buttonFile;
    QLabel *label;
    QLineEdit *editFile;
    QPushButton *buttonDoFragment;
    QFrame *frame;
    QLabel *label_2;
    QSpinBox *spinFragments;
    QLabel *label_4;
    QSpinBox *spinIDfragments;
    QLabel *label_5;
    QLineEdit *editProtocols;
    QLabel *label_6;
    QSpinBox *spinTypePoint;
    QLabel *label_7;
    QLineEdit *editPoint;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(432, 366);
        QFont font;
        font.setPointSize(9);
        MainWindow->setFont(font);
        MainWindow->setToolTipDuration(-1);
        MainWindow->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        MainWindow->setDockOptions(QMainWindow::DockOption::AllowTabbedDocks|QMainWindow::DockOption::AnimatedDocks);
        showMorePref = new QAction(MainWindow);
        showMorePref->setObjectName("showMorePref");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentProperties));
        showMorePref->setIcon(icon);
        QFont font1;
        showMorePref->setFont(font1);
        showMorePref->setMenuRole(QAction::MenuRole::PreferencesRole);
        action_3 = new QAction(MainWindow);
        action_3->setObjectName("action_3");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::SystemLogOut));
        action_3->setIcon(icon1);
        action_3->setMenuRole(QAction::MenuRole::QuitRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        buttonFile = new QPushButton(centralwidget);
        buttonFile->setObjectName("buttonFile");
        buttonFile->setGeometry(QRect(210, 10, 80, 31));
        QFont font2;
        font2.setPointSize(14);
        buttonFile->setFont(font2);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 0, 191, 51));
        label->setFont(font2);
        label->setAlignment(Qt::AlignmentFlag::AlignJustify|Qt::AlignmentFlag::AlignVCenter);
        editFile = new QLineEdit(centralwidget);
        editFile->setObjectName("editFile");
        editFile->setGeometry(QRect(10, 50, 401, 24));
        editFile->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        buttonDoFragment = new QPushButton(centralwidget);
        buttonDoFragment->setObjectName("buttonDoFragment");
        buttonDoFragment->setGeometry(QRect(110, 280, 181, 41));
        buttonDoFragment->setFont(font2);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 80, 411, 201));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 191, 41));
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignmentFlag::AlignJustify|Qt::AlignmentFlag::AlignVCenter);
        spinFragments = new QSpinBox(frame);
        spinFragments->setObjectName("spinFragments");
        spinFragments->setGeometry(QRect(260, 10, 42, 25));
        spinFragments->setFont(font2);
        spinFragments->setMinimum(1);
        spinFragments->setMaximum(3);
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 40, 251, 41));
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignmentFlag::AlignJustify|Qt::AlignmentFlag::AlignVCenter);
        spinIDfragments = new QSpinBox(frame);
        spinIDfragments->setObjectName("spinIDfragments");
        spinIDfragments->setGeometry(QRect(260, 50, 42, 25));
        spinIDfragments->setFont(font2);
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 80, 141, 41));
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignmentFlag::AlignJustify|Qt::AlignmentFlag::AlignVCenter);
        editProtocols = new QLineEdit(frame);
        editProtocols->setObjectName("editProtocols");
        editProtocols->setGeometry(QRect(260, 90, 141, 24));
        editProtocols->setFont(font2);
        editProtocols->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        editProtocols->setInputMask(QString::fromUtf8(""));
        editProtocols->setText(QString::fromUtf8(""));
        editProtocols->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        label_6 = new QLabel(frame);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 120, 101, 41));
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignmentFlag::AlignJustify|Qt::AlignmentFlag::AlignVCenter);
        spinTypePoint = new QSpinBox(frame);
        spinTypePoint->setObjectName("spinTypePoint");
        spinTypePoint->setGeometry(QRect(260, 130, 42, 25));
        spinTypePoint->setFont(font2);
        spinTypePoint->setMinimum(3);
        spinTypePoint->setMaximum(6);
        spinTypePoint->setSingleStep(3);
        label_7 = new QLabel(frame);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(0, 160, 71, 41));
        label_7->setFont(font2);
        label_7->setAlignment(Qt::AlignmentFlag::AlignJustify|Qt::AlignmentFlag::AlignVCenter);
        editPoint = new QLineEdit(frame);
        editPoint->setObjectName("editPoint");
        editPoint->setGeometry(QRect(260, 170, 141, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 432, 21));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(showMorePref);
        menu->addSeparator();
        menu->addAction(action_3);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        showMorePref->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        buttonFile->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\267\320\276\321\200", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \321\204\320\260\320\271\320\273\320\260", nullptr));
        buttonDoFragment->setText(QCoreApplication::translate("MainWindow", "\320\244\321\200\320\260\320\263\320\274\320\265\320\275\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273-\320\262\320\276 \321\204\321\200\320\260\320\263\320\274\320\265\320\275\321\202\320\276\320\262", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\230\320\264\320\265\320\275\321\202\320\270\321\204\320\270\320\272\320\260\321\202\320\276\321\200 \321\204\321\200\320\260\320\263\320\274\320\265\320\275\321\202\320\260 ", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\277\321\200\320\276\321\202\320\276\320\272\320\276\320\273\320\260", nullptr));
        editProtocols->setPlaceholderText(QCoreApplication::translate("MainWindow", "0x0800", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\274\320\265\321\202\320\272\320\270", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\202\320\272\320\260", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
