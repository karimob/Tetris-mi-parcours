
#include "precompiledHeader.h"
#include "mainWindowTetris.h"
#include "ui_mainWindowTetris.h"
#include "tetrixwindow.h"


MainWindowTetris::MainWindowTetris(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowTetris)
{
    ui->setupUi(this);
	TetrixWindow *window = new TetrixWindow;
	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(window);
	setCentralWidget(new QWidget);
	centralWidget()->setLayout(layout);
    setFixedSize(500, 670);
    this->setWindowTitle("THE BEST TETRIX GAME");
    this->setWindowIcon(QIcon(":/picture/TETRIX_ICON.jpg"));
    createMenuBar();
}


void MainWindowTetris::createMenuBar()
{
    QMenu *helpMenu = menuBar()->addMenu(tr("&AIDE"));
    QAction *aboutAct = helpMenu->addAction(tr("&Commandes"), this, &MainWindowTetris::commande);
    aboutAct = helpMenu->addAction(tr("&A propos"), this, &MainWindowTetris::about);
    aboutAct->setStatusTip(tr("Montre le a propos"));
}


void MainWindowTetris::commande()
{
   QMessageBox::about(this, tr("commande Game"),
            tr("<br><b>flèche → :</b>  Permet de bouger à GAUCHE \n</br>"
               "<br><b>flèche ← :</b>  Permet de bouger à DROIT \n</br>"
               "<br><b>flèche ↓ :</b>  Permet de faire une rotation DROITE \n</br>"
               "<br><b>flèche ↑ :</b>  Permet de faire une rotation GAUCHE \n</br>"
               "<br><b>touche espace :</b>  Descendre rapidement \n</br>"
               "<br><b>touche D :</b>  Descendre d'une ligne</br>"));
}


void MainWindowTetris::about()
{
   QMessageBox::about(this, tr("A propos Application"),
            tr("Le but du jeu est d'empiler les pièces tombées du haut de la zone de jeu afin qu'elles remplissent des rangées entières au bas de la zone de jeu."
              " Lorsqu'une rangée est remplie, tous les blocs de cette rangée sont supprimés, le joueur gagne un certain nombre de points et les pièces ci-dessus sont déplacées vers le bas pour occuper cette rangée. Si plus d'une ligne est remplie, les blocs de chaque ligne sont supprimés et le joueur gagne des points supplémentaires."

               ));
}

//Destructeur
MainWindowTetris::~MainWindowTetris()
{
    delete ui;
}
