#include "estructuras.h"
#include <QtCore>

class hilo_Hate: public QThread{
public:
    bool running;

    hilo_Hate();

    ColaHate * colaHate;

    void __init__(struct ColaHate*);
    void run();
    void stop();
    void continuar();
};
