/********************************************************************************
** Form generated from reading UI file 'enemy_plane.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENEMY_PLANE_H
#define UI_ENEMY_PLANE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_enemy_plane
{
public:
    QGridLayout *gridLayout;
    QProgressBar *progressBar;

    void setupUi(QWidget *enemy_plane)
    {
        if (enemy_plane->objectName().isEmpty())
            enemy_plane->setObjectName(QStringLiteral("enemy_plane"));
        enemy_plane->resize(554, 415);
        enemy_plane->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(enemy_plane);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        progressBar = new QProgressBar(enemy_plane);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 0, 0, 1, 1);


        retranslateUi(enemy_plane);

        QMetaObject::connectSlotsByName(enemy_plane);
    } // setupUi

    void retranslateUi(QWidget *enemy_plane)
    {
        enemy_plane->setWindowTitle(QApplication::translate("enemy_plane", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class enemy_plane: public Ui_enemy_plane {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENEMY_PLANE_H
