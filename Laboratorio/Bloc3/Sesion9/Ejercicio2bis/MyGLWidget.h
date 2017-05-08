#define GLM_FORCE_RADIANS
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QtMultimediaWidgets>
#include <QLabel>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "model.h"


class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
  Q_OBJECT

  public:
    MyGLWidget (QWidget *parent=0);
    ~MyGLWidget ();

  public slots:
    void ZoomPerspectiva(int v);

    void ZoomOrtogonal(int v);

    void Perspective(bool b);

    void Ortogonal(bool b);

    void CarregaModel(QString str);

    void updateTheta(int value);

    void updatePsi(int value);

    void setEscalat(double value);

    void setRed(int color);

    void setGreen(int color);

    void setBlue(int color);

    void setSong(QString song);
    /*
    void updateHeight();

    void updateWidth();*/

  signals:
    //Radio Buttons
    void updatePers();
    void updateOrt();

    //Dials
    void updatepsi(int val);
    void updatetheta(int val);

    void updateEscalat(double val);

    //Sliders
    void updateslfov(int nfv);
    void updateslort(int nrt);

  protected:
    // initializeGL - Aqui incluim les inicialitzacions del contexte grafic.
    virtual void initializeGL ( );
    // paintGL - Mètode cridat cada cop que cal refrescar la finestra.
    // Tot el que es dibuixa es dibuixa aqui.
    virtual void paintGL ( );
    // resizeGL - És cridat quan canvia la mida del widget
    virtual void resizeGL (int width, int height);
    // keyPressEvent - Es cridat quan es prem una tecla
    virtual void keyPressEvent (QKeyEvent *event);

    virtual void mouseMoveEvent(QMouseEvent *e);

    virtual void mousePressEvent(QMouseEvent *e);

    virtual void wheelEvent (QWheelEvent * e);

  private:
    void createBuffers ();
    void carregaShaders ();

    void modelTransformPat1 ();
    void modelTransformPat2 ();

    void modelTransformHomer1 ();
    void modelTransformHomer2 ();

    void modelTransformLego1 ();
    void modelTransformLego2 ();

    void modelTransformLegoAssegut1();
    void modelTransformLegoAssegut2();

    void modelTransformShaun1();
    void modelTransformShaun2();

    void modelTransformVaca1 ();
    void modelTransformVaca2 ();

    void modelTransformDelfin1 ();
    void modelTransformDelfin2 ();

    void modelTransformF161 ();
    void modelTransformF162 ();

    void modelTransformPorsche1 ();
    void modelTransformPorsche2 ();

    void modelTransformCotxe1 ();
    void modelTransformCotxe2 ();

    void modelTransformFloor ();
    void modelTransformWall ();

    void projectTransformOrtogonal ();
    void projectTransformPerspectiva();

    void viewTransform ();

    void ini_camera ();
    void ini_camera_3a_persona();

    void carregaModels();
    void carregaFloor();

    void pinta_model();
    void pinta_floor();

    void evitaDeformacions (int w, int h);

    void gira();

    void calculaCapsaModels();

    void resizeOrto();

    void sunshine();
    void restart();

    // attribute locations
    GLuint vertexLoc, normalLoc, matambLoc, matdiffLoc, matspecLoc, matshinLoc;;

    // uniform locations
    GLuint transLoc;
    GLuint projLoc;
    GLuint viewLoc;
    GLuint colorFocusLoc;
    GLuint posFocusLoc;

    // VAO i VBO names
    GLuint Vs[11][7];

    Model models[11];

    float scales[11];
    float radiModels[11];
    glm::vec3 EsferaModels[11][4];

    int index;

    glm::vec3 posFocus;
    glm::vec3 colFocus;
    int factor;
    bool sun;
    bool cambia;

    // Program
    QOpenGLShaderProgram *program;


    // Internal vars

    bool song;
    bool gir;
    bool ortogonal;

    float red, green, blue;

    QString model;
    QString filename;
    QMediaPlayer player;
    float one_degree;

    //Variable de transformació
    QPoint position;
    float scale;
    float degreesX;

    //Paràmetre inicials
    float FOVini;
    float raini;

    int fvant;

    //Variables Project Matrix
    float FOV;
    float ra;
    float znear;
    float zfar;

    float left;
    float right;
    float bottom;
    float top;

    float laux;
    float raux;
    float baux;
    float taux;

    //Variables View Matrix
    float theta;
    float fi; //no cal
    float psi;

    glm::vec3 pos;
    glm::vec3 OBS;
    glm::vec3 VRP;
    glm::vec3 UP;


    //Eixos
    glm::vec3 x;
    glm::vec3 y;
    glm::vec3 z;

    //Variables càmara 3a persona

    float radiModel;
    float d;

    //vector normalitzat
    glm::vec3 v;

    glm::vec3 origen;

};
