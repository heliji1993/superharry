/********************************************************************************
** Form generated from reading UI file 'myplane.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYPLANE_H
#define UI_MYPLANE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myplane
{
public:
    QGridLayout *gridLayout;
    QProgressBar *progressBar;

    void setupUi(QWidget *myplane)
    {
        if (myplane->objectName().isEmpty())
            myplane->setObjectName(QStringLiteral("myplane"));
        myplane->resize(537, 430);
        myplane->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(myplane);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        progressBar = new QProgressBar(myplane);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 0, 0, 1, 1);


        retranslateUi(myplane);

        QMetaObject::connectSlotsByName(myplane);
    } // setupUi

    void retranslateUi(QWidget *myplane)
    {
        myplane->setWindowTitle(QApplication::translate("myplane", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class myplane: public Ui_myplane {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYPLANE_H
