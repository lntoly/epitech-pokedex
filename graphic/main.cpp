#include <QtGui/QApplication>
#include <QtGui/QSplashScreen>
#include <QtGui/QBitmap>
#include "parser/pokedexmanager.h"
#include "mainwindow.h"
#include "master.h"

int                 main(int argc, char *argv[])
{
    QApplication    a(argc, argv);
    QSplashScreen   splash;
    splash.setPixmap(QPixmap(":/Images/ressources/splash.png"));
    splash.show();


    MainWindow      w;

    w.loadPokemons(w.getPokemons());
    w.show(); splash.finish(&w);
    return a.exec();
}
