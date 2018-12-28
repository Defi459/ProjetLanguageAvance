#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QApplication>
#include <QtWidgets>
#include <QPushButton>
#include <QProgressBar>

class MaFenetre : public QWidget {
    Q_OBJECT

    public:
        MaFenetre();
        MaFenetre(int longeur, int largeur);

    public slots:
        void reset_slider();

    private:
        QPushButton *m_bouton;
//        QLCDNumber *m_lcd;
        QSlider *m_slider;
        QProgressBar *m_progressBar;
};


#endif // MAFENETRE_H
