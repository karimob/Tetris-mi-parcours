#ifndef MAINWINDOWTETRIS_H
#define MAINWINDOWTETRIS_H

#include "precompiledHeader.h"

namespace Ui {
class MainWindowTetris;
}

class MainWindowTetris : public QMainWindow
{
    Q_OBJECT

public:
    //explicit sert uniquement à éviter la conversion implicite d'un autre type vers la classe en utilisant un constructeur prenant potentiellement un seul paramètre.
    explicit MainWindowTetris(QWidget *parent = nullptr);
    ~MainWindowTetris();

private:
    Ui::MainWindowTetris *ui;
    void createMenuBar();

private slots:
    void commande();
    void about();

};

#endif // MAINWINDOWTETRIS_H
