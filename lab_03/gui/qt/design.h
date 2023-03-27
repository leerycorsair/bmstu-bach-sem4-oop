/********************************************************************************
** Form generated from reading UI file 'design.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DESIGN_H
#define DESIGN_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_7;
    QFrame *move_label;
    QGridLayout *gridLayout_5;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QDoubleSpinBox *dy_box;
    QDoubleSpinBox *dz_box;
    QDoubleSpinBox *dx_box;
    QPushButton *move_btn;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_6;
    QFrame *frame_2;
    QGridLayout *gridLayout_6;
    QLabel *label_5;
    QLabel *label_4;
    QDoubleSpinBox *ky_box;
    QDoubleSpinBox *kx_box;
    QLabel *label_6;
    QDoubleSpinBox *kz_box;
    QPushButton *scale_btn;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_3;
    QGridLayout *gridLayout_7;
    QDoubleSpinBox *ay_box;
    QDoubleSpinBox *ax_box;
    QDoubleSpinBox *az_box;
    QPushButton *rotate_btn;
    QLabel *label_12;
    QLabel *label_11;
    QLabel *label_10;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *up_btn;
    QPushButton *left_btn;
    QPushButton *down_btn;
    QPushButton *right_btn;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QListWidget *objects_list;
    QPushButton *remove_object_btn;
    QPushButton *clear_scene_btn;
    QTabWidget *tabWidget_2;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_9;
    QFrame *frame_6;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_9;
    QLabel *curr_model_lbl;
    QPushButton *change_model_btn;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_8;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QLabel *curr_camera_lbl;
    QPushButton *change_camera_btn;
    QVBoxLayout *verticalLayout_10;
    QGraphicsView *graphicsView;
    QGridLayout *gridLayout_2;
    QPushButton *load_model_btn;
    QPushButton *load_camera_btn;
    QPushButton *add_camera_btn;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1345, 859);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush5(QColor(0, 0, 0, 128));
        brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        MainWindow->setPalette(palette);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(9);
        frame_4->setFont(font);
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(frame_4);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_7 = new QVBoxLayout(tab);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        move_label = new QFrame(tab);
        move_label->setObjectName(QString::fromUtf8("move_label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(move_label->sizePolicy().hasHeightForWidth());
        move_label->setSizePolicy(sizePolicy1);
        move_label->setFont(font);
        move_label->setFrameShape(QFrame::StyledPanel);
        move_label->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(move_label);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_3 = new QLabel(move_label);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        label_3->setFont(font1);

        gridLayout_5->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(move_label);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        gridLayout_5->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(move_label);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        gridLayout_5->addWidget(label, 0, 0, 1, 1);

        dy_box = new QDoubleSpinBox(move_label);
        dy_box->setObjectName(QString::fromUtf8("dy_box"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(11);
        dy_box->setFont(font2);
        dy_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        dy_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dy_box->setMinimum(-10000000000000000000000.000000000000000);
        dy_box->setMaximum(10000000000000000000000.000000000000000);

        gridLayout_5->addWidget(dy_box, 1, 1, 1, 1);

        dz_box = new QDoubleSpinBox(move_label);
        dz_box->setObjectName(QString::fromUtf8("dz_box"));
        dz_box->setFont(font2);
        dz_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        dz_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dz_box->setMinimum(-99999999999999991611392.000000000000000);
        dz_box->setMaximum(10000000000000000.000000000000000);

        gridLayout_5->addWidget(dz_box, 2, 1, 1, 1);

        dx_box = new QDoubleSpinBox(move_label);
        dx_box->setObjectName(QString::fromUtf8("dx_box"));
        dx_box->setMinimumSize(QSize(0, 1));
        dx_box->setFont(font2);
        dx_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        dx_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dx_box->setMinimum(-10000000000000000.000000000000000);
        dx_box->setMaximum(10000000000000000.000000000000000);

        gridLayout_5->addWidget(dx_box, 0, 1, 1, 1);

        move_btn = new QPushButton(move_label);
        move_btn->setObjectName(QString::fromUtf8("move_btn"));
        move_btn->setFont(font);

        gridLayout_5->addWidget(move_btn, 3, 0, 1, 2);


        verticalLayout_7->addWidget(move_label);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_6 = new QVBoxLayout(tab_3);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        frame_2 = new QFrame(tab_3);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setFont(font);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_2);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        gridLayout_6->addWidget(label_5, 1, 0, 1, 1);

        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        gridLayout_6->addWidget(label_4, 0, 0, 1, 1);

        ky_box = new QDoubleSpinBox(frame_2);
        ky_box->setObjectName(QString::fromUtf8("ky_box"));
        ky_box->setFont(font2);
        ky_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        ky_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ky_box->setMinimum(0.000000000000000);
        ky_box->setMaximum(10000000000000000000000.000000000000000);

        gridLayout_6->addWidget(ky_box, 1, 1, 1, 1);

        kx_box = new QDoubleSpinBox(frame_2);
        kx_box->setObjectName(QString::fromUtf8("kx_box"));
        kx_box->setFont(font2);
        kx_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        kx_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        kx_box->setMinimum(0.000000000000000);
        kx_box->setMaximum(10000000000000000.000000000000000);

        gridLayout_6->addWidget(kx_box, 0, 1, 1, 1);

        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        gridLayout_6->addWidget(label_6, 2, 0, 1, 1);

        kz_box = new QDoubleSpinBox(frame_2);
        kz_box->setObjectName(QString::fromUtf8("kz_box"));
        kz_box->setFont(font2);
        kz_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        kz_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        kz_box->setMinimum(0.000000000000000);
        kz_box->setMaximum(10000000000000000.000000000000000);

        gridLayout_6->addWidget(kz_box, 2, 1, 1, 1);

        scale_btn = new QPushButton(frame_2);
        scale_btn->setObjectName(QString::fromUtf8("scale_btn"));
        scale_btn->setFont(font);

        gridLayout_6->addWidget(scale_btn, 3, 0, 1, 2);


        verticalLayout_6->addWidget(frame_2);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_5 = new QVBoxLayout(tab_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        frame_3 = new QFrame(tab_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setFont(font);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame_3);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        ay_box = new QDoubleSpinBox(frame_3);
        ay_box->setObjectName(QString::fromUtf8("ay_box"));
        ay_box->setFont(font2);
        ay_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        ay_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ay_box->setMinimum(-10000000000000000000000.000000000000000);
        ay_box->setMaximum(10000000000000000000000.000000000000000);

        gridLayout_7->addWidget(ay_box, 1, 1, 1, 1);

        ax_box = new QDoubleSpinBox(frame_3);
        ax_box->setObjectName(QString::fromUtf8("ax_box"));
        ax_box->setFont(font2);
        ax_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        ax_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ax_box->setMinimum(-10000000000000000.000000000000000);
        ax_box->setMaximum(10000000000000000.000000000000000);

        gridLayout_7->addWidget(ax_box, 0, 1, 1, 1);

        az_box = new QDoubleSpinBox(frame_3);
        az_box->setObjectName(QString::fromUtf8("az_box"));
        az_box->setFont(font2);
        az_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        az_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        az_box->setMinimum(-99999999999999991611392.000000000000000);
        az_box->setMaximum(10000000000000000.000000000000000);

        gridLayout_7->addWidget(az_box, 2, 1, 1, 1);

        rotate_btn = new QPushButton(frame_3);
        rotate_btn->setObjectName(QString::fromUtf8("rotate_btn"));
        rotate_btn->setFont(font);

        gridLayout_7->addWidget(rotate_btn, 3, 0, 1, 2);

        label_12 = new QLabel(frame_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font1);

        gridLayout_7->addWidget(label_12, 1, 0, 1, 1);

        label_11 = new QLabel(frame_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font1);

        gridLayout_7->addWidget(label_11, 0, 0, 1, 1);

        label_10 = new QLabel(frame_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font1);

        gridLayout_7->addWidget(label_10, 2, 0, 1, 1);


        verticalLayout_5->addWidget(frame_3);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        groupBox = new QGroupBox(frame_4);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        up_btn = new QPushButton(groupBox);
        up_btn->setObjectName(QString::fromUtf8("up_btn"));
        up_btn->setFont(font);

        gridLayout->addWidget(up_btn, 0, 1, 1, 1);

        left_btn = new QPushButton(groupBox);
        left_btn->setObjectName(QString::fromUtf8("left_btn"));
        left_btn->setFont(font);

        gridLayout->addWidget(left_btn, 1, 0, 1, 1);

        down_btn = new QPushButton(groupBox);
        down_btn->setObjectName(QString::fromUtf8("down_btn"));
        down_btn->setFont(font);

        gridLayout->addWidget(down_btn, 1, 1, 1, 1);

        right_btn = new QPushButton(groupBox);
        right_btn->setObjectName(QString::fromUtf8("right_btn"));
        right_btn->setFont(font);

        gridLayout->addWidget(right_btn, 1, 2, 1, 1);


        verticalLayout->addWidget(groupBox);

        frame = new QFrame(frame_4);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFont(font);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_7);

        objects_list = new QListWidget(frame);
        objects_list->setObjectName(QString::fromUtf8("objects_list"));

        verticalLayout_2->addWidget(objects_list);

        remove_object_btn = new QPushButton(frame);
        remove_object_btn->setObjectName(QString::fromUtf8("remove_object_btn"));
        remove_object_btn->setFont(font);

        verticalLayout_2->addWidget(remove_object_btn);

        clear_scene_btn = new QPushButton(frame);
        clear_scene_btn->setObjectName(QString::fromUtf8("clear_scene_btn"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(clear_scene_btn->sizePolicy().hasHeightForWidth());
        clear_scene_btn->setSizePolicy(sizePolicy2);
        clear_scene_btn->setFont(font);

        verticalLayout_2->addWidget(clear_scene_btn);


        verticalLayout->addWidget(frame);

        tabWidget_2 = new QTabWidget(frame_4);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_9 = new QVBoxLayout(tab_4);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        frame_6 = new QFrame(tab_4);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setFont(font);
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_9 = new QLabel(frame_6);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font2);
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_9);

        curr_model_lbl = new QLabel(frame_6);
        curr_model_lbl->setObjectName(QString::fromUtf8("curr_model_lbl"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setWeight(75);
        curr_model_lbl->setFont(font3);
        curr_model_lbl->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(curr_model_lbl);


        verticalLayout_4->addLayout(horizontalLayout);

        change_model_btn = new QPushButton(frame_6);
        change_model_btn->setObjectName(QString::fromUtf8("change_model_btn"));
        change_model_btn->setFont(font);

        verticalLayout_4->addWidget(change_model_btn);


        verticalLayout_9->addWidget(frame_6);

        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        verticalLayout_8 = new QVBoxLayout(tab_5);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        frame_5 = new QFrame(tab_5);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFont(font);
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_5);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_8 = new QLabel(frame_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font2);
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_8);

        curr_camera_lbl = new QLabel(frame_5);
        curr_camera_lbl->setObjectName(QString::fromUtf8("curr_camera_lbl"));
        curr_camera_lbl->setFont(font3);
        curr_camera_lbl->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(curr_camera_lbl);


        verticalLayout_3->addLayout(horizontalLayout_2);

        change_camera_btn = new QPushButton(frame_5);
        change_camera_btn->setObjectName(QString::fromUtf8("change_camera_btn"));
        change_camera_btn->setFont(font);

        verticalLayout_3->addWidget(change_camera_btn);


        verticalLayout_8->addWidget(frame_5);

        tabWidget_2->addTab(tab_5, QString());

        verticalLayout->addWidget(tabWidget_2);


        formLayout->setWidget(0, QFormLayout::LabelRole, frame_4);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setFont(font);

        verticalLayout_10->addWidget(graphicsView);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        load_model_btn = new QPushButton(centralwidget);
        load_model_btn->setObjectName(QString::fromUtf8("load_model_btn"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Ubuntu"));
        font4.setPointSize(10);
        load_model_btn->setFont(font4);

        gridLayout_2->addWidget(load_model_btn, 0, 0, 1, 1);

        load_camera_btn = new QPushButton(centralwidget);
        load_camera_btn->setObjectName(QString::fromUtf8("load_camera_btn"));
        load_camera_btn->setFont(font4);

        gridLayout_2->addWidget(load_camera_btn, 0, 1, 1, 1);

        add_camera_btn = new QPushButton(centralwidget);
        add_camera_btn->setObjectName(QString::fromUtf8("add_camera_btn"));
        add_camera_btn->setFont(font4);

        gridLayout_2->addWidget(add_camera_btn, 0, 2, 1, 1);


        verticalLayout_10->addLayout(gridLayout_2);


        formLayout->setLayout(0, QFormLayout::FieldRole, verticalLayout_10);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(dx_box, dy_box);
        QWidget::setTabOrder(dy_box, dz_box);
        QWidget::setTabOrder(dz_box, move_btn);
        QWidget::setTabOrder(move_btn, kx_box);
        QWidget::setTabOrder(kx_box, ky_box);
        QWidget::setTabOrder(ky_box, kz_box);
        QWidget::setTabOrder(kz_box, scale_btn);
        QWidget::setTabOrder(scale_btn, ax_box);
        QWidget::setTabOrder(ax_box, ay_box);
        QWidget::setTabOrder(ay_box, az_box);
        QWidget::setTabOrder(az_box, rotate_btn);
        QWidget::setTabOrder(rotate_btn, remove_object_btn);
        QWidget::setTabOrder(remove_object_btn, change_camera_btn);
        QWidget::setTabOrder(change_camera_btn, left_btn);
        QWidget::setTabOrder(left_btn, up_btn);
        QWidget::setTabOrder(up_btn, load_model_btn);
        QWidget::setTabOrder(load_model_btn, add_camera_btn);
        QWidget::setTabOrder(add_camera_btn, down_btn);
        QWidget::setTabOrder(down_btn, right_btn);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        objects_list->setCurrentRow(-1);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Lab 03", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", " dz", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", " dy", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", " dx", nullptr));
        move_btn->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "M", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", " ky", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", " kx", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", " kz", nullptr));
        scale_btn->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "S", nullptr));
        rotate_btn->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "ay", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "ax", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "az", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "R", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\224\320\262\320\270\320\266\320\265\320\275\320\270\320\265 \320\272\320\260\320\274\320\265\321\200\321\213", nullptr));
        up_btn->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\321\200\321\205", nullptr));
        left_btn->setText(QCoreApplication::translate("MainWindow", "\320\222\320\273\320\265\320\262\320\276", nullptr));
        down_btn->setText(QCoreApplication::translate("MainWindow", "\320\222\320\275\320\270\320\267", nullptr));
        right_btn->setText(QCoreApplication::translate("MainWindow", "\320\222\320\277\321\200\320\260\320\262\320\276", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\272\321\202\321\213 \321\201\321\206\320\265\320\275\321\213", nullptr));
        remove_object_btn->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\276\320\261\321\212\320\265\320\272\321\202", nullptr));
        clear_scene_btn->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\201\321\206\320\265\320\275\321\203", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217:", nullptr));
        curr_model_lbl->setText(QCoreApplication::translate("MainWindow", "\320\235\320\265\321\202", nullptr));
        change_model_btn->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217:", nullptr));
        curr_camera_lbl->setText(QCoreApplication::translate("MainWindow", "\320\235\320\265\321\202", nullptr));
        change_camera_btn->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QCoreApplication::translate("MainWindow", "\320\232\320\260\320\274\320\265\321\200\320\260", nullptr));
        load_model_btn->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\274\320\276\320\264\320\265\320\273\321\214", nullptr));
        load_camera_btn->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\272\320\260\320\274\320\265\321\200\321\203", nullptr));
        add_camera_btn->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\320\260\320\274\320\265\321\200\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DESIGN_H
