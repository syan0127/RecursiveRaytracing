/********************************************************************************
** Form generated from reading UI file 'samplercontrols.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAMPLERCONTROLS_H
#define UI_SAMPLERCONTROLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SamplerControls
{
public:
    QLabel *label;
    QLabel *label_2;
    QFrame *line;
    QSlider *numSamplesSlider;
    QSpinBox *numSamplesSpinBox;
    QComboBox *comboBox;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox_2;
    QCheckBox *checkBox;
    QFrame *line_2;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QFrame *line_3;
    QPushButton *pushButton;
    QLabel *discUnifPDFLabel;
    QLabel *discConcPDFLabel;
    QLabel *spherePDFLabel;
    QLabel *sphereCapPDFLabel;
    QLabel *hemiUnifPDFLabel;
    QLabel *hemiCosPDFLabel;
    QSpinBox *thetaMaxSpinBox;
    QLabel *label_12;

    void setupUi(QWidget *SamplerControls)
    {
        if (SamplerControls->objectName().isEmpty())
            SamplerControls->setObjectName(QStringLiteral("SamplerControls"));
        SamplerControls->resize(260, 543);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SamplerControls->sizePolicy().hasHeightForWidth());
        SamplerControls->setSizePolicy(sizePolicy);
        SamplerControls->setStyleSheet(QStringLiteral("background-color: yellow;"));
        label = new QLabel(SamplerControls);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 241, 50));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(12);
        label->setFont(font);
        label->setStyleSheet(QLatin1String("QLabel {\n"
"	font: \"Comic Sans MS\";\n"
"	color: magenta;\n"
"}"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(SamplerControls);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 101, 21));
        QFont font1;
        font1.setFamily(QStringLiteral("Comic Sans MS"));
        font1.setPointSize(8);
        label_2->setFont(font1);
        label_2->setStyleSheet(QLatin1String("QLabel {\n"
"	font: \"Comic Sans MS\";\n"
"	color: blue;\n"
";\n"
"}"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        line = new QFrame(SamplerControls);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 40, 241, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        numSamplesSlider = new QSlider(SamplerControls);
        numSamplesSlider->setObjectName(QStringLiteral("numSamplesSlider"));
        numSamplesSlider->setGeometry(QRect(10, 90, 160, 22));
        numSamplesSlider->setStyleSheet(QLatin1String("QSlider::handle:horizontal {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #ff85d0, stop:1 #ff3fb4);\n"
"    border: 1px solid #5c5c5c;\n"
"    width: 10px;\n"
"    margin: -7px 0; /* handle is placed by default on the contents rect of the groove. Expand outside the groove */\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    border: 1px solid #999999;\n"
"    height: 8px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #ff85d0, stop:1 #cb67a4);\n"
"    margin: 2px 0;\n"
"}"));
        numSamplesSlider->setMinimum(4);
        numSamplesSlider->setMaximum(16);
        numSamplesSlider->setSingleStep(1);
        numSamplesSlider->setPageStep(2);
        numSamplesSlider->setValue(10);
        numSamplesSlider->setOrientation(Qt::Horizontal);
        numSamplesSpinBox = new QSpinBox(SamplerControls);
        numSamplesSpinBox->setObjectName(QStringLiteral("numSamplesSpinBox"));
        numSamplesSpinBox->setEnabled(false);
        numSamplesSpinBox->setGeometry(QRect(180, 90, 71, 22));
        numSamplesSpinBox->setStyleSheet(QLatin1String("QSpinBox{\n"
"	background-color: rgb(226, 153, 186);\n"
"    border-radius: 5px;\n"
"}\n"
"QSpinBox::down-button{\n"
"	color: pink;\n"
"    border-radius: 5px;\n"
"}\n"
"QSpinBox::up-button{\n"
"	color: black;\n"
"    border-radius: 5px;\n"
"}\n"
""));
        numSamplesSpinBox->setMinimum(16);
        numSamplesSpinBox->setMaximum(1048576);
        numSamplesSpinBox->setSingleStep(10);
        numSamplesSpinBox->setValue(1024);
        comboBox = new QComboBox(SamplerControls);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(10, 150, 241, 31));
        comboBox->setStyleSheet(QLatin1String("QComboBox {\n"
"    border: 1px solid rgb(255, 85, 255);\n"
"    border-radius: 5px;\n"
"    padding: 1px 18px 1px 3px;\n"
"    min-width: 6em;\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"\n"
"    border-left-width: 1px;\n"
"    border-left-color: rgb(255, 85, 255);\n"
"    border-left-style: solid; /* just a single line */\n"
"    border-top-right-radius: 5px; /* same radius as the QComboBox */\n"
"    border-bottom-right-radius: 5px;\n"
"}\n"
"QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    border: 2px solid rgb(255, 170, 255);\n"
"    selection-background-color: rgb(255, 170, 255);\n"
"	font: \"Comic Sans MS\";\n"
"    border-radius: 5px;\n"
"}"));
        label_3 = new QLabel(SamplerControls);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 120, 131, 21));
        label_3->setFont(font1);
        label_3->setStyleSheet(QLatin1String("QLabel {\n"
"	font: \"Comic Sans MS\";\n"
"	color: blue;\n"
";\n"
"}"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_4 = new QLabel(SamplerControls);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 190, 131, 21));
        label_4->setFont(font1);
        label_4->setStyleSheet(QLatin1String("QLabel {\n"
"	font: \"Comic Sans MS\";\n"
"	color: blue;\n"
";\n"
"}"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        comboBox_2 = new QComboBox(SamplerControls);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(10, 220, 241, 31));
        comboBox_2->setStyleSheet(QLatin1String("QComboBox {\n"
"    border: 1px solid rgb(255, 85, 255);\n"
"    border-radius: 5px;\n"
"    padding: 1px 18px 1px 3px;\n"
"    min-width: 6em;\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"\n"
"    border-left-width: 1px;\n"
"    border-left-color: rgb(255, 85, 255);\n"
"    border-left-style: solid; /* just a single line */\n"
"    border-top-right-radius: 5px; /* same radius as the QComboBox */\n"
"    border-bottom-right-radius: 5px;\n"
"}\n"
"QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    border: 2px solid rgb(255, 170, 255);\n"
"    selection-background-color: rgb(255, 170, 255);\n"
"	font: \"Comic Sans MS\";\n"
"    border-radius: 5px;\n"
"}"));
        checkBox = new QCheckBox(SamplerControls);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(10, 270, 119, 20));
        checkBox->setStyleSheet(QLatin1String("QCheckBox::indicator{\n"
"    border: 1px solid rgb(255, 85, 255);\n"
"    border-radius: 5px;\n"
"    padding: 1px 1px 1px 3px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"    background-color: yellow;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: rgb(255, 170, 255)\n"
"}"));
        line_2 = new QFrame(SamplerControls);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(10, 290, 241, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_6 = new QLabel(SamplerControls);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 300, 241, 50));
        label_6->setFont(font);
        label_6->setStyleSheet(QLatin1String("QLabel {\n"
"	font: \"Comic Sans MS\";\n"
"	color: magenta;\n"
"}"));
        label_6->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(SamplerControls);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 350, 131, 21));
        label_5->setFont(font1);
        label_5->setStyleSheet(QLatin1String("QLabel {\n"
"	font: \"Comic Sans MS\";\n"
"	color: blue;\n"
";\n"
"}"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_7 = new QLabel(SamplerControls);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 370, 131, 21));
        label_7->setFont(font1);
        label_7->setStyleSheet(QLatin1String("QLabel {\n"
"	font: \"Comic Sans MS\";\n"
"	color: blue;\n"
";\n"
"}"));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_8 = new QLabel(SamplerControls);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 390, 131, 21));
        label_8->setFont(font1);
        label_8->setStyleSheet(QLatin1String("QLabel {\n"
"	font: \"Comic Sans MS\";\n"
"	color: blue;\n"
";\n"
"}"));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_9 = new QLabel(SamplerControls);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 410, 131, 21));
        label_9->setFont(font1);
        label_9->setStyleSheet(QLatin1String("QLabel {\n"
"	font: \"Comic Sans MS\";\n"
"	color: blue;\n"
";\n"
"}"));
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_10 = new QLabel(SamplerControls);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 430, 141, 21));
        label_10->setFont(font1);
        label_10->setStyleSheet(QLatin1String("QLabel {\n"
"	font: \"Comic Sans MS\";\n"
"	color: blue;\n"
";\n"
"}"));
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_11 = new QLabel(SamplerControls);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 450, 141, 21));
        label_11->setFont(font1);
        label_11->setStyleSheet(QLatin1String("QLabel {\n"
"	font: \"Comic Sans MS\";\n"
"	color: blue;\n"
";\n"
"}"));
        label_11->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        line_3 = new QFrame(SamplerControls);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(150, 350, 16, 121));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        pushButton = new QPushButton(SamplerControls);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 490, 93, 28));
        QFont font2;
        font2.setFamily(QStringLiteral("Comic Sans MS"));
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QLatin1String("QPushButton {\n"
"    border: 2px solid rgb(85, 255, 255);\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 rgb(255, 170, 255), stop: 1 rgb(255, 85, 255));\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 rgb(255, 85, 255), stop: 1 rgb(255, 170, 255));\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        discUnifPDFLabel = new QLabel(SamplerControls);
        discUnifPDFLabel->setObjectName(QStringLiteral("discUnifPDFLabel"));
        discUnifPDFLabel->setGeometry(QRect(170, 350, 81, 21));
        discUnifPDFLabel->setFont(font1);
        discUnifPDFLabel->setStyleSheet(QLatin1String("QLabel {\n"
"	font: \"Comic Sans MS\";\n"
"	color: blue;\n"
";\n"
"}"));
        discUnifPDFLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        discConcPDFLabel = new QLabel(SamplerControls);
        discConcPDFLabel->setObjectName(QStringLiteral("discConcPDFLabel"));
        discConcPDFLabel->setGeometry(QRect(170, 370, 81, 21));
        discConcPDFLabel->setFont(font1);
        discConcPDFLabel->setStyleSheet(QLatin1String("QLabel {\n"
"	font: \"Comic Sans MS\";\n"
"	color: blue;\n"
";\n"
"}"));
        discConcPDFLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        spherePDFLabel = new QLabel(SamplerControls);
        spherePDFLabel->setObjectName(QStringLiteral("spherePDFLabel"));
        spherePDFLabel->setGeometry(QRect(170, 390, 81, 21));
        spherePDFLabel->setFont(font1);
        spherePDFLabel->setStyleSheet(QLatin1String("QLabel {\n"
"	font: \"Comic Sans MS\";\n"
"	color: blue;\n"
";\n"
"}"));
        spherePDFLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        sphereCapPDFLabel = new QLabel(SamplerControls);
        sphereCapPDFLabel->setObjectName(QStringLiteral("sphereCapPDFLabel"));
        sphereCapPDFLabel->setGeometry(QRect(170, 410, 81, 21));
        sphereCapPDFLabel->setFont(font1);
        sphereCapPDFLabel->setStyleSheet(QLatin1String("QLabel {\n"
"	font: \"Comic Sans MS\";\n"
"	color: blue;\n"
";\n"
"}"));
        sphereCapPDFLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        hemiUnifPDFLabel = new QLabel(SamplerControls);
        hemiUnifPDFLabel->setObjectName(QStringLiteral("hemiUnifPDFLabel"));
        hemiUnifPDFLabel->setGeometry(QRect(170, 430, 81, 21));
        hemiUnifPDFLabel->setFont(font1);
        hemiUnifPDFLabel->setStyleSheet(QLatin1String("QLabel {\n"
"	font: \"Comic Sans MS\";\n"
"	color: blue;\n"
";\n"
"}"));
        hemiUnifPDFLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        hemiCosPDFLabel = new QLabel(SamplerControls);
        hemiCosPDFLabel->setObjectName(QStringLiteral("hemiCosPDFLabel"));
        hemiCosPDFLabel->setGeometry(QRect(170, 450, 81, 21));
        hemiCosPDFLabel->setFont(font1);
        hemiCosPDFLabel->setStyleSheet(QLatin1String("QLabel {\n"
"	font: \"Comic Sans MS\";\n"
"	color: blue;\n"
";\n"
"}"));
        hemiCosPDFLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        thetaMaxSpinBox = new QSpinBox(SamplerControls);
        thetaMaxSpinBox->setObjectName(QStringLiteral("thetaMaxSpinBox"));
        thetaMaxSpinBox->setEnabled(false);
        thetaMaxSpinBox->setGeometry(QRect(200, 260, 41, 31));
        thetaMaxSpinBox->setStyleSheet(QLatin1String("QSpinBox{\n"
"	background-color: rgb(226, 153, 186);\n"
"    border-radius: 5px;\n"
"}\n"
"QSpinBox::down-button{\n"
"	color: pink;\n"
"    border-radius: 5px;\n"
"}\n"
"QSpinBox::up-button{\n"
"	color: black;\n"
"    border-radius: 5px;\n"
"}\n"
""));
        thetaMaxSpinBox->setMinimum(0);
        thetaMaxSpinBox->setMaximum(180);
        thetaMaxSpinBox->setSingleStep(1);
        thetaMaxSpinBox->setValue(150);
        label_12 = new QLabel(SamplerControls);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(120, 260, 71, 31));
        label_12->setFont(font1);
        label_12->setStyleSheet(QLatin1String("QLabel {\n"
"	font: \"Comic Sans MS\";\n"
"	color: blue;\n"
";\n"
"}"));
        label_12->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        retranslateUi(SamplerControls);
        QObject::connect(numSamplesSlider, SIGNAL(valueChanged(int)), SamplerControls, SLOT(slot_setSamples(int)));
        QObject::connect(comboBox, SIGNAL(currentIndexChanged(int)), SamplerControls, SLOT(slot_setSampleMode(int)));
        QObject::connect(comboBox_2, SIGNAL(currentIndexChanged(int)), SamplerControls, SLOT(slot_setWarpMethod(int)));
        QObject::connect(checkBox, SIGNAL(clicked()), SamplerControls, SLOT(slot_setDisplayGrid()));
        QObject::connect(pushButton, SIGNAL(clicked()), SamplerControls, SLOT(slot_computePDFs()));
        QObject::connect(thetaMaxSpinBox, SIGNAL(valueChanged(int)), SamplerControls, SLOT(slot_updateThetaMax(int)));

        QMetaObject::connectSlotsByName(SamplerControls);
    } // setupUi

    void retranslateUi(QWidget *SamplerControls)
    {
        SamplerControls->setWindowTitle(QApplication::translate("SamplerControls", "Sample Warper Controls", Q_NULLPTR));
        label->setText(QApplication::translate("SamplerControls", "Sample Warping Controls", Q_NULLPTR));
        label_2->setText(QApplication::translate("SamplerControls", "Sample Count", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("SamplerControls", "Random", Q_NULLPTR)
         << QApplication::translate("SamplerControls", "Grid", Q_NULLPTR)
         << QApplication::translate("SamplerControls", "Stratified", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("SamplerControls", "Sample Distribution", Q_NULLPTR));
        label_4->setText(QApplication::translate("SamplerControls", "Warping Method", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("SamplerControls", "None", Q_NULLPTR)
         << QApplication::translate("SamplerControls", "Disc (Uniform)", Q_NULLPTR)
         << QApplication::translate("SamplerControls", "Disc (Concentric)", Q_NULLPTR)
         << QApplication::translate("SamplerControls", "Sphere", Q_NULLPTR)
         << QApplication::translate("SamplerControls", "Sphere Cap", Q_NULLPTR)
         << QApplication::translate("SamplerControls", "Hemisphere (Uniform)", Q_NULLPTR)
         << QApplication::translate("SamplerControls", "Hemisphere (Cosine Weighted)", Q_NULLPTR)
        );
        checkBox->setText(QApplication::translate("SamplerControls", "Display Grid", Q_NULLPTR));
        label_6->setText(QApplication::translate("SamplerControls", "PDF Integral Results", Q_NULLPTR));
        label_5->setText(QApplication::translate("SamplerControls", "Disc (Uniform)", Q_NULLPTR));
        label_7->setText(QApplication::translate("SamplerControls", "Disc (Concentric)", Q_NULLPTR));
        label_8->setText(QApplication::translate("SamplerControls", "Sphere", Q_NULLPTR));
        label_9->setText(QApplication::translate("SamplerControls", "Sphere Cap", Q_NULLPTR));
        label_10->setText(QApplication::translate("SamplerControls", "Hemisphere (Uniform)", Q_NULLPTR));
        label_11->setText(QApplication::translate("SamplerControls", "Hemisphere (Cosine)", Q_NULLPTR));
        pushButton->setText(QApplication::translate("SamplerControls", "Compute PDFs", Q_NULLPTR));
        discUnifPDFLabel->setText(QApplication::translate("SamplerControls", "0", Q_NULLPTR));
        discConcPDFLabel->setText(QApplication::translate("SamplerControls", "0", Q_NULLPTR));
        spherePDFLabel->setText(QApplication::translate("SamplerControls", "0", Q_NULLPTR));
        sphereCapPDFLabel->setText(QApplication::translate("SamplerControls", "0", Q_NULLPTR));
        hemiUnifPDFLabel->setText(QApplication::translate("SamplerControls", "0", Q_NULLPTR));
        hemiCosPDFLabel->setText(QApplication::translate("SamplerControls", "0", Q_NULLPTR));
        label_12->setText(QApplication::translate("SamplerControls", "Min Theta", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SamplerControls: public Ui_SamplerControls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAMPLERCONTROLS_H
